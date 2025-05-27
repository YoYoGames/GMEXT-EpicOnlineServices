
if(async_load[? "id"] == request_MFA)
if(async_load[? "status"])
if(async_load[? "result"] != "")
{
	var code = async_load[? "result"]
	
	eos_auth_login(
		EOS_LOGIN_CREDENTIAL_TYPE.ExchangeCode, 
        EOS_AUTH_SCOPE_FLAGS.BasicProfile | EOS_AUTH_SCOPE_FLAGS.FriendsList | EOS_AUTH_SCOPE_FLAGS.Presence,
		"",
		code,
		noone)
}
