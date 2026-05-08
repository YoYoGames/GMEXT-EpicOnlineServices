
if(global.product_user_id == "")
{
	//show_debug_message("eos_auth_login CALLED")
	eos_auth_login(
		EpicLoginCredentialType.AccountPortal,
        EpicAuthScopeFlags.BasicProfile | EpicAuthScopeFlags.FriendsList | EpicAuthScopeFlags.Presence,
		"",
		"",
		noone
		)
}
else
	eos_auth_logout(global.epic_account_id)


