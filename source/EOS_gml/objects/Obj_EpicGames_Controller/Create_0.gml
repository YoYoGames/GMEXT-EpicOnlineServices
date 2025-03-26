
globalvar AccountID;
globalvar userID;
globalvar AuthToken;

AccountID = ""
userID = ""

RefreshPeriod_AccountID = room_speed*60*10//Around 10mins

Auth_NotifyLoginStatusChanged = noone 
Connect_NotifyAuthExpiration = noone
Connect_NotifyLoginStatusChanged = noone

request_MFA = noone

NotifyID_Auth_LoginStatusChanged = eos_auth_add_notify_login_status_changed()
NotifyID_Connect_AuthExpiration= eos_connect_add_notify_auth_expiration()
NotifyID_Connect_LoginStatusChanged = eos_connect_add_notify_login_status_changed()
NotifyID_Friends = eos_friends_add_notify_friends_update()
NotifyID_Achievements_UnlockedV2 = eos_achievements_add_notify_achievements_unlocked_v2()
NotifyID_UI_DisplaySettingsUpdated = eos_ui_add_notify_display_settings_updated()

eos_auth_login(
		EOS_LCT_PERSISTENT_AUTH,
		EOS_AS_BASIC_PROFILE | EOS_AS_FRIENDS_LIST | EOS_AS_PRESENCE,
		"",
		"",
		noone
	)

room_goto(Room_EpicGames_Menu)

