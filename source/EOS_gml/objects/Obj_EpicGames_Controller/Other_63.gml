
if(async_load[? "id"] == request_MFA)
if(async_load[? "status"])
if(async_load[? "result"] != "")
{
	var code = async_load[? "result"]
	
	eos_auth_login(
		EOS_LOGIN_CREDENTIAL_TYPE.EXCHANGE_CODE, 
        EOS_AUTH_SCOPE_FLAGS.BASIC_PROFILE | EOS_AUTH_SCOPE_FLAGS.FRIENDS_LIST | EOS_AUTH_SCOPE_FLAGS.PRESENCE,
		"",
		code,
		noone)
}
