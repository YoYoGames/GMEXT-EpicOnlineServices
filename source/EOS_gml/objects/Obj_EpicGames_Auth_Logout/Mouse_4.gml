
if(userID == "")
{
	//show_debug_message("eos_auth_login CALLED")
	eos_auth_login(
		EOS_LOGIN_CREDENTIAL_TYPE.ACCOUNT_PORTAL, 
        EOS_AUTH_SCOPE_FLAGS.BASIC_PROFILE | EOS_AUTH_SCOPE_FLAGS.FRIENDS_LIST | EOS_AUTH_SCOPE_FLAGS.PRESENCE,
		"",
		"",
		noone
		)
}
else
	eos_auth_logout(AccountID)


