
if(global.product_user_id == "")
{
	show_debug_message("eos_auth_login CALLED")
	eos_auth_login("", "", EpicLoginCredentialType.AccountPortal,
	    EpicExternalCredentialType.Epic,
	    EpicAuthScopeFlags.BasicProfile | EpicAuthScopeFlags.FriendsList | EpicAuthScopeFlags.Presence,
		EpicAuthLoginFlags.NoFlags,
	    function(_info) {
	        if (_info.result_code == EpicResult.Success)
	            show_debug_message("Logged in: " + _info.local_user_id);
	        else
	            show_debug_message("Login failed: " + string(_info.result_code));
	    });
}
else
	eos_auth_logout(global.epic_account_id)


