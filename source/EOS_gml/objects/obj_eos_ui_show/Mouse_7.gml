
if(!locked)
{
	eos_ui_show_friends(global.epic_account_id, function(_info) {
	    show_debug_message("ShowFriends result: " + string(_info.result_code));
	});
	show_debug_message(eos_api_last_error())
}
