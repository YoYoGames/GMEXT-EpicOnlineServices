event_inherited();

show_debug_message("mAccountID: " + mAccountID)
request = eos_user_info_query_user_info(global.epic_account_id,mAccountID,function(_info){

		show_debug_message(_info)

	})
