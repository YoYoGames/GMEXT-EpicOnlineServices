
if(userID == "")
{
	//show_debug_message("eos_auth_login CALLED")
	eos_auth_login(
		EOS_LoginCredentialType.AccountPortal, 
        EOS_AuthScopeFlags.BasicProfile | EOS_AuthScopeFlags.FriendsList | EOS_AuthScopeFlags.Presence,
		"",
		"",
		noone
		)
}
else
	eos_auth_logout(AccountID)


