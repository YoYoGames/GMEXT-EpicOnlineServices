
show_debug_message("Async: " + json_encode(async_load))

switch(async_load[? "type"])
{
	case "eos_auth_logout":
		
		AccountID = ""
		userID = ""
		alarm[0] = -1
		
	break
	
	case "eos_auth_link_account":
	case "eos_auth_login":
        
		switch(async_load[? "status"])
		{
			case EOS_RESULT.SUCCESS:
			
				alarm[0] = RefreshPeriod_AccountID
		
				AccountID = async_load[? "account_id"]
				
				var AuthToken = eos_auth_copy_user_auth_token(AccountID)
				eos_connect_login(EOS_EXTERNAL_CREDENTIAL_TYPE.EPIC,AuthToken.access_token,"")
				
				if(!instance_number(Obj_EpicGames_Metrics))
					instance_create_depth(0,0,0,Obj_EpicGames_Metrics)
				
			break
			
			case EOS_RESULT.INVALID_USER:
				
				eos_auth_link_account(AccountID,EOS_LInk_ACCOUNT_FLAGS.NoFlags)
				
			break
			
			case EOS_RESULT.AUTH_MFA_REQUIRED:
			
				request_MFA = get_string_async("token","")

			break
		}
		
	break

	case "eos_connect_login":
	case "eos_connect_create_user":
	
		switch(async_load[? "status"])
		{
			case EOS_RESULT.SUCCESS:
				
				userID = async_load[? "local_user_id"]
				
			break
			
			case EOS_INVALID_USER:
				eos_connect_create_user()
			break
		}
		
	break
	
	case "eos_auth_add_notify_login_status_changed":
	break
	
	case "eos_connect_add_notify_auth_expiration":
	break
	
	case "eos_connect_add_notify_login_status_changed":
	break
	
	case "eos_friends_add_notify_friends_update":
	break
	
	case "eos_achievements_add_notify_achievements_unlocked_v2":
	break
	
	case "eos_ui_add_notify_display_settings_updated":
	break
	
}


