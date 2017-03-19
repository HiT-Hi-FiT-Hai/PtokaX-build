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
#ifndef SettingComH
#define SettingComH
//---------------------------------------------------------------------------

const char * SetBoolCom[] = {
    "# Anti MoGlo description\n", 
    "# Hub autostart. Non-gui version starting automatically!\n", 
    "# Redirect all connecting users\n", 
    "# Redirect users when hub is full\n", 
    "# Automatically register hub to hublist\n", 
    "# Hub for registered users only\n", 
    "# Redirect non-registered users when hub is for registered users only\n", 
    "# Redirect user when his share is outside share limits\n", 
    "# Redirect user when his slot count is outside slot limits\n", 
    "# Redirect user when his hub/slot ratio not meet hub/slot ratio limit\n", 
    "# Redirect user when his hub count is above maximal hubs limit\n", 
    "# Add user connection mode(s) to MyINFO command\n", 
    "# Add user connection mode(s) to description\n", 
    "# Remove user description from MyINFO command\n", 
    "# Remove user client tag from MyINFO command\n", 
    "# Remove user connection from MyINFO command\n", 
    "# Remove user email from MyINFO command\n", 
    "# Register hub bot on hub\n", 
    "# Use hub bot nick instead of Hub-Security\n", 
    "# Register Opchat bot on hub\n", 
    "# Redirect user when he is temporary banned\n", 
    "# Redirect user when he is permanently banned\n", 
    "# Enable Lua scripting interface\n", 
    "# Don't disconnect slow clients, who are not able to receive all data from hub, when it is possible\n", 
    "# Automatically check for new PtokaX releases on startup. Only in gui version!\n", 
    "# Enable tray icon. Only in gui version!\n", 
    "# Start minimized. Only in gui version!\n", 
    "# Filter kick messages from chat\n", 
    "# When kick messages filtering from chat is enabled, then always send kick messages to hub Operators\n", 
    "# Send status messages to Operators\n", 
    "# Send status messages as private messages to Operators\n", 
    "# Enable text files\n", 
    "# Send text files as private messages\n", 
    "# Stop script on script error\n", 
    "# Send MOTD as private message\n", 
    "# Report deflood actions to Operators\n", 
    "# Reply to hub commands in private message\n", 
    "# Disable MOTD\n", 
    "# Block hublist pingers from hub checking\n", 
    "# Report hublist pingers to Operators\n", 
    "# Report when someone sent 3 times bad password for registered user\n", 
    "# Advanced password protection\n", 
    "# Listen only on single IP address for every TCP/IP\n", 
    "# Resolve hostname to IP address(es)\n", 
    "# Redir user when his nick length is outside nick length limits\n", 
/*Obsolete "SendUserIP2ToUserOnLogin"*/"",
    "# Send IP address in ban message\n", 
    "# Send range in ban message\n", 
    "# Send nick in ban message\n", 
    "# Send reason in ban message\n", 
    "# Send who created ban in ban message\n", 
    "# Report suspicious tag to Operators\n", 
/*Obsolete "AcceptUnknownTag"*/"",
/*Obsolete "CheckIpInCommands"*/"", 
/*Obsolete "PopupScriptsWindow"*/"",
    "# Save script errors to log\n", 
    "# Disallow clients sending buggy $Supports command\n", 
    "# Store registered users passwords as hashes\n",
#if defined(_WITH_SQLITE) || defined(_WITH_POSTGRES) || defined(_WITH_MYSQL)
	"# Enable database support\n",
#endif
};

const char * SetShortCom[] = {
    "# Maximal users limit. Maximum 32767\n", 
    "# Minimal share limit. Maximum 9999\n", 
    "# Minimal share units. 0 = B, 1 = kB, 2 = MB, 3 = GB, 4 = TB\n", 
    "# Maximal share limit. Maximum 9999\n", 
    "# Maximal share units. 0 = B, 1 = kB, 2 = MB, 3 = GB, 4 = TB\n", 
    "# Minimal slots limit\n", 
    "# Maximal slots limit. Maximum 999\n", 
    "# Hubs for hub/slot ratio. Maximum 999\n", 
    "# Slots for hub/slot ratio. Maximum 999\n", 
    "# Maximal hubs limit. Maximum 999\n", 
    "# No client tag option. 0 = accept, 1 = reject, 2 = redirect\n", 
    "# Send original MyINFO to... 0 = to all users, 1 = to allowed profiles, 2 = don't send\n", 
    "# Maximal chat length limit. Maximum 32767\n", 
    "# Maximal chat lines limit. Maximum 999\n", 
    "# Maximal private message length limit. Maximum 32767\n", 
    "# Maximal private message lines limit. Maximum 999\n", 
    "# Default temporary ban time. Must be higher than 0! Maximum 32767\n", 
    "# Maximal passive search replys limit. Maximum 32767\n", 
    "# Time before new MyINFO from user is accepted for broadcast. Maximum 999\n", 
    "# Main chat deflood messages count. Must be higher than 0! Maximum 999\n", 
    "# Main chat deflood time. Must be higher than 0! Maximum 999\n", 
    "# Main chat deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Same main chat deflood messages count. Must be higher than 1! Maximum 999\n", 
    "# Same main chat deflood time. Must be higher than 0! Maximum 999\n", 
    "# Same main chat deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Same multiline main chat deflood messages count. Must be higher than 1! Maximum 999\n", 
    "# Same multiline main chat deflood lines. Minimum 2, maximum 999\n", 
    "# Same multiline main chat deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Private message deflood messages count. Must be higher than 0! Maximum 999\n", 
    "# Private message deflood time. Must be higher than 0! Maximum 999\n", 
    "# Private message deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Same private message deflood messages count. Must be higher than 1! Maximum 999\n", 
    "# Same private message deflood time. Must be higher than 0! Maximum 999\n", 
    "# Same private message deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Same multiline private message deflood messages count. Must be higher than 1! Maximum 999\n", 
    "# Same multiline private message deflood lines. Minimum 2, maximum 999\n", 
    "# Same multiline private message action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Search deflood messages count. Must be higher than 0! Maximum 999\n", 
    "# Search deflood time. Must be higher than 0! Maximum 999\n", 
    "# Search deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Same search deflood messages count. Must be higher than 1! Maximum 999\n", 
    "# Same search deflood time. Must be higher than 0! Maximum 999\n", 
    "# Same search deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# MyINFO deflood messages count. Must be higher than 0! Maximum 999\n", 
    "# MyINFO deflood time. Must be higher than 0! Maximum 999\n", 
    "# MyINFO deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# GetNickList deflood messages count. Must be higher than 0! Maximum 999\n", 
    "# GetNickList deflood time. Must be higher than 0! Maximum 999\n", 
    "# GetNickList deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# New connections to hub deflood connections count. Must be higher than 0! Maximum 999\n", 
    "# New connection to hub deflood time. Must be higher than 0! Maximum 999\n", 
    "# Deflood warnings count. ust be higher than 0! Maximum 999\n", 
    "# Deflood warnings action. 0 = disconnect user, 1 = kick user, 2 = temporary ban user, 3 = permanently ban user\n", 
    "# Deflood tempban time. Must be higher than 0!\n", 
    "# Global main chat messages count. Must be higher than 0! Maximum 999\n", 
    "# Global main chat time. Must be higher than 0! Maximum 999\n", 
    "# Global main chat time for lock chat or send to Operators with IP action is taken . Must be higher than 0! Maximum 999\n", 
    "# Global main chat action. 0 = deflood disabled, 1 = lock chat, 2 = send to Operators with IP address\n", 
    "# Minimal search length\n", 
    "# Maximal search length. Maximum 999\n", 
    "# Minimal nick length. Maximum 64\n", 
    "# Max nick length. Maximum 64\n", 
    "# Brute force password protection ban type. 0 = disabled, 1 = permanent ban, 2 = temporary ban\n", 
    "# Brute force password protection temporary ban time. Must be higher than 0!\n", 
    "# Maximal private messages count to same user per minute. Maximum 999\n", 
    "# Maximal simultaneous user logins. Must be higher than 0! Maximum 999\n", 
    "# Secondary main chat deflood messages count. Must be higher than 0! Maximum 999\n", 
    "# Secondary main chat deflood time. Must be higher than 0! Maximum 999\n", 
    "# Secondary main chat deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Secondary private message deflood messages count. Must be higher than 0! Maximum 999\n", 
    "# Secondary private message deflood time. Must be higher than 0! Maximum 999\n", 
    "# Secondary private message deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Secondary search deflood messages count. Must be higher than 0! Maximum 999\n", 
    "# Secondary search deflood time. Must be higher than 0! Maximum 999\n", 
    "# Secondary search deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Secondary MyINFO deflood messages count. Must be higher than 0! Maximum 999\n", 
    "# Secondary MyINFO deflood time. Must be higher than 0! Maximum 999\n", 
    "# Secondary MyINFO deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Maximal MyINFO length. Minimum 64, maximum 512\n", 
    "# ConnectToMe deflood count. Must be higher than 0! Maximum 9999\n", 
    "# ConnectToMe deflood time. Must be higher than 0! Maximum 9999\n", 
    "# ConnectToMe deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Secondary ConnectToMe deflood count. Must be higher than 0! Maximum 9999\n", 
    "# Secondary ConnectToMe deflood time. Must be higher than 0! Maximum 9999\n", 
    "# Secondary ConnectToMe deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# RevConnectToMe deflood count. Must be higher than 0! Maximum 9999\n", 
    "# RevConnectToMe deflood time. Must be higher than 0! Maximum 9999\n", 
    "# RevConnectToMe deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Secondary RevConnectToMe deflood count. Must be higher than 0! Maximum 9999\n", 
    "# Secondary RevConnectToMe deflood time. Must be higher than 0! Maximum 9999\n", 
    "# Secondary RevConnectToMe deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Maximal ConnectToMe length. Must be higher than 0! Maximum 512\n", 
    "# Maximal RevConnectToMe length. Must be higher than 0! Maximum 512\n", 
    "# SR deflood count. Must be higher than 0! Maximum 32767\n", 
    "# SR deflood time. Must be higher than 0! Maximum 9999\n", 
    "# SR deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Secondary SR deflood count. Must be higher than 0! Maximum 32767\n", 
    "# Secondary SR deflood time. Must be higher than 0! Maximum 9999\n", 
    "# Secondary SR deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Maximal SR length. Must be higher than 0! Maximum 8192\n", 
    "# Maximal received data deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Maximal received data deflood kB. Must be higher than 0! Maximum 9999\n", 
    "# Maximal received data deflood time. Must be higher than 0! Maximum 9999\n", 
    "# Secondary maximal received data deflood action. 0 = deflood disabled, 1 = ignore message, 2 = warn user, 3 = disconnect user, 4 = kick user, 5 = temporary ban user, 6 = permanently ban user\n", 
    "# Secondary maximal received data deflood kB. Must be higher than 0! Maximum 9999\n", 
    "# Secondary maximal received data deflood time. Must be higher than 0! Maximum 9999\n", 
    "# Chat messages interval messages. Must be higher than 0! Maximum 999\n", 
    "# Chat messages interval time. Must be higher than 0! Maximum 999\n", 
    "# Private messages interval messages. Must be higher than 0! Maximum 999\n", 
    "# Private messages interval time. Must be higher than 0! Maximum 999\n", 
    "# Search interval count. Must be higher than 0! Maximum 999\n", 
    "# Search interval time. Must be higher than 0! Maximum 999\n", 
    "# Maxial connections from same IP address. Must be higher than 0! Maximum 256\n", 
    "# Minimum reconnect time in seconds. Must be higher than 0! Maximum 256\n", 
#if defined(_WITH_SQLITE) || defined(_WITH_POSTGRES) || defined(_WITH_MYSQL)
    "# Remove records older than x days from database. Maximum 32767\n",
#endif
    "", 
};

const char * SetTxtCom[] = {
    "# Hub name. Minimal length 1, maximal length 256. $ and | is not allowed\n", 
    "# Admin nick. Minimal length 1. Maximal length 64. $, | and space is not allowed\n", 
    "# Hub address. Minimal length 1. Maximal length 256. $ and | is not allowed\n", 
    "# TCP ports. Minimal length 1. Maximal length 64\n", 
    "# UDP port. Minimal length 1. Maximal length 5\n", 
    "# Hub description. Maximal length 256. $ and | is not allowed\n", 
    "# Main redirect address. Maximal length 256. | is not allowed\n", 
    "# Hublist register servers. Maximal length 1024\n", 
    "# Registered users only message. Minimal length 1. Maximal length 256. | is not allowed\n", 
    "# Registered users only redirect address. Maximal length 256. | is not allowed\n", 
    "# Hub topic. Maximal length 256. $ and | is not allowed\n", 
    "# Share limit message. Use %[min] for minimal share size and %[max] for maximal share size. Minimal length 1. Maximal length 256. | is not allowed\n", 
    "# Share limit redirect address. Maximal length 256. | is not allowed\n", 
    "# Slot limit message. Use %[min] for minimal slots and %[max] for maximal slots. Minimal length 1. Maximal length 256. | is not allowed\n", 
    "# Slot limit redirect address. Maximal length 256. | is not allowed\n", 
    "# Hub/slot ratio limit message. Use %[hubs] for hubs and %[slots] for slots. Minimal length 1. Maximal length 256. | is not allowed\n", 
    "# Hub/slot ratio limit redirect address. Maximal length 256. | is not allowed\n", 
    "# Max hubs limit message. Use %[hubs] for maximal hubs. Minimal length 1. Maximal length 256. | is not allowed\n", 
    "# Max hubs limit redirect address. Maximal length 256. | is not allowed\n", 
    "# No tag rule message. Minimal length 1. Maximal length 256. | is not allowed\n", 
    "# No tag rule redirect address. Maximal length 256. | is not allowed\n", 
    "# Hub bot nick. Minimal length 1. Maximal length 64. $, | and space is not allowed\n", 
    "# Hub bot description. Maximal length 64. $ and | is not allowed\n", 
    "# Hub bot email. Maximal length 64. $ and | is not allowed\n", 
    "# OpChat bot nick. Minimal length 1. Maximal length 64. $, | and space is not allowed\n", 
    "# OpChat bot description. Maximal length 64. $ and | is not allowed\n", 
    "# OpChat bot email. Maximal length 64. $ and | is not allowed\n", 
    "# Temporary ban redirect address. Maximal length 256. | is not allowed\n", 
    "# Perm ban redirect address. Maximal length 256. | is not allowed\n", 
    "# Chat commands prefixes. Minimal length 1. Maximal length 5. | and space is not allowed\n", 
    "# Hub owner email. Maximal length 64. $ and | is not allowed\n", 
    "# Nick limit message. Use %[min] for minimal length and %[max] for maximal length. Minimal length 1. Maximal length 256. | is not allowed\n", 
    "# Nick limit redirect address. Maximal length 256. | is not allowed\n", 
    "# Additional message to ban message. Maximal length 256. | is not allowed\n", 
    "# Language\n", 
    "# IP address for TCP/IP version 4. Maximal length 15\n",
    "# IP address for TCP/IP version 6. Maximal length 39\n",
    "# Character encoding for non-unicode texts\n",
#ifdef _WITH_POSTGRES
    "# PostgreSQL database host\n",
    "# PostgreSQL database port\n",
    "# PostgreSQL database name\n",
    "# PostgreSQL database user\n",
    "# PostgreSQL database password\n",
#elif _WITH_MYSQL
    "# MySQL database host\n",
    "# MySQL database port\n",
    "# MySQL database name\n",
    "# MySQL database user\n",
    "# MySQL database password\n",
#endif
};
//---------------------------------------------------------------------------

#endif
