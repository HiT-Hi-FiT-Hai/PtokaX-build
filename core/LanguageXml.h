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
#ifndef LanguageXmlH
#define LanguageXmlH
//---------------------------------------------------------------------------

const char* LangXmlStr[] = {
    "ThisHubIsRunning",
    "HubName",
    "MOTD(motd)",
    "HubTopic",
    "HubDescription",
    "AntiMoGLODescription",
    "HubAddress",
    "ResolveToIP",
    "ListenOnlyOnIP",
    "TCPPorts",
    "TCPPortsHint",
    "UDPPort",
    "AdminNick",
    "RedirectAddress",
    "RedirectAllConn",
    "RedirectFull",
    "HublistRegisterAddresses",
    "AutoReg",
    "HubAutoStart",
    "StartHub",
    "StopHub",
    "DisableMOTD",
    "SendMOTDinPM",
    "UsersChat",
    "AdminChat",
    "Auto",
    "RefreshUserlist",
    "CLS",
    "Chat",
    "CMDs",
    "MassMsg",
    "RedirectAllUsers",
    "RegUsers",
    "User",
    "Password",
    "Profile",
    "New",
    "Modify",
    "Remove",
    "RefreshBans",
    "RefreshRangeBans",
    "IP",
    "Nick",
    "BannedBy",
    "Reason",
    "Expire",
    "Range",
    "TemporaryBans",
    "ClearBans",
    "ClearRangeBans",
    "Redirect",
    "PermanentBans",
    "Rules",
    "MinShare",
    "MaxShare",
    "MinSlots",
    "MaxSlots",
    "MaxHubs",
    "Accept",
    "Reject",
    "MsgToSnd",
    "NickLimits",
    "MinLen",
    "MaxLen",
    "ScriptsMemory",
    "ScriptFile",
    "MemUsage",
    "MoveUp",
    "LuaMoveUpHint",
    "MoveDown",
    "LuaMoveDownHint",
    "CheckSyntax",
    "CheckSyntaxHint",
    "RestartScripts",
    "RestartScriptsHint",
    "Load",
    "LuaLoadHint",
    "Save",
    "LuaSaveHint",
    "EnableTray",
    "MinimizeOnStartup",
    "EnableScripting",
    "StopScriptError",
    "ReplyHubCmdsPm",
    "FilterKicks",
    "FilteredKicksToOPs",
    "SendStatus",
    "SendStatusPm",
    "DisallowPingers",
    "ReportPingers",
    "ReportBadTags",
    "ReportBadPass",
    "AdvPassProtect",
    "UseUserIP",
    "AcceptUnknownTag",
    "CheckIP",
    "KeepSlow",
    "CheckStartupNewVersion",
    "CheckUpdateNow",
    "MyinfoProcess",
    "ToAllUsers",
    "OnlyAllowedProfiles",
    "DontSend",
    "ModeToMyINFO",
    "ModeToDescr",
    "MinBeforeNewSend",
    "RegOnlyHub",
    "Language",
    "SaveSettings",
    "ProfileMan",
    "HubBot",
    "UseAsAlias",
    "MinutesLwr",
    "TextFiles",
    "EnableTextFiles",
    "TextFilesPm",
    "RefreshTextFiles",
    "BanMessage",
    "ShowBannedIP",
    "ShowBannedRange",
    "ShowBannedNick",
    "ShowReason",
    "ShowWho",
    "AddMsg",
    "Deflood",
    "MainChat",
    "Disabled",
    "Ignore",
    "Warn",
    "Disconnect",
    "Kick",
    "TempBan",
    "PermBan",
    "SecLwr",
    "SameMainChat",
    "SameMultiMainChat",
    "WithLwr",
    "LinesLwr",
    "PrivateMessages",
    "SamePrivateMessages",
    "SameMultiPrivateMessages",
    "Search",
    "SameSearches",
    "MyINFOs",
    "GetNickLists",
    "MinLwr",
    "GlobalMainChatDeflood",
    "LockChat",
    "OnlyToOPsWithIP",
    "For",
    "WarnSettings",
    "After",
    "Warnings",
    "PMLimits",
    "Length",
    "Lines",
    "MainChatLimits",
    "SearchLengthLimits",
    "ReportFlood",
    "MaxUsersLogins",
    "BruteForcePassProtAct",
    "YearsLwr", 
    "YearLwr", 
    "MonthsLwr", 
    "MonthLwr", 
    "DaysLwr", 
    "DayLwr", 
    "HoursLwr", 
    "HourLwr", 
    "SorryPermBanned", 
    "SorryTempBanned", 
    "UpTime", 
    "UserInfo", 
    "UdpSckCreateErr", 
    "UdpNonBlockFail", 
    "YouSubscribedUdpDebug", 
    "ToUnsubUdpDbg", 
    "YouRedirTo", 
    "SryLastMsgBcs", 
    "ExcMsgLmt", 
    "SorryLast", 
    "MsgsNotSent", 
    "UnbCrtSrvSck", 
    "ErrorCode", 
    "SrvSckOptErr", 
    "ForPortLwr", 
    "SrvBindErr", 
    "SrvListenErr", 
    "Add", 
    "SetAll", 
    "ClearAll",
    "EntFullHub",  
    "AllowLoginBannedIp", 
    "Drop", 
    "GetUserInfo", 
    "Redir", 
    "TemporaryBan", 
    "TemporaryUnban", 
    "PermanentBan", 
    "UnbanPermUnban", 
    "ClearTempBans", 
    "ClearPermBans", 
    "GetBans", 
    "RangePermBan", 
    "RangeUnbanRangePermUnban", 
    "TempRangeBan", 
    "TempRangeUnban", 
    "GetRangeBans", 
    "ClearPermRangeBans", 
    "ClearTempRangeBans", 
    "GagUngag", 
    "TempOP", 
    "StartStopRestartScripts", 
    "RestartHub", 
    "RldTxtFiles", 
    "NoShareLimit", 
    "NoSlotCheck", 
    "NoRatioCheck", 
    "NoMaxHubsCheck", 
    "NoChatLimits", 
    "NoTagCheck", 
    "NoMainChatDeflood", 
    "NoPMDeflood", 
    "NoSearchLimits", 
    "NoSearchDeflood", 
    "NoMyINFODeflood", 
    "NoGetNickListDeflood", 
    "Topic", 
    "AddRegisteredUser", 
    "DelRegisteredUser", 
    "AllowedForOpChat", 
    "SendFullMyinfos", 
    "SendUsersIP", 
    "DontCheckIP", 
    "HaveKeyIsOp", 
    "ProfilesLoadingFailed", 
    "ProfileDelFailed", 
    "Failed", 
    "Name", 
    "NewProfileName", 
    "ProfileNameExist",
    "RegisteredUser",
    "Nickname",
    "UserProfile",
    "Discard",  
    "Error", 
    "Note", 
    "NickMustBeSpecified", 
    "PassMustBeSpecified", 
    "NoBadCharsInNick", 
    "NoPipeInPass", 
    "UserIsAlredyReg", 
    "UserWithSameNickAlredyExist", 
    "ErrorInScript", 
    "NoSynErrInScriptFile", 
    "NoSynErrInScript", 
    "Syntax", 
    "YouBeingKickedBecause", 
    "WasKickedBecause", 
    "WasKickedBy", 
    "BecauseLwr", 
    "Message", 
    "Flooding", 
    "Flooder", 
    "WithIP", 
    "DisconnByScript", 
    "FatalErrInScript", 
    "ScriptStopped", 
    "Banned", 
    "By", 
    "Full", 
    "NoBansFound", 
    "SyntaxErrInCmd", 
    "NickLwr", 
    "NoParamGiven", 
    "IsNotInUserlist", 
    "IsAlredyGagged", 
    "NotAlwToGag",
    "YouGaggedBy", 
    "HasGagged", 
    "Status", 
    "OnlineFrom", 
    "ShareSize", 
    "Description", 
    "Tag", 
    "Connection", 
    "Email", 
    "NoTempBansFound", 
    "Scripts", 
    "NoPermBansFound", 
    "TempRangeBans", 
    "PermRangeBans", 
    "NoRangeBansFound", 
    "NoPermRangeBansFound", 
    "NoTempRangeBansFound", 
    "ReasonLwr", 
    "NoNickSpecified", 
    "YouCantBanYourself", 
    "YouAreNotAllowedTo", 
    "YouHadBeenBannedBecause", 
    "NoReasonSpecified", 
    "IsAlredyBannedUserDisconnected", 
    "IsAlredyBanned", 
    "AddedLwr", 
    "ToBans", 
    "HasBeenBannedBy", 
    "AddedToBans", 
    "TimeLwr", 
    "BadTimeSpecified", 
    "YouBeenTempBannedTo", 
    "AlrBndLngrTimeDisconnected", 
    "IsAlreadyBannedToLongerTime", 
    "HasBeenTempBannedBy", 
    "ToLwr", 
    "HasBeenTempBannedTo", 
    "Sorry", 
    "IsNotInMyTempBans", 
    "RemovedLwr", 
    "FromTempBans", 
    "RemovedFromTempBans", 
    "TopicHasBeenCleared", 
    "TopicHasBeenSetTo", 
    "NewTopic", 
    "YourIpIs", 
    "MessageLwr", 
    "MassMsgToAllSent", 
    "ErrScriptsDisabled", 
    "RestartedScripts", 
    "ScriptsRestarted", 
    "HubWillBeRestarted", 
    "BackInFewMinutes", 
    "TxtFilesSupIsNotEnabled", 
    "ReloadTextFilesLwr",
    "TextFilesReloaded",
    "ScriptNameLwr", 
    "ErrorScript", 
    "NotRunning", 
    "RestartedScript", 
    "Script", 
    "RestartedLwr", 
    "RestartFailed", 
    "FromIPLwr", 
    "ToIP", 
    "IpOrNick", 
    "IsNotInMyPermBans", 
    "FromBans", 
    "RemovedFromBans", 
    "IsNotGagged", 
    "YouAreUngaggedBy", 
    "HasUngagged", 
    "AlredyGotOperatorStatus", 
    "OperatorProfileMissing", 
    "YouGotTempOp", 
    "SetsOperatorModeTo", 
    "GotOperatorStatus", 
    "MassMessageToOPsSent", 
    "DroppedAddedTempbanBy", 
    "DroppedAddedTempbanBecause", 
    "CommandTooLong", 
    "IsNotInRegs", 
    "YoureNotAlwdToDelUserWithThisprofile", 
    "FromRegisteredUsers", 
    "RemovedFromRegisteredUsers", 
    "PortLwr", 
    "UnsubFromUdpDebug", 
    "UnableFindUdpDebugInterface", 
    "NotSubscribUdpDebug", 
    "AlredySubscribUdpDebugToUnsub", 
    "InMainchat", 
    "SubscribUdpDebugOnPort", 
    "ToUnsubType", 
    "UdpDebugSubscripFailed", 
    "HasClearedTempBans", 
    "TempBansCleared", 
    "HasClearedPermBans", 
    "PermBansCleared", 
    "TempRangeBansCleared", 
    "HasClearedPermRangeBans", 
    "PermRangeBansCleared", 
    "NoBanFound", 
    "BannedNick", 
    "NoValidIpSpecified", 
    "BannedIP", 
    "BadParamsGiven", 
    "NoValidIpRangeSpecified", 
    "NoRangeBanFound", 
    "PasswordLwr", 
    "ProfileNameLwr", 
    "MaxAlwdNickLen64Chars", 
    "MaxAlwdPassLen64Chars", 
    "ErrNoProfileGivenNameExist", 
    "YouNotAllowedToAddUserThisProfile", 
    "IsAlreadyRegistered", 
    "SuccessfullyAdded", 
    "ToRegisteredUsers", 
    "SuccessfullyAddedToRegisteredUsers", 
    "FolowCommandsAvailableToYou", 
    "ProfileSpecificCommands", 
    "NewPassword", 
    "ChangeYourPassword", 
    "PermBanUserGivenNickDisconnect", 
    "PermBanIpAddress", 
    "BanUsersNickIfConnThenDisconn", 
    "TempBanUserGivenNickDisconnect", 
    "TempBanIpAddress", 
    "TempBanUsersNickIfConnThenDisconn", 
    "UnbanIpOrNick", 
    "UnbanPermBannedIpOrNick", 
    "UnbanTempBannedIpOrNick", 
    "DisplayListOfBans", 
    "DisplayListOfPermBans", 
    "DisplayListOfTempBans", 
    "ClearPermBansLwr",
    "ClearTempBansLwr",
    "PermBanGivenIpRange", 
    "TempBanGivenIpRange", 
    "UnbanBannedIpRange", 
    "UnbanPermBannedIpRange", 
    "UnbanTempBannedIpRange", 
    "DisplayListOfRangeBans", 
    "DisplayListOfRangePermBans", 
    "DisplayListOfRangeTempBans", 
    "ClearPermRangeBansLwr", 
    "ClearTempRangeBansLwr", 
    "DisplayBanFoundForGivenNick", 
    "DisplayBansFoundForGivenIp", 
    "DisplayRangeBanFoundForGivenRange", 
    "DisconnectWithTempban", 
    "DisplaysInfoOnUserWithGivenNick", 
    "GiveTempOp", 
    "DisallowUserToPostInMainchat", 
    "UserCanPostToMainchatAgain", 
    "RestartHubLwr", 
    "FileNameLwr", 
    "StartScriptWithGivenFilename", 
    "StopScriptWithGivenFilename", 
    "ReStartScriptWithGivenFilename", 
    "RestartScriptingPartOfTheHub", 
    "DisplayListOfScripts", 
    "ReloadAllTextfiles", 
    "AddRegUserWithSpecifiedProfile", 
    "RemoveRegisteredUser", 
    "SetNewTopicOr", 
    "ClearTopic", 
    "SendPrivateMessageToAllUsers", 
    "SendPrivateMessageToAllOPs", 
    "ReasonIsAlwaysOptional", 
    "FullBansDisallowAllFromBannedIpToLogin", 
    "TempBanTimeValues", 
    "GlobalCommands", 
    "SpeakIn3rdPerson", 
    "ShowYourIp", 
    "StoppedScript", 
    "StoppedLwr", 
    "ErrorScriptAlreadyRunning", 
    "ErrorScriptNotExist", 
    "StartedScript", 
    "StartedLwr", 
    "StartFailed", 
    "YouAreNotAllowedToChangePassword", 
    "YourPassUpdateSuccess", 
    "IsNotOnline", 
    "YouAreNotAllowedToBan", 
    "HasBeen", 
    "ByLwr", 
    "IsLwr", 
    "IsAlready", 
    "YouAreNotAllowedToTempBan", 
    "ToLongerTime", 
    "ErrorFrom", 
    "IsNotValidRange", 
    "BanLwr", 
    "TempBanNick", 
    "DropLwr", 
    "BannedLwr", 
    "TempBanned", 
    "IsNotInMyRange", 
    "TempBansLwr",
    "PermBansLwr",
    "IsRemovedFromRange", 
    "IsNotInMyRangeBans", 
    "IsRemovedFromRangeBansBy", 
    "IsRemovedFromRangeBans", 
    "YouAreNotAlwdToUseThisCmd", 
    "WeeksLwr", 
    "HaveNoneExistantProfile", 
    "ChangedProfileTo", 
    "IsAlreadyInRegs", 
    "UserDeleted", 
    "Ready", 
    "SelectUser", 
    "YouAreBeingKicked", 
    "IsKicking", 
    "Mem", 
    "Users", 
    "Client", 
    "Ver", 
    "Mode", 
    "Slots", 
    "Hubs", 
    "AutoOpenSlotWhenUploadUnder", 
    "AreYouSure", 
    "Ban", 
    "YouAreBeingBanned", 
    "YouAreBeingBannedBecause", 
    "ResolvingHubAddress", 
    "ResolvingOfHostname", 
    "HasFailed", 
    "CheckTheAddressPlease", 
    "ResolvedSuccessfully", 
    "Running", 
    "Stopped", 
    "File", 
    "NotExist", 
    "loaded", 
    "SavingFailed", 
    "UpdateCheckFailed", 
    "NewVersion", 
    "ReleasedOn", 
    "Changes", 
    "OpenPtokaXHomepage", 
    "SorryNoNewVersionAvailable", 
    "ReadyLwr", 
    "Total", 
    "Logged", 
    "Closing", 
    "Logging", 
    "ScriptStarted", 
    "Warning", 
    "ScriptWasNotInitialized", 
    "LoadScript", 
    "SaveScript", 
    "SavedLwr", 
    "FullBanned", 
    "NickBan", 
    "IpBan", 
    "Permanent", 
    "GlobalChatFloodDetected", 
    "YouMyINFOIsCorrupted", 
    "FakeTag", 
    "HasSuspiciousTagCheckHim", 
    "FullDescription", 
    "PingerFromIP", 
    "WithNick", 
    "DetectedLwr", 
    "PleaseDontFloodWithGetNickList", 
    "YouAreBeingDisconnectedBecause", 
    "GetNickListFlooding", 
    "GetNickListFlooder", 
    "DisconnectedLwr", 
    "WasKicked", 
    "WasTemporaryBanned", 
    "WasBanned", 
    "YouCantKickYourself", 
    "YouAreNotAllowedToKick", 
    "PleaseDontFloodWithSearches", 
    "SearchFlooding", 
    "SearchFlooder", 
    "SorryMinSearchLenIs", 
    "SorryMaxSearchLenIs", 
    "PleaseDontFloodWithMyINFO", 
    "MyINFOFlooding", 
    "MyINFOFlooder", 
    "YourIPBannedBruteForceAttack", 
    "Your ASS is banned", 
    "BannedBecause3xBadPassForNick", 
    "IncorrectPassword", 
    "YouAreNotAllowedToRedirect", 
    "YouAreRedirectedTo", 
    "IsRedirectedTo", 
    "SorryThisHubNotAllowPingerChecking", 
    "PleaseDontFloodWithPM", 
    "PMFlooding", 
    "PMFlooder", 
    "TheMessageWasTooLong", 
    "PleaseDontFloodChat", 
    "ChatFlooding", 
    "ChatFlooder", 
    "YourNickContainsIllegalCharacter", 
    "PleaseCorrectItAndGetBackAgain", 
    "TheNickIsReservedForSomeoneOther", 
    "ChangeYourNickAndGetBackAgain", 
    "LastPassWasWrongYouNeedWait", 
    "BeforeYouTryAgain", 
    "ThisHubIsFull", 
    "UsersOnlineLwr", 
    "KickUser",
    "BanUser",
    "OpUser",
    "YouCantDropYourself", 
    "YouCantGagYourself", 
    "Close", 
    "YouCantCloseYourself", 
    "YouAreNotAllowedToClose", 
    "WasClosedBy", 
    "WasClosed", 
    "FullLwr", 
    "DescriptionTag", 
    "NoTagAction", 
    "MaxUsersLimit", 
    "TempBanTimeAfterEtc", 
    "HubOwnerEmail", 
    "MainRedirectAddress", 
    "RegOnlyMsg", 
    "MaxPSRLimit", 
    "OpChatBot", 
    "TempBanRedirAddress", 
    "PermBanRedirAddress", 
    "NewConnsFrmSingleIPLim", 
    "PMLimToUsrFrmMultiNicks", 
    "DefloodTempBanTime", 
    "MaximalHubsLimit", 
    "SlotLimits", 
    "HubSlotRatioLimit", 
    "ShareLimits", 
    "ExpertsOnly", 
    "PasswordProtection", 
    "HubStartupAndTrayIcon", 
    "HubCommands", 
    "Scripting", 
    "KickMessages", 
    "StatusMessages", 
    "Pinger", 
    "AllowOnlyRegs", 
    "EnableWithArrow", 
    "EnableAndRegBotOnHub", 
    "SecondsLwr", 
    "Minimum", 
    "Maximum", 
    "MaxMsgsToOneUserPerMin", 
    "Per10Seconds", 
    "TemporaryBanTime", 
    "PrefixesForHubCmds", 
    "GeneralSettings", 
    "MOTD", 
    "DefaultBots", 
    "MoreGeneral", 
    "BanHandling", 
    "Advanced", 
    "AdvancedSecurity", 
    "MoreRules", 
    "MoreDeflood", 
    "Settings", 
    "HubListRegsHint", 
    "MyINFOToHint", 
    "ShareLimitMessageHint", 
    "NickLimitMessageHint", 
    "HubSlotRatioMessageHint", 
    "SlotLimitMessageHint", 
    "HubLimitMessageHint", 
    "RedirectHint", 
    "ZeroUnlimited", 
    "ScriptsMemoryUsage", 
    "Bans", 
    "RangeBans", 
    "AreYouSureDDOS", 
    "SettingsSaved", 
    "OpenExternalEditor", 
    "DeleteScript", 
    "RefreshScripts", 
    "PopupScriptsWindow", 
    "UpdateCheck", 
    "AcceptedConnections", 
    "ClosedConnections", 
    "ActiveConnections", 
    "UsersOnline", 
    "Received", 
    "Sent", 
    "UsersPeak", 
    "CharsNotAllowedInProfile", 
    "FullBan", 
    "CreatedBy", 
    "Temporary", 
    "Day", 
    "Month", 
    "Year", 
    "Hour", 
    "Minute", 
    "TempbanExpiration", 
    "Jan", 
    "Feb", 
    "Mar", 
    "Apr", 
    "May", 
    "Jun", 
    "Jul", 
    "Aug", 
    "Sep", 
    "Oct", 
    "Nov", 
    "Dec", 
    "FullBanHint", 
    "ForNickBanSpecifyNick", 
    "ForIPBanSpecifyIP", 
    "IsNotValidIPAddress", 
    "BadTimeSpecifiedBanExpired", 
    "SimilarBanExist", 
    "YouCantCreateBanWithoutNickOrIP", 
    "FromIP", 
    "To IP", 
    "RangeBan", 
    "BanNotFound", 
    "NoValidTCPPortSpecified", 
    "WasDisconnected", 
    "PleaseDontFloodWithSameSearches", 
    "SameSearchFlooding", 
    "SameSearchFlooder", 
    "PleaseDontFloodWithSamePM", 
    "SamePMFlooding", 
    "SamePMFlooder", 
    "PleaseDontFloodSameChat", 
    "SameChatFlooding", 
    "SameChatFlooder", 
    "PleaseDontFloodSameMultiPM", 
    "SameMultiPMFlooding", 
    "SameMultiPMFlooder", 
    "PleaseDontFloodSameMultiChat", 
    "SameMultiChatFlooding", 
    "SameMultiChatFlooder", 
    "MoreMoreDeflood", 
    "MyINFOLengthLimit", 
    "YourClientSendIncorrectIP", 
    "InCTMReqRealIPIs", 
    "InSearchReqRealIPIs", 
    "ConnectToMe", 
    "NoCTMDeflood", 
    "PleaseDontFloodWithCTM", 
    "CTMFlooding", 
    "CTMFlooder", 
    "RevConnectToMe", 
    "NoRCTMDeflood", 
    "PleaseDontFloodWithRCTM", 
    "RCTMFlooding", 
    "RCTMFlooder", 
    "CTMLenLimit", 
    "RCTMLenLimit", 
    "MyINFOTooLong", 
    "CTMTooLong", 
    "RCTMTooLong", 
    "SR", 
    "NoSRDeflood", 
    "PleaseDontFloodWithSR", 
    "SRFlooding", 
    "SRFlooder", 
    "SRLenLimit", 
    "SRTooLong", 
    "RecvDataFromUser", 
    "NoRecvDeflood", 
    "PleaseDontFloodWithData", 
    "DataFlooding", 
    "DataFlooder", 
    "Interval", 
    "NoChatInterval", 
    "NoPMInterval", 
    "NoSearchInterval", 
    "PleaseWait", 
    "SecBeforeNextChatMsg", 
    "SecBeforeNextPM", 
    "SecBeforeNextSearch", 
    "MaxUsersSameIP", 
    "NoMaxUsersSameIP", 
    "SorryAlreadyMaxIPConns", 
    "NoReConnTime", 
    "ReConnTime", 
    "Min", 
    "SecBeforeReconn", 
    "Rename", 
    "Country", 
    "LogScriptErrors", 
    "QuackSupports", 
    "ClientsBuggySupports", 
    "DisallowBuggySupports", 
    "MaxAlwdTopicLen256Chars",
    "MaxAlwdScriptNameLen256Chars",
    "MaxAlwdIPLen15Chars",
    "View",
    "Help",
    "Exit",
    "website",
    "board",
    "wiki",
    "About",
    "CheckForUpdate",
    "ReloadTextFiles",
    "RedirectAllUsersTo",
    "OriginalMyINFO",
    "OptionsForModifiedMyINFO",
    "RemoveDescription",
    "RemoveTag",
    "RemoveConnection",
    "RemoveEmail",
};
//---------------------------------------------------------------------------

#endif
