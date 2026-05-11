
//TODO

event_inherited();

show_debug_message("mAccountID: " + mAccountID)
request = eos_user_info_query_user_info(global.epic_account_id,mAccountID,function(_info){
		
		show_debug_message(_info)
		
		//if(async_load[? "identifier"] == request)
		//{
		//	var struct = eos_user_info_copy_user_info(global.epic_account_id,mAccountID)
		//	if(struct.status = EpicResult.Success)
		//	{
		//		user_display_name = struct.display_name
		//		//struct.PreferredLanguage
		//		//struct.user_id
		//		show_debug_message(struct)
		//	}
		//	else show_debug_message("ERROR!!!")
		//}
	})
