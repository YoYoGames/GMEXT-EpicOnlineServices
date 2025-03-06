
show_debug_message("Async: " + json_encode(async_load))

switch(async_load[?"type"])
{
	case "EpicGames_Auth_Logout":
		
		AccountID = ""
		userID = ""
		alarm[0] = -1
		
	break
	
	case "EpicGames_Auth_LinkAccount":
	case "EpicGames_Auth_Login":
		
		switch(async_load[?"status"])
		{
			case EpicGames_Success:
			
				alarm[0] = RefreshPeriod_AccountID
		
				AccountID = async_load[?"AccountID"]
				
				var AuthToken = EpicGames_Auth_CopyUserAuthToken(AccountID)
				EpicGames_Connect_Login(EpicGames_ECT_EPIC,AuthToken.AccessToken,"")
				
				if(!instance_number(Obj_EpicGames_Metrics))
					instance_create_depth(0,0,0,Obj_EpicGames_Metrics)
				
			break
			
			case EpicGames_InvalidUser:
				
				EpicGames_Auth_LinkAccount(AccountID,EpicGames_LA_NoFlags)
				
			break
			
			case EpicGames_Auth_MFARequired:
			
				request_MFA = get_string_async("token","")

			break
		}
		
	break

	case "EpicGames_Connect_Login":
	case "EpicGames_Connect_CreateUser":
	
		switch(async_load[?"status"])
		{
			case EpicGames_Success:
				
				userID = async_load[?"LocalUserId"]
				
			break
			
			case EpicGames_InvalidUser:
				EpicGames_Connect_CreateUser()
			break
		}
		
	break
	
	case "EpicGames_Auth_AddNotifyLoginStatusChanged":
	break
	
	case "EpicGames_Connect_AddNotifyAuthExpiration":
	break
	
	case "EpicGames_Connect_AddNotifyLoginStatusChanged":
	break
	
	case "EpicGames_Friends_AddNotifyFriendsUpdate":
	break
	
	case "EpicGames_Achievements_AddNotifyAchievementsUnlockedV2":
	break
	
	case "EpicGames_UI_AddNotifyDisplaySettingsUpdated":
	break
	
}


