/*
 * PtokaX - hub server for Direct Connect peer to peer network.

 * Copyright (C) 2002-2005  Ptaczek, Ptaczek at PtokaX dot org
 * Copyright (C) 2004-2010  Petr Kozelka, PPK at PtokaX dot org

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3
 * as published by the Free Software Foundation.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//---------------------------------------------------------------------------
#include "stdinc.h"
//---------------------------------------------------------------------------
#include "LuaInc.h"
//---------------------------------------------------------------------------
#include "LanguageManager.h"
#include "ServerManager.h"
#include "serviceLoop.h"
#include "SettingManager.h"
#include "utility.h"
//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#ifdef _MSC_VER
	#include "ExceptionHandling.h"
#endif
#include "LuaScript.h"
//---------------------------------------------------------------------------
#ifdef TIXML_USE_STL
	#undef TIXML_USE_STL
#endif
//---------------------------------------------------------------------------

#ifdef _DEBUG
//    #pragma link "lib/sqlited.lib"
//    #pragma message("Linking sqlited.lib")
	#pragma link "tinyxmld.lib"
	#pragma message("Linking tinyxmld.lib")
	#pragma link "zlibd.lib"
	#pragma message("Linking zlibd.lib")
#else
//    #pragma link "lib/sqlite.lib"
//    #pragma message("Linking sqlite.lib")
	#ifndef _MSC_VER
        #pragma link "tinyxml.lib"
	#else
        #ifndef _M_X64
            #pragma comment(lib, "tinyxml")
        #else
            #pragma comment(lib, "tinyxml-x64")
        #endif
    #endif
    #pragma message("Linking tinyxml.lib")

    #ifndef _MSC_VER
        #pragma link "zlib.lib"
    #else
        #ifndef _M_X64
            #pragma comment(lib, "zlib")
        #else
            #pragma comment(lib, "zlib-x64")
        #endif
    #endif
    #pragma message("Linking zlib.lib")
#endif
//---------------------------------------------------------------------------
	
static int InstallService(const char * sServiceName, const char * sPath) {
	SC_HANDLE schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	     
	if(schSCManager == NULL) {
	    printf("OpenSCManager failed (%d)!", GetLastError());
	    return EXIT_FAILURE;
	}
	
	char sBuf[MAX_PATH+1];
	::GetModuleFileName(NULL, sBuf, MAX_PATH);
	
	string sCmdLine = "\"" + string(sBuf) + "\" -s " + string(sServiceName);
	
	if(sPath != NULL) {
	    sCmdLine += " -c " + string(sPath);
	}
	
	SC_HANDLE schService = CreateService(schSCManager, sServiceName, sServiceName, 0, SERVICE_WIN32_OWN_PROCESS,
	    SERVICE_AUTO_START, SERVICE_ERROR_NORMAL, sCmdLine.c_str(),
	    NULL, NULL, NULL, NULL, NULL);
	
	if(schService == NULL) {
	    printf("CreateService failed (%d)!", GetLastError());
	    CloseServiceHandle(schSCManager);
	    return EXIT_FAILURE;
	} else {
	    printf("PtokaX service '%s' installed successfully.", sServiceName);
	}

	CloseServiceHandle(schService);
	CloseServiceHandle(schSCManager);
	
	return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------
	
static int UninstallService(const char * sServiceName) {
	SC_HANDLE schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	     
	if(schSCManager == NULL) {
	    printf("OpenSCManager failed (%d)!", GetLastError());
	    return EXIT_FAILURE;
	}
	
	SC_HANDLE schService = OpenService(schSCManager, sServiceName, SERVICE_QUERY_STATUS | SERVICE_STOP | DELETE);
	     
	if(schService == NULL) {
	    printf("OpenService failed (%d)!", GetLastError());
	    CloseServiceHandle(schSCManager);
	    return EXIT_FAILURE;
	}
	
	SERVICE_STATUS_PROCESS ssp;
	DWORD dwBytesNeeded;
	
	if(QueryServiceStatusEx(schService, SC_STATUS_PROCESS_INFO, (LPBYTE)&ssp, sizeof(SERVICE_STATUS_PROCESS), &dwBytesNeeded) != 0) {
	    if(ssp.dwCurrentState != SERVICE_STOPPED && ssp.dwCurrentState != SERVICE_STOP_PENDING) {
	        ControlService(schService, SERVICE_CONTROL_STOP, (LPSERVICE_STATUS)&ssp);
	    }
	}
	
	if(DeleteService(schService) == false) {
	    printf("DeleteService failed (%d)!", GetLastError());
	    CloseServiceHandle(schService);
	    CloseServiceHandle(schSCManager);
	    return EXIT_FAILURE;
	} else {
	    printf("PtokaX service '%s' deleted successfully.", sServiceName);
	    CloseServiceHandle(schService);
	    CloseServiceHandle(schSCManager);
	    return EXIT_SUCCESS;
	}
}
//---------------------------------------------------------------------------
static SERVICE_STATUS_HANDLE ssh;
static SERVICE_STATUS ss;
//---------------------------------------------------------------------------
	
static void WINAPI CtrlHandler(DWORD dwCtrl) {
	switch(dwCtrl) {
	    case SERVICE_CONTROL_SHUTDOWN:
	    case SERVICE_CONTROL_STOP:
	        ss.dwCurrentState = SERVICE_STOP_PENDING;
	        bIsClose = true;
	        ServerStop();
	    case SERVICE_CONTROL_INTERROGATE:
	        // Fall through to send current status.
	        break;
	    default:
	        break;
	}
	
	if(SetServiceStatus(ssh, &ss) == false) {
		AppendLog("CtrlHandler::SetServiceStatus failed ("+string((uint32_t)GetLastError())+")!");
	}
}
//---------------------------------------------------------------------------
	
static void WINAPI StartService(DWORD /*argc*/, char* argv[]) {
	ssh = RegisterServiceCtrlHandler(argv[0], CtrlHandler);
	
	if(ssh == NULL) {
		AppendLog("RegisterServiceCtrlHandler failed ("+string((uint32_t)GetLastError())+")!");
	    return;
	}
	
	ss.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	ss.dwCurrentState = SERVICE_START_PENDING;
	ss.dwControlsAccepted = SERVICE_ACCEPT_SHUTDOWN | SERVICE_ACCEPT_STOP;
	ss.dwWin32ExitCode = NO_ERROR;
	ss.dwCheckPoint = 0;
	ss.dwWaitHint = 10 * 1000;
	
	if(SetServiceStatus(ssh, &ss) == false) {
		AppendLog("StartService::SetServiceStatus failed ("+string((uint32_t)GetLastError())+")!");
		return;
	}
	
	ServerInitialize();
	
	if(ServerStart() == false) {
	    AppendLog("Server start failed!");
		ss.dwCurrentState = SERVICE_STOPPED;
		SetServiceStatus(ssh, &ss);
		return;
	}
	
	ss.dwCurrentState = SERVICE_RUNNING;
	
	if(SetServiceStatus(ssh, &ss) == false) {
		AppendLog("StartService::SetServiceStatus1 failed ("+string((uint32_t)GetLastError())+")!");
		return;
	}

	MSG msg;
	BOOL bRet;
	        
	while((bRet = GetMessage(&msg, NULL, 0, 0)) != 0) {
	    if(bRet == -1) {
	        // handle the error and possibly exit
	    } else {
	        if(msg.message == WM_USER+1) {
	            break;
	        } else if(msg.message == WM_TIMER) {
                if(msg.wParam == sectimer) {
                    ServerOnSecTimer();
                } else if(msg.wParam == srvLoop->timer) {
                    srvLoop->Looper();
                } else if(msg.wParam == regtimer) {
                    ServerOnRegTimer();
                } else {
                    //Must be script timer
                    ScriptOnTimer(msg.wParam);
                }
            }

	    	TranslateMessage(&msg);
	        DispatchMessage(&msg);
	    }
	}

#ifdef _MSC_VER
    ExceptionHandlingUnitialize();
#endif

	ss.dwCurrentState = SERVICE_STOPPED;
	SetServiceStatus(ssh, &ss);
}
//---------------------------------------------------------------------------

int WINAPI main(int argc, char* argv[]) {
	sTitle = "PtokaX DC Hub " + string(PtokaXVersionString);
#ifdef _DEBUG
	sTitle += " [debug]";
#endif

#ifdef _DEBUG
//    AllocConsole();
//    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    Cout("PtokaX Debug console\n");
#endif
	
	char sBuf[MAX_PATH+1];
	::GetModuleFileName(NULL, sBuf, MAX_PATH);
	char * sPath = strrchr(sBuf, '\\');
	if(sPath != NULL) {
		PATH = string(sBuf, sPath-sBuf);
	} else {
		PATH = sBuf;
	}

	char * sServiceName = NULL;
	
	bool bInstallService = false;
	
	for(int i = 0; i < argc; i++) {
	    if(stricmp(argv[i], "-s") == NULL || stricmp(argv[i], "/service") == NULL) {
	    	if(++i == argc) {
	            AppendLog("Missing service name!");
	            return EXIT_FAILURE;
	    	}
	    	sServiceName = argv[i];
	    	bService = true;
	    } else if(stricmp(argv[i], "-c") == 0) {
	        if(++i == argc) {
	            printf("Missing config directory!");
	            return EXIT_FAILURE;
	        }
	
	        size_t iLen = strlen(argv[i]);
	        if(iLen >= 1 && argv[i][0] != '\\' && argv[i][0] != '/') {
	            if(iLen < 4 || (argv[i][1] != ':' || (argv[i][2] != '\\' && argv[i][2] != '/'))) {
	                printf("Config directory must be absolute path!");
	                return EXIT_FAILURE;
	            }
	    	}
	
	    	if(argv[i][iLen - 1] == '/' || argv[i][iLen - 1] == '\\') {
	            PATH = string(argv[i], iLen - 1);
	    	} else {
	            PATH = string(argv[i], iLen);
	        }
	    
	        if(DirExist(PATH.c_str()) == false) {
	            if(CreateDirectory(PATH.c_str(), NULL) == 0) {
	                printf("Config directory not exist and can't be created!");
	                return EXIT_FAILURE;
	            }
	        }
	    } else if(stricmp(argv[i], "-i") == NULL || stricmp(argv[i], "/install") == NULL) {
	    	if(++i == argc) {
	            printf("Please specify service name!");
	    		return EXIT_FAILURE;
	    	}
	    	sServiceName = argv[i];
	    	bInstallService = true;
	    } else if(stricmp(argv[i], "-u") == NULL || stricmp(argv[i], "/uninstall") == NULL) {
	    	if(++i == argc) {
	            printf("Please specify service name!");
	    		return EXIT_FAILURE;
	    	}
	    	sServiceName = argv[i];
	    	return UninstallService(sServiceName);
	    } else if(stricmp(argv[i], "-v") == NULL || stricmp(argv[i], "/version") == NULL) {
	    	printf((sTitle+" built on "+__DATE__+" "+__TIME__).c_str());
	    	return EXIT_SUCCESS;
	    } else if(stricmp(argv[i], "-h") == NULL || stricmp(argv[i], "/help") == NULL) {
	    	printf("PtokaX [-c <configdir>] [-i <servicename>] [-u <servicename>] [-v]");
	    	return EXIT_SUCCESS;
	    } else if(stricmp(argv[i], "/nokeycheck") == NULL) {
	        bCmdNoKeyCheck = true;
	    }
	}

	if(bInstallService == true) {
	    if(sPath == NULL && strcmp(PATH.c_str(), sBuf) == 0) {
	        return InstallService(sServiceName, NULL);
		} else {
			return InstallService(sServiceName, PATH.c_str());
		}
	}

#ifdef _MSC_VER
    ExceptionHandlingInitialize(PATH, sBuf);
#endif

	if(bService == false) {
	    ServerInitialize();
	
	    if(ServerStart() == false) {
	        printf("Server start failed!");
#ifdef _MSC_VER
            ExceptionHandlingUnitialize();
#endif
	        return EXIT_FAILURE;
	    } else {
	        printf((sTitle+" running...\n").c_str());
	    }

	    MSG msg;
	    BOOL bRet;

	    while((bRet = GetMessage(&msg, NULL, 0, 0)) != 0) {
	        if(bRet == -1) {
	            // handle the error and possibly exit
	        } else {
	            if(msg.message == WM_USER+1) {
	                break;
	            } else if(msg.message == WM_TIMER) {
                    if(msg.wParam == srvLoop->timer) {
                        srvLoop->Looper();
                    } else if(msg.wParam == regtimer) {
                        ServerOnRegTimer();
                    } else {
                        //Must be script timer
                        ScriptOnTimer(msg.wParam);
                    }
                }
	
	    		TranslateMessage(&msg);
	            DispatchMessage(&msg);
	        }
	    }

#ifdef _MSC_VER
        ExceptionHandlingUnitialize();
#endif
	} else {
	    SERVICE_TABLE_ENTRY DispatchTable[] = {
	        { sServiceName, StartService },
	        { NULL, NULL }
	    };
	       
	    if(StartServiceCtrlDispatcher(DispatchTable) == false) {
			AppendLog("StartServiceCtrlDispatcher failed ("+string((uint32_t)GetLastError())+")!");
#ifdef _MSC_VER
            ExceptionHandlingUnitialize();
#endif
	        return EXIT_FAILURE;
	    }
	}

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------
