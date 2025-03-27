
if(async_load[? "id"] == request_MFA)
if(async_load[? "status"])
if(async_load[? "result"] != "")
{
	var code = async_load[? "result"]
	
	eos_auth_login(
		EOS_LoginCredentialType.ExchangeCode, 
        EOS_AuthScopeFlags.BasicProfile | EOS_AuthScopeFlags.FriendsList | EOS_AuthScopeFlags.Presence,
		"",
		code,
		noone)
}
