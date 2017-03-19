/*
 * PtokaX - hub server for Direct Connect peer to peer network.

 * Copyright (C) 2004-2017  Petr Kozelka, PPK at PtokaX dot org

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

const char * LangXmlStr[] = {
    "ThisHubIsRunning",
    "HubName",
    "MOTD(motd)",
    "HubTopic",
    "HubDescription",
    "AntiMoGLODescription",
    "HubAddress",
    "ResolveHostToIPs",
    "ListenOnlyOnIPs",
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
    "Auto",
    "RefreshUserlist",
    "Chat",
    "CMDs",
    "MassMsg",
    "RedirectAllUsers",
    "RegUsers",
    "User",
    "Password",
    "Profile",
    "Remove",
    "IP",
    "Nick",
    "BannedBy",
    "Reason",
    "Expire",
    "Range",
    "TemporaryBans",
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
    "ScriptFile",
    "MemUsage",
    "MoveUp",
    "MoveDown",
    "CheckSyntax",
    "RestartScripts",
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
    "KeepSlow",
    "CheckStartupNewVersion",
    "MyinfoProcess",
    "ToAllUsers",
    "OnlyAllowedProfiles",
    "DontSend",
    "ModeToMyINFO",
    "ModeToDescr",
    "DontSendMyINFOChanges",
    "RegOnlyHub",
    "Language",
    "SaveSettings",
    "HubBot",
    "UseAsAlias",
    "MinutesLwr",
    "TextFiles",
    "EnableTextFiles",
    "TextFilesPm",
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
    "SendLongMyinfos",
    "SendUsersIP", 
    "DontCheckIP", 
    "HaveKeyIsOp", 
    "ProfilesLoadingFailed", 
    "ProfileDelFailed", 
    "NewProfileName",
    "ProfileNameExist",
    "RegisteredUser",
    "Discard",
    "Error", 
    "NickMustBeSpecified",
    "PassMustBeSpecified", 
    "NoBadCharsInNickName",
    "NoPipeInPass",
    "UserIsAlredyReg", 
    "NoSynErrInScriptFile",
    "NoSynErrInScript", 
    "Syntax", 
    "YouBeingKickedBecause", 
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
    "HasClearedTempRangeBans",
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
    "YouAreBeingKicked",
    "Users",
    "Client", 
    "Version",
    "Mode", 
    "Slots", 
    "Hubs", 
    "AutoOpenSlotWhenUploadUnder", 
    "AreYouSure", 
    "Ban", 
    "YouAreBeingBannedBecause",
    "ResolvingHubAddress", 
    "ResolvingOfHostname", 
    "HasFailed", 
    "CheckTheAddressPlease", 
    "ResolvedSuccessfully", 
    "Running", 
    "Stopped", 
    "File", 
    "UpdateCheckFailed",
    "NewVersion", 
    "ReleasedOn", 
    "Changes", 
    "SorryNoNewVersionAvailable",
    "Total",
    "Logged", 
    "Closing", 
    "Logging", 
    "ScriptStarted", 
    "LoadScript",
    "SaveScript", 
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
    "PSRLimit", 
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
    "Bans",
    "RangeBans", 
    "SettingsSaved",
    "OpenExternalEditor", 
    "DeleteScript", 
    "RefreshScripts", 
    "CheckingForUpdate",
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
    "ForNickBanSpecifyNick",
    "ForIPBanSpecifyIP", 
    "IsNotValidIPAddress", 
    "BadTimeSpecifiedBanExpired", 
    "SimilarBanExist", 
    "YouCantCreateBanWithoutNickOrIP", 
    "RangeBan",
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
    "ConnectToMeLenLimit",
    "RevConnectToMeLenLimit",
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
    "SecBeforeReconn",
    "Rename", 
    "Country", 
    "LogScriptErrors", 
    "QuackSupports", 
    "DisallowBuggySupports",
    "MaxAlwdTopicLen256Chars",
    "MaxAlwdScriptNameLen256Chars",
    "MaxAlwdIPLen39Chars",
    "View",
    "Help",
    "Exit",
    "website",
    "forum",
    "wiki",
    "MenuAbout",
    "CheckForUpdate",
    "ReloadTextFiles",
    "RedirectAllUsersTo",
    "SendLongMyINFO",
    "OptionsForShortMyINFO",
    "RemoveDescription",
    "RemoveTag",
    "RemoveConnection",
    "RemoveEmail",
    "0Disabled",
    "LwrKiloBytes",
    "Bytes",
    "KiloBytes",
    "MegaBytes",
    "GigaBytes",
    "TeraBytes",
    "MenuSettings",
    "About",
    "Stats",
    "MenuCopy",
    "MenuSelectAll",
    "MenuRegisterUser",
    "MenuDisconnectUser",
    "MenuKickUser",
    "MenuBanUser",
    "MenuRedirectUser",
    "PleaseEnterReason",
    "WasRedirectedTo",
    "PleaseEnterRedirectAddress",
    "Limiter",
    "ScriptsErrors",
    "ScriptEditor",
    "OpenScriptEditor",
    "FailedToOpen",
    "OpenInScriptEditor",
    "FailedToSave",
    "FailedToCheckSyntax",
    "Change",
    "FilterRegisteredUsers",
    "UserDeletedAcceptToNew",
    "UserChanged",
    "AddNewReg",
    "Profiles",
    "AddNewProfile",
    "ProfilePermissions",
    "AddNewBan",
    "FilterBans",
    "BanDeletedAcceptToNew",
    "AddNewRangeBan",
    "FilterRangeBans",
    "RangeBanDeletedAcceptToNew",
    "IsAvailable",
    "IPv4Address",
    "IPv6Address",
    "Register",
    "As",
    "Registered",
    "YouWereRegisteredPleaseEnterYourPassword",
    "SorryYouAreAlreadyRegistered",
    "ThankYouForPasswordYouAreNowRegisteredAs",
    "RegisterUserWithSpecifiedProfile",
    "InCommandHubReplacedItWithYourRealIP",
    "YourNickContainsIllegalWhiteCharacter",
    "PasswordIsHashed",
    "StoreRegPassHashed", 
    "YourClientSentIncorrectPortInCTM", 
    "YourClientSentIncorrectPortInSearch", 
    "NotFound", 
	"OfflineFrom", 
	"DisplaysInfoOnGivenIP",
	"DatabaseSupport",
	"EnableDatabase",
	"RemoveOldRecords",
	"YouCanUseSQLWildcards",
	"Unlimited", 
	"YourClientSendIncorrectIpPortInCmd",
};
//---------------------------------------------------------------------------

#endif
