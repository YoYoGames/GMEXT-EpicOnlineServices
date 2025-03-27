
if(async_load[? "type"] != "eos_user_info_query_user_info") return;

show_debug_message(json_encode(async_load))

if(async_load[? "identifier"] == request)
{
	var struct = eos_user_info_copy_user_info(AccountID,mAccountID)
	if(struct.status = EOS_SUCCESS)
	{
		user_display_name = struct.display_name
		//struct.PreferredLanguage
		//struct.user_id
		show_debug_message(struct)
	}
	else show_debug_message("ERROR!!!")
}

