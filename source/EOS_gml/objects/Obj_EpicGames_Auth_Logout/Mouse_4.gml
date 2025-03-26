
if(userID == "")
{
	//show_debug_message("eos_auth_login CALLED")
	eos_auth_login(
		EOS_LCT_ACCOUNT_PORTAL,
		EOS_AS_BASIC_PROFILE | EOS_AS_FRIENDS_LIST | EOS_AS_PRESENCE,
		"",
		"",
		noone
		)
}
else
	eos_auth_logout(AccountID)


