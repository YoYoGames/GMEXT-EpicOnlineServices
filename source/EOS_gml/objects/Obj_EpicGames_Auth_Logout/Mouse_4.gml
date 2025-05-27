
if(userID == "")
{
	//show_debug_message("eos_auth_login CALLED")
	eos_auth_login(
		EOS_LOGIN_CREDENTIAL_TYPE.AccountPortal, 
        EOS_AUTH_SCOPE_FLAGS.BasicProfile | EOS_AUTH_SCOPE_FLAGS.FriendsList | EOS_AUTH_SCOPE_FLAGS.Presence,
		"",
		"",
		noone
		)
}
else
	eos_auth_logout(AccountID)


