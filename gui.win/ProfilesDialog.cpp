/*
 * PtokaX - hub server for Direct Connect peer to peer network.

 * Copyright (C) 2002-2005  Ptaczek, Ptaczek at PtokaX dot org
 * Copyright (C) 2004-2011  Petr Kozelka, PPK at PtokaX dot org

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
#include "../core/stdinc.h"
//---------------------------------------------------------------------------
#include "ProfilesDialog.h"
//---------------------------------------------------------------------------
#include "../core/LanguageManager.h"
#include "../core/ProfileManager.h"
#include "../core/utility.h"
//---------------------------------------------------------------------------
#ifdef _WIN32
	#pragma hdrstop
#endif
//---------------------------------------------------------------------------
#include "GuiUtil.h"
#include "LineDialog.h"
//---------------------------------------------------------------------------
ProfilesDialog * pProfilesDialog = NULL;
//---------------------------------------------------------------------------
#define IDC_RENAME_PROFILE      1000
#define IDC_REMOVE_PROFILE      1001
//---------------------------------------------------------------------------
static ATOM atomProfilesDialog = 0;
//---------------------------------------------------------------------------

ProfilesDialog::ProfilesDialog() {
    pProfilesDialog = this;

    m_hWnd = NULL;

    memset(&hWndWindowItems, 0, (sizeof(hWndWindowItems) / sizeof(hWndWindowItems[0])) * sizeof(HWND));

    bIgnoreItemChanged = false;
}
//---------------------------------------------------------------------------

ProfilesDialog::~ProfilesDialog() {
    pProfilesDialog = NULL;
}
//---------------------------------------------------------------------------

LRESULT CALLBACK ProfilesDialog::StaticProfilesDialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    ProfilesDialog * pProfilesDialog = (ProfilesDialog *)::GetWindowLongPtr(hWnd, GWLP_USERDATA);

    if(pProfilesDialog == NULL) {
        return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

	return pProfilesDialog->ProfilesDialogProc(uMsg, wParam, lParam);
}
//------------------------------------------------------------------------------

void OnNewProfileOk(char * sLine, const int &/*iLen*/) {
    int32_t iRet = ProfileMan->AddProfile(sLine);

    if(iRet == -1) {
        ::MessageBox(pProfilesDialog->m_hWnd, LanguageManager->sTexts[LAN_PROFILE_NAME_EXIST], sTitle.c_str(), MB_OK);
    } else if(iRet == -2) {
        ::MessageBox(pProfilesDialog->m_hWnd, LanguageManager->sTexts[LAN_CHARS_NOT_ALLOWED_IN_PROFILE], sTitle.c_str(), MB_OK);
    }
}
//---------------------------------------------------------------------------

LRESULT ProfilesDialog::ProfilesDialogProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_WINDOWPOSCHANGED: {
            RECT rcParent;
            ::GetClientRect(m_hWnd, &rcParent);

            int iProfilesWidth = (rcParent.right-rcParent.left)/3;

            int iPermissionsWidth = (rcParent.right-rcParent.left)-(iProfilesWidth+17);

            ::SetWindowPos(hWndWindowItems[BTN_CLEAR_ALL], NULL,
                iProfilesWidth+9+(iPermissionsWidth/2), rcParent.bottom-30, (rcParent.right-rcParent.left)-(iProfilesWidth+17+(iPermissionsWidth/2)), 23, SWP_NOZORDER);
            ::SetWindowPos(hWndWindowItems[BTN_SET_ALL], NULL, iProfilesWidth+9, rcParent.bottom-30, (iPermissionsWidth/2)-1, 23, SWP_NOZORDER);
            ::SetWindowPos(hWndWindowItems[LV_PERMISSIONS], NULL, iProfilesWidth+10, rcParent.top+16, (rcParent.right-rcParent.left)-(iProfilesWidth+19), (rcParent.bottom-rcParent.top)-48,
                SWP_NOZORDER);
            ::SendMessage(hWndWindowItems[LV_PERMISSIONS], LVM_SETCOLUMNWIDTH, 0, iPermissionsWidth-25);
            ::SetWindowPos(hWndWindowItems[GB_PERMISSIONS], NULL, iProfilesWidth+4, rcParent.top+1, (rcParent.right-rcParent.left)-(iProfilesWidth+7), (rcParent.bottom-rcParent.top)-4,
                SWP_NOZORDER);
            ::SetWindowPos(hWndWindowItems[BTN_MOVE_DOWN], NULL, (iProfilesWidth/2)+2, rcParent.bottom-25, iProfilesWidth-(iProfilesWidth/2), 23, SWP_NOZORDER);
            ::SetWindowPos(hWndWindowItems[BTN_MOVE_UP], NULL, 2, rcParent.bottom-25, (iProfilesWidth/2)-1, 23, SWP_NOZORDER);
            ::SetWindowPos(hWndWindowItems[LV_PROFILES], NULL, 0, 0, iProfilesWidth-2, (rcParent.bottom-rcParent.top)-54, SWP_NOMOVE | SWP_NOZORDER);
            ::SendMessage(hWndWindowItems[LV_PROFILES], LVM_SETCOLUMNWIDTH, 0, iProfilesWidth-6);
            ::SetWindowPos(hWndWindowItems[BTN_ADD_PROFILE], NULL, 0, 0, iProfilesWidth, 23, SWP_NOMOVE | SWP_NOZORDER);

            return 0;
        }
        case WM_COMMAND:
            switch(LOWORD(wParam)) {
                case BTN_ADD_PROFILE: {
                    LineDialog * NewProfileDlg = new LineDialog(&OnNewProfileOk);
                    NewProfileDlg->DoModal(m_hWnd, LanguageManager->sTexts[LAN_NEW_PROFILE_NAME], "");

                    return 0;
                }
                case IDC_RENAME_PROFILE: {
                    int iSel = (int)::SendMessage(hWndWindowItems[LV_PROFILES], LVM_GETNEXTITEM, (WPARAM)-1, LVNI_SELECTED);

                    if(iSel == -1) {
                        return 0;
                    }

                    RenameProfile(iSel);

                    return 0;
                }
                case IDC_REMOVE_PROFILE: {
                    int iSel = (int)::SendMessage(hWndWindowItems[LV_PROFILES], LVM_GETNEXTITEM, (WPARAM)-1, LVNI_SELECTED);

                    if(iSel == -1 || ::MessageBox(m_hWnd, (string(LanguageManager->sTexts[LAN_ARE_YOU_SURE], (size_t)LanguageManager->ui16TextsLens[LAN_ARE_YOU_SURE])+" ?").c_str(),
                        sTitle.c_str(), MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) == IDNO) {
                        return 0;
                    }

                    if(ProfileMan->RemoveProfile((uint16_t)iSel) == false) {
                        ::MessageBox(m_hWnd, LanguageManager->sTexts[LAN_PROFILE_DEL_FAIL], sTitle.c_str(), MB_OK);
                    }

                    return 0;
                }
                case BTN_SET_ALL:
                    ChangePermissionChecks(true);
                    return 0;
                case BTN_CLEAR_ALL:
                    ChangePermissionChecks(false);
                    return 0;
                case BTN_MOVE_UP: {
                    int iSel = (int)::SendMessage(hWndWindowItems[LV_PROFILES], LVM_GETNEXTITEM, (WPARAM)-1, LVNI_SELECTED);

                    if(iSel == -1) {
                        return 0;
                    }

                    ProfileMan->MoveProfileUp((uint16_t)iSel);

                    return 0;
                }
                case BTN_MOVE_DOWN: {
                    int iSel = (int)::SendMessage(hWndWindowItems[LV_PROFILES], LVM_GETNEXTITEM, (WPARAM)-1, LVNI_SELECTED);

                    if(iSel == -1) {
                        return 0;
                    }

                    ProfileMan->MoveProfileDown((uint16_t)iSel);

                    return 0;
                }
            }

            break;
        case WM_CONTEXTMENU:
            OnContextMenu((HWND)wParam, lParam);
            break;
        case WM_NOTIFY:
            if(((LPNMHDR)lParam)->hwndFrom == hWndWindowItems[LV_PROFILES]) {
                if(((LPNMHDR)lParam)->code == LVN_ITEMCHANGED) {
                    OnProfileChanged((LPNMLISTVIEW)lParam);
                } else if(((LPNMHDR)lParam)->code == NM_DBLCLK) {
                    RenameProfile(((LPNMITEMACTIVATE)lParam)->iItem);
                }
            } else if(((LPNMHDR)lParam)->hwndFrom == hWndWindowItems[LV_PERMISSIONS]) {
                if(((LPNMHDR)lParam)->code == LVN_ITEMCHANGED) {
                    OnPermissionChanged((LPNMLISTVIEW)lParam);
                }
            }

            break;
        case WM_GETMINMAXINFO: {
            MINMAXINFO *mminfo = (MINMAXINFO*)lParam;
            mminfo->ptMinTrackSize.x = 443;
            mminfo->ptMinTrackSize.y = 454;

            return 0;
        }
        case WM_CLOSE:
            ::EnableWindow(::GetParent(m_hWnd), TRUE);
            break;
        case WM_NCDESTROY:
            delete this;
            return ::DefWindowProc(m_hWnd, uMsg, wParam, lParam);
    }

	return ::DefWindowProc(m_hWnd, uMsg, wParam, lParam);
}
//------------------------------------------------------------------------------

void ProfilesDialog::DoModal(HWND hWndParent) {
    if(atomProfilesDialog == 0) {
        WNDCLASSEX m_wc;
        memset(&m_wc, 0, sizeof(WNDCLASSEX));
        m_wc.cbSize = sizeof(WNDCLASSEX);
        m_wc.lpfnWndProc = ::DefWindowProc;
        m_wc.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
        m_wc.lpszClassName = "PtokaX_ProfilesDialog";
        m_wc.hInstance = g_hInstance;
        m_wc.hCursor = ::LoadCursor(m_wc.hInstance, IDC_ARROW);
        m_wc.style = CS_HREDRAW | CS_VREDRAW;

        atomProfilesDialog = ::RegisterClassEx(&m_wc);
    }

    RECT rcParent;
    ::GetWindowRect(hWndParent, &rcParent);

    int iX = (rcParent.left + (((rcParent.right-rcParent.left))/2))-221;
    int iY = (rcParent.top + ((rcParent.bottom-rcParent.top)/2))-227;

    m_hWnd = ::CreateWindowEx(WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE, MAKEINTATOM(atomProfilesDialog), LanguageManager->sTexts[LAN_PROFILES],
        WS_POPUP | WS_CAPTION | WS_MAXIMIZEBOX | WS_SYSMENU | WS_SIZEBOX | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, iX >= 5 ? iX : 5, iY >= 5 ? iY : 5, 443, 454,
        hWndParent, NULL, g_hInstance, NULL);

    if(m_hWnd == NULL) {
        return;
    }

    ::SetWindowLongPtr(m_hWnd, GWLP_USERDATA, (LONG_PTR)this);
    ::SetWindowLongPtr(m_hWnd, GWLP_WNDPROC, (LONG_PTR)StaticProfilesDialogProc);

    ::GetClientRect(m_hWnd, &rcParent);

    int iProfilesWidth = (rcParent.right-rcParent.left)/3;

    hWndWindowItems[BTN_ADD_PROFILE] = ::CreateWindowEx(0, WC_BUTTON, LanguageManager->sTexts[LAN_ADD_NEW_PROFILE], WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON,
        2, rcParent.top+2, iProfilesWidth, 23, m_hWnd, (HMENU)BTN_ADD_PROFILE, g_hInstance, NULL);

    hWndWindowItems[LV_PROFILES] = ::CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, "", WS_CHILD | WS_VISIBLE | LVS_NOCOLUMNHEADER | LVS_REPORT | LVS_SHOWSELALWAYS | LVS_SINGLESEL,
        3, 27, iProfilesWidth-2, (rcParent.bottom-rcParent.top)-54, m_hWnd, NULL, g_hInstance, NULL);
    ::SendMessage(hWndWindowItems[LV_PROFILES], LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_DOUBLEBUFFER | LVS_EX_FULLROWSELECT | LVS_EX_LABELTIP);

    hWndWindowItems[BTN_MOVE_UP] = ::CreateWindowEx(0, WC_BUTTON, LanguageManager->sTexts[LAN_MOVE_UP], WS_CHILD | WS_VISIBLE | WS_DISABLED | WS_TABSTOP | BS_PUSHBUTTON,
        2, rcParent.bottom-25, (iProfilesWidth/2)-1, 23, m_hWnd, (HMENU)BTN_MOVE_UP, g_hInstance, NULL);

    hWndWindowItems[BTN_MOVE_DOWN] = ::CreateWindowEx(0, WC_BUTTON, LanguageManager->sTexts[LAN_MOVE_DOWN], WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON,
        (iProfilesWidth/2)+2, rcParent.bottom-25, iProfilesWidth-(iProfilesWidth/2), 23, m_hWnd, (HMENU)BTN_MOVE_DOWN, g_hInstance, NULL);

    hWndWindowItems[GB_PERMISSIONS] = ::CreateWindowEx(WS_EX_TRANSPARENT, WC_BUTTON, LanguageManager->sTexts[LAN_PROFILE_PERMISSIONS],
        WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | BS_GROUPBOX, iProfilesWidth+4, 1, (rcParent.right-rcParent.left)-(iProfilesWidth+7), (rcParent.bottom-rcParent.top)-4,
        m_hWnd, NULL, g_hInstance, NULL);

    hWndWindowItems[LV_PERMISSIONS] = ::CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, "", WS_CHILD | WS_VISIBLE | LVS_NOCOLUMNHEADER | LVS_REPORT | LVS_SHOWSELALWAYS | LVS_SINGLESEL,
        iProfilesWidth+10, rcParent.top+16, (rcParent.right-rcParent.left)-(iProfilesWidth+19), (rcParent.bottom-rcParent.top)-48, m_hWnd, NULL, g_hInstance, NULL);
    ::SendMessage(hWndWindowItems[LV_PERMISSIONS], LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_DOUBLEBUFFER | LVS_EX_FULLROWSELECT | LVS_EX_LABELTIP | LVS_EX_CHECKBOXES);

    int iPermissionsWidth = (rcParent.right-rcParent.left)-(iProfilesWidth+17);

    hWndWindowItems[BTN_SET_ALL] = ::CreateWindowEx(0, WC_BUTTON, LanguageManager->sTexts[LAN_SET_ALL], WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON,
        iProfilesWidth+9, rcParent.bottom-30, (iPermissionsWidth/2)-1, 23, m_hWnd, (HMENU)BTN_SET_ALL, g_hInstance, NULL);

    hWndWindowItems[BTN_CLEAR_ALL] = ::CreateWindowEx(0, WC_BUTTON, LanguageManager->sTexts[LAN_CLEAR_ALL], WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON,
        iProfilesWidth+9+(iPermissionsWidth/2), rcParent.bottom-30, (rcParent.right-rcParent.left)-(iProfilesWidth+17+(iPermissionsWidth/2)), 23,
        m_hWnd, (HMENU)BTN_CLEAR_ALL, g_hInstance, NULL);

    for(uint8_t ui8i = 0; ui8i < (sizeof(hWndWindowItems) / sizeof(hWndWindowItems[0])); ui8i++) {
        if(hWndWindowItems[ui8i] == NULL) {
            return;
        }

        ::SendMessage(hWndWindowItems[ui8i], WM_SETFONT, (WPARAM)hfFont, MAKELPARAM(TRUE, 0));
    }

	RECT rcProfiles;
	::GetClientRect(hWndWindowItems[LV_PROFILES], &rcProfiles);

    LVCOLUMN lvColumn = { 0 };
    lvColumn.mask = LVCF_FMT | LVCF_WIDTH;
    lvColumn.fmt = LVCFMT_LEFT;
    lvColumn.cx = rcProfiles.right - rcProfiles.left;

    ::SendMessage(hWndWindowItems[LV_PROFILES], LVM_INSERTCOLUMN, 0, (LPARAM)&lvColumn);

	RECT rcPermissions;
	::GetClientRect(hWndWindowItems[LV_PERMISSIONS], &rcPermissions);

    lvColumn.cx = rcPermissions.right - rcPermissions.left;

    ::SendMessage(hWndWindowItems[LV_PERMISSIONS], LVM_INSERTCOLUMN, 0, (LPARAM)&lvColumn);

    const int iPermissionsStrings[] = {
        LAN_ENT_FULL_HUB, LAN_ALLOW_LOGIN_BANNED_IP, LAN_CLOSE, LAN_DROP, LAN_KICK, LAN_GET_USER_INFO,
        LAN_REDIR, LAN_TEMPOR_BAN, LAN_TEMPOR_UNBAN, LAN_PERMANENT_BAN, LAN_UNBAN_PERM_UNBAN, LAN_CLEAR_TEMP_BANS,
        LAN_CLEAR_PERM_BANS, LAN_GET_BANS, LAN_RANGE_PERM_BAN, LAN_RANGE_UNBAN_RANGE_PERM_UNBAN, LAN_TEMP_RANGE_BAN,
        LAN_TEMP_RANGE_UNBAN, LAN_GET_RANGE_BANS, LAN_CLEAR_PERM_RANGE_BANS, LAN_CLEAR_TEMP_RANGE_BANS, LAN_GAG_UNGAG,
        LAN_TEMP_OP, LAN_START_STOP_RESTART_SCRIPTS, LAN_RESTART_HUB, LAN_RLD_TXT_FILES, LAN_NO_SHARE_LIMIT, LAN_NO_SLOT_CHECK,
        LAN_NO_RATIO_CHECK, LAN_NO_MAX_HUBS_CHECK, LAN_NO_CHAT_LIMITS, LAN_NO_TAG_CHECK, LAN_NO_MAIN_DFLD,
        LAN_NO_PM_DFLD, LAN_NO_SEARCH_LIMITS, LAN_NO_SEARCH_DFLD, LAN_NO_MYINFO_DFLD, LAN_NO_GETNICKLIST_DFLD,
        LAN_NO_CTM_DFLD, LAN_NO_RCTM_DFLD, LAN_NO_SR_DFLD, LAN_NO_RECV_DFLD, LAN_TOPIC,
        LAN_MASS_MSG, LAN_ADD_REG_USER, LAN_DEL_REG_USER, LAN_ALLOW_OPCHAT, LAN_SEND_FULL_MYINFOS,
        LAN_SEND_USER_IPS, LAN_DONT_CHECK_IP, LAN_HAVE_KEY_IS_OP, LAN_NO_CHAT_INTERVAL, LAN_NO_PM_INTERVAL,
        LAN_NO_SEARCH_INTERVAL, LAN_NO_MAX_USR_SAME_IP, LAN_NO_RECONN_TIME
    };

    const int iPermissionsIds[] = {
        ProfileManager::ENTERFULLHUB, ProfileManager::ENTERIFIPBAN, ProfileManager::CLOSE, ProfileManager::DROP, ProfileManager::KICK, ProfileManager::GETINFO,
        ProfileManager::REDIRECT, ProfileManager::TEMP_BAN, ProfileManager::TEMP_UNBAN, ProfileManager::BAN, ProfileManager::UNBAN, ProfileManager::CLRTEMPBAN,
        ProfileManager::CLRPERMBAN, ProfileManager::GETBANLIST, ProfileManager::RANGE_BAN, ProfileManager::RANGE_UNBAN, ProfileManager::RANGE_TBAN,
        ProfileManager::RANGE_TUNBAN, ProfileManager::GET_RANGE_BANS, ProfileManager::CLR_RANGE_BANS, ProfileManager::CLR_RANGE_TBANS, ProfileManager::GAG,
        ProfileManager::TEMPOP, ProfileManager::RSTSCRIPTS, ProfileManager::RSTHUB, ProfileManager::REFRESHTXT, ProfileManager::NOSHARELIMIT, ProfileManager::NOSLOTCHECK,
        ProfileManager::NOSLOTHUBRATIO, ProfileManager::NOMAXHUBCHECK, ProfileManager::NOCHATLIMITS, ProfileManager::NOTAGCHECK, ProfileManager::NODEFLOODMAINCHAT,
        ProfileManager::NODEFLOODPM, ProfileManager::NOSEARCHLIMITS, ProfileManager::NODEFLOODSEARCH, ProfileManager::NODEFLOODMYINFO, ProfileManager::NODEFLOODGETNICKLIST,
        ProfileManager::NODEFLOODCTM, ProfileManager::NODEFLOODRCTM, ProfileManager::NODEFLOODSR, ProfileManager::NODEFLOODRECV, ProfileManager::TOPIC,
        ProfileManager::MASSMSG, ProfileManager::ADDREGUSER, ProfileManager::DELREGUSER, ProfileManager::ALLOWEDOPCHAT, ProfileManager::SENDFULLMYINFOS,
        ProfileManager::SENDALLUSERIP, ProfileManager::NOIPCHECK, ProfileManager::HASKEYICON, ProfileManager::NOCHATINTERVAL, ProfileManager::NOPMINTERVAL,
        ProfileManager::NOSEARCHINTERVAL, ProfileManager::NOUSRSAMEIP, ProfileManager::NORECONNTIME
    };

    for(uint16_t i = 0; i < (sizeof(iPermissionsIds) / sizeof(iPermissionsIds[0])); i++) {
        LVITEM lvItem = { 0 };
        lvItem.mask = LVIF_PARAM | LVIF_TEXT;
        lvItem.iItem = i;
        lvItem.lParam = (LPARAM)iPermissionsIds[i];
        lvItem.pszText = LanguageManager->sTexts[iPermissionsStrings[i]];

        ::SendMessage(hWndWindowItems[LV_PERMISSIONS], LVM_INSERTITEM, 0, (LPARAM)&lvItem);
    }

    AddAllProfiles();

    ::EnableWindow(hWndParent, FALSE);

    ::ShowWindow(m_hWnd, SW_SHOW);
}
//------------------------------------------------------------------------------

void ProfilesDialog::AddAllProfiles() {
    ::SendMessage(hWndWindowItems[LV_PROFILES], WM_SETREDRAW, (WPARAM)FALSE, 0);

    for(uint16_t i = 0; i < ProfileMan->iProfileCount; i++) {
        LVITEM lvItem = { 0 };
        lvItem.mask = LVIF_PARAM | LVIF_TEXT;
        lvItem.iItem = i;
        lvItem.lParam = (LPARAM)ProfileMan->ProfilesTable[i];
        lvItem.pszText = ProfileMan->ProfilesTable[i]->sName;

        ::SendMessage(hWndWindowItems[LV_PROFILES], LVM_INSERTITEM, 0, (LPARAM)&lvItem);
    }

    LVITEM lvItem = { 0 };
    lvItem.mask = LVIF_STATE;
    lvItem.state = LVIS_SELECTED;
    lvItem.stateMask = LVIS_SELECTED;

    ::SendMessage(hWndWindowItems[LV_PROFILES], LVM_SETITEMSTATE, 0, (LPARAM)&lvItem);

    ::SendMessage(hWndWindowItems[LV_PROFILES], WM_SETREDRAW, (WPARAM)TRUE, 0);
}
//------------------------------------------------------------------------------

void ProfilesDialog::OnContextMenu(HWND hWindow, LPARAM lParam) {
    if(hWindow != hWndWindowItems[LV_PROFILES]) {
        return;
    }

    int iSel = (int)::SendMessage(hWndWindowItems[LV_PROFILES], LVM_GETNEXTITEM, (WPARAM)-1, LVNI_SELECTED);

    if(iSel == -1) {
        return;
    }

    HMENU hMenu = ::CreatePopupMenu();

    ::AppendMenu(hMenu, MF_STRING, IDC_RENAME_PROFILE, LanguageManager->sTexts[LAN_RENAME]);
    ::AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);
    ::AppendMenu(hMenu, MF_STRING, IDC_REMOVE_PROFILE, LanguageManager->sTexts[LAN_REMOVE]);

    int iX = GET_X_LPARAM(lParam);
    int iY = GET_Y_LPARAM(lParam);

    // -1, -1 is menu created by key. We need few tricks to show menu on correct position ;o)
    if(iX == -1 && iY == -1) {
        POINT pt = { 0 };
        if((BOOL)::SendMessage(hWndWindowItems[LV_PROFILES], LVM_ISITEMVISIBLE, (WPARAM)iSel, 0) == FALSE) {
            RECT rcList;
            ::GetClientRect(hWndWindowItems[LV_PROFILES], &rcList);

            ::SendMessage(hWndWindowItems[LV_PROFILES], LVM_GETITEMPOSITION, (WPARAM)iSel, (LPARAM)&pt);

            pt.y = (pt.y < rcList.top) ? rcList.top : rcList.bottom;
        } else {
            RECT rcItem;
            rcItem.left = LVIR_LABEL;
            ::SendMessage(hWndWindowItems[LV_PROFILES], LVM_GETITEMRECT, (WPARAM)iSel, (LPARAM)&rcItem);

            pt.x = rcItem.left;
            pt.y = rcItem.top + ((rcItem.bottom - rcItem.top) / 2);
        }

        ::ClientToScreen(hWndWindowItems[LV_PROFILES], &pt);

        iX = pt.x;
        iY = pt.y;
    }

    ::TrackPopupMenuEx(hMenu, TPM_LEFTALIGN | TPM_RIGHTBUTTON, iX, iY, m_hWnd, NULL);

    ::DestroyMenu(hMenu);
}
//------------------------------------------------------------------------------

void ProfilesDialog::OnProfileChanged(const LPNMLISTVIEW &pListView) {
    UpdateUpDown();

    if(pListView->iItem == -1 || (pListView->uOldState & LVIS_SELECTED) == LVIS_SELECTED || (pListView->uNewState & LVIS_SELECTED) != LVIS_SELECTED) {
        return;
    }

    bIgnoreItemChanged = true;

    uint16_t iItemCount = (uint16_t)::SendMessage(hWndWindowItems[LV_PERMISSIONS], LVM_GETITEMCOUNT, 0, 0);

    for(uint16_t i = 0; i < iItemCount; i++) {
        LVITEM lvItem = { 0 };
        lvItem.mask = LVIF_PARAM;
        lvItem.iItem = i;

        if((BOOL)::SendMessage(hWndWindowItems[LV_PERMISSIONS], LVM_GETITEM, 0, (LPARAM)&lvItem) == FALSE) {
            continue;
        }

        lvItem.mask = LVIF_STATE;
        lvItem.state = INDEXTOSTATEIMAGEMASK(ProfileMan->ProfilesTable[pListView->iItem]->bPermissions[(int)lvItem.lParam] == true ? 2 : 1);
        lvItem.stateMask = LVIS_STATEIMAGEMASK;

        ::SendMessage(hWndWindowItems[LV_PERMISSIONS], LVM_SETITEMSTATE, i, (LPARAM)&lvItem);
    }

    bIgnoreItemChanged = false;
}
//------------------------------------------------------------------------------

void ProfilesDialog::ChangePermissionChecks(const bool &bCheck) {
    int iSel = (int)::SendMessage(hWndWindowItems[LV_PROFILES], LVM_GETNEXTITEM, (WPARAM)-1, LVNI_SELECTED);

    if(iSel == -1) {
        return;
    }

    bIgnoreItemChanged = true;

    uint16_t iItemCount = (uint16_t)::SendMessage(hWndWindowItems[LV_PERMISSIONS], LVM_GETITEMCOUNT, 0, 0);

    for(uint16_t i = 0; i < iItemCount; i++) {
        ProfileMan->ProfilesTable[iSel]->bPermissions[i] = bCheck;

        LVITEM lvItem = { 0 };
        lvItem.mask = LVIF_STATE;
        lvItem.iItem = i;
        lvItem.state = INDEXTOSTATEIMAGEMASK(bCheck == true ? 2 : 1);
        lvItem.stateMask = LVIS_STATEIMAGEMASK;

        ::SendMessage(hWndWindowItems[LV_PERMISSIONS], LVM_SETITEMSTATE, i, (LPARAM)&lvItem);
    }

    bIgnoreItemChanged = false;
}
//------------------------------------------------------------------------------

void OnRenameProfileOk(char * sLine, const int &iLen) {
    int iSel = (int)::SendMessage(pProfilesDialog->hWndWindowItems[ProfilesDialog::LV_PROFILES], LVM_GETNEXTITEM, (WPARAM)-1, LVNI_SELECTED);

    if(iSel == -1) {
        return;
    }

    ProfileMan->ChangeProfileName((uint16_t)iSel, sLine, iLen);

    LVITEM lvItem = { 0 };
    lvItem.mask = LVIF_TEXT;
    lvItem.iItem = iSel;
    lvItem.pszText = sLine;

    ::SendMessage(pProfilesDialog->hWndWindowItems[ProfilesDialog::LV_PROFILES], LVM_SETITEMTEXT, iSel, (LPARAM)&lvItem);
}
//---------------------------------------------------------------------------

void ProfilesDialog::RenameProfile(const int &iProfile) {
    LineDialog * RenameProfileDlg = new LineDialog(&OnRenameProfileOk);
    RenameProfileDlg->DoModal(m_hWnd, LanguageManager->sTexts[LAN_NEW_PROFILE_NAME], ProfileMan->ProfilesTable[iProfile]->sName);
}
//------------------------------------------------------------------------------

void ProfilesDialog::RemoveProfile(const uint16_t &iProfile) {
    ::SendMessage(hWndWindowItems[LV_PROFILES], LVM_DELETEITEM, iProfile, 0);

    int iSel = (int)::SendMessage(hWndWindowItems[LV_PROFILES], LVM_GETNEXTITEM, (WPARAM)-1, LVNI_SELECTED);

    if(iSel == -1) {
        LVITEM lvItem = { 0 };
        lvItem.mask = LVIF_STATE;
        lvItem.state = LVIS_SELECTED;
        lvItem.stateMask = LVIS_SELECTED;

        ::SendMessage(hWndWindowItems[LV_PROFILES], LVM_SETITEMSTATE, 0, (LPARAM)&lvItem);
    }

    UpdateUpDown();
}
//------------------------------------------------------------------------------

void ProfilesDialog::UpdateUpDown() {
    int iSel = (int)::SendMessage(hWndWindowItems[LV_PROFILES], LVM_GETNEXTITEM, (WPARAM)-1, LVNI_SELECTED);

    if(iSel == -1) {
		::EnableWindow(hWndWindowItems[BTN_MOVE_UP], FALSE);
		::EnableWindow(hWndWindowItems[BTN_MOVE_DOWN], FALSE);
	} else if(iSel == 0) {
		::EnableWindow(hWndWindowItems[BTN_MOVE_UP], FALSE);
		if(iSel == (ProfileMan->iProfileCount-1)) {
			::EnableWindow(hWndWindowItems[BTN_MOVE_DOWN], FALSE);
		} else {
            ::EnableWindow(hWndWindowItems[BTN_MOVE_DOWN], TRUE);
		}
	} else if(iSel == (ProfileMan->iProfileCount-1)) {
		::EnableWindow(hWndWindowItems[BTN_MOVE_UP], TRUE);
		::EnableWindow(hWndWindowItems[BTN_MOVE_DOWN], FALSE);
	} else {
		::EnableWindow(hWndWindowItems[BTN_MOVE_UP], TRUE);
		::EnableWindow(hWndWindowItems[BTN_MOVE_DOWN], TRUE);
	}
}
//------------------------------------------------------------------------------

void ProfilesDialog::AddProfile() {
    LVITEM lvItem = { 0 };
    lvItem.mask = LVIF_PARAM | LVIF_TEXT;
    lvItem.iItem = ProfileMan->iProfileCount-1;
    lvItem.lParam = (LPARAM)ProfileMan->ProfilesTable[ProfileMan->iProfileCount-1];
    lvItem.pszText = ProfileMan->ProfilesTable[ProfileMan->iProfileCount-1]->sName;

    ::SendMessage(hWndWindowItems[LV_PROFILES], LVM_INSERTITEM, 0, (LPARAM)&lvItem);

    UpdateUpDown();
}
//------------------------------------------------------------------------------

void ProfilesDialog::MoveDown(const uint16_t &iProfile) {
    LVITEM lvItem1 = { 0 };
    lvItem1.mask = LVIF_PARAM | LVIF_STATE;
    lvItem1.iItem = iProfile;
    lvItem1.stateMask = LVIS_SELECTED;

    if((BOOL)::SendMessage(hWndWindowItems[LV_PROFILES], LVM_GETITEM, 0, (LPARAM)&lvItem1) == FALSE) {
        return;
    }

    LVITEM lvItem2 = { 0 };
    lvItem2.mask = LVIF_PARAM | LVIF_STATE;
    lvItem2.iItem = iProfile+1;
    lvItem2.stateMask = LVIS_SELECTED;

    if((BOOL)::SendMessage(hWndWindowItems[LV_PROFILES], LVM_GETITEM, 0, (LPARAM)&lvItem2) == FALSE) {
        return;
    }

    lvItem1.mask |= LVIF_TEXT;
    lvItem1.iItem++;
    lvItem1.pszText = ProfileMan->ProfilesTable[lvItem1.iItem]->sName;

    lvItem2.mask |= LVIF_TEXT;
    lvItem2.iItem--;
    lvItem2.pszText = ProfileMan->ProfilesTable[lvItem2.iItem]->sName;

    ::SendMessage(hWndWindowItems[LV_PROFILES], LVM_SETITEM, 0, (LPARAM)&lvItem1);
    ::SendMessage(hWndWindowItems[LV_PROFILES], LVM_SETITEM, 0, (LPARAM)&lvItem2);
}
//------------------------------------------------------------------------------

void ProfilesDialog::MoveUp(const uint16_t &iProfile) {
    LVITEM lvItem1 = { 0 };
    lvItem1.mask = LVIF_PARAM | LVIF_STATE;
    lvItem1.iItem = iProfile;
    lvItem1.stateMask = LVIS_SELECTED;

    if((BOOL)::SendMessage(hWndWindowItems[LV_PROFILES], LVM_GETITEM, 0, (LPARAM)&lvItem1) == FALSE) {
        return;
    }

    LVITEM lvItem2 = { 0 };
    lvItem2.mask = LVIF_PARAM | LVIF_STATE;
    lvItem2.iItem = iProfile-1;
    lvItem2.stateMask = LVIS_SELECTED;

    if((BOOL)::SendMessage(hWndWindowItems[LV_PROFILES], LVM_GETITEM, 0, (LPARAM)&lvItem2) == FALSE) {
        return;
    }

    lvItem1.mask |= LVIF_TEXT;
    lvItem1.iItem--;
    lvItem1.pszText = ProfileMan->ProfilesTable[lvItem1.iItem]->sName;

    lvItem2.mask |= LVIF_TEXT;
    lvItem2.iItem++;
    lvItem2.pszText = ProfileMan->ProfilesTable[lvItem2.iItem]->sName;

    ::SendMessage(hWndWindowItems[LV_PROFILES], LVM_SETITEM, 0, (LPARAM)&lvItem1);
    ::SendMessage(hWndWindowItems[LV_PROFILES], LVM_SETITEM, 0, (LPARAM)&lvItem2);
}
//------------------------------------------------------------------------------

void ProfilesDialog::OnPermissionChanged(const LPNMLISTVIEW &pListView) {
    if(bIgnoreItemChanged == true || pListView->iItem == -1 || (pListView->uNewState & LVIS_STATEIMAGEMASK) == (pListView->uOldState & LVIS_STATEIMAGEMASK)) {
        return;
    }

    int iSel = (int)::SendMessage(hWndWindowItems[LV_PROFILES], LVM_GETNEXTITEM, (WPARAM)-1, LVNI_SELECTED);

    if(iSel == -1) {
        return;
    }

    bool bEnabled = ((((pListView->uNewState & LVIS_STATEIMAGEMASK) >> 12) - 1) == 0 ? false : true);

    LVITEM lvItem = { 0 };
    lvItem.mask = LVIF_PARAM;
    lvItem.iItem = pListView->iItem;

    if((BOOL)::SendMessage(hWndWindowItems[LV_PERMISSIONS], LVM_GETITEM, 0, (LPARAM)&lvItem) == FALSE) {
        return;
    }

    ProfileMan->ProfilesTable[iSel]->bPermissions[(int)lvItem.lParam] = bEnabled;
}
//------------------------------------------------------------------------------
