
globalvar AccountID;
globalvar userID;
globalvar AuthToken;

AccountID = ""
userID = ""

RefreshPeriod_AccountID = room_speed*60*10//Around of 10mins

Auth_NotifyLoginStatusChanged = noone 
Connect_NotifyAuthExpiration = noone
Connect_NotifyLoginStatusChanged = noone

request_MFA = noone

NotifyID_Auth_LoginStatusChanged = EpicGames_Auth_AddNotifyLoginStatusChanged()
NotifyID_Connect_AuthExpiration= EpicGames_Connect_AddNotifyAuthExpiration()
NotifyID_Connect_LoginStatusChanged = EpicGames_Connect_AddNotifyLoginStatusChanged()
NotifyID_Friends = EpicGames_Friends_AddNotifyFriendsUpdate()
NotifyID_Achievements_UnlockedV2 = EpicGames_Achievements_AddNotifyAchievementsUnlockedV2()
NotifyID_UI_DisplaySettingsUpdated = EpicGames_UI_AddNotifyDisplaySettingsUpdated()

EpicGames_Auth_Login(
		EpicGames_LCT_PersistentAuth,
		EpicGames_AS_BasicProfile | EpicGames_AS_FriendsList | EpicGames_AS_Presence,
		"",
		"",
		noone
	)

room_goto(Room_EpicGames_Menu)

