
if(async_load[? "id"] == request_MFA)
if(async_load[? "status"])
if(async_load[? "result"] != "")
{
	var code = async_load[? "result"]
	
	eos_auth_login(
		EOS_LCT_EXCHANGE_CODE,
		EOS_AS_BASIC_PROFILE | EOS_AS_FRIENDS_LIST | EOS_AS_PRESENCE,
		"",
		code,
		noone)
}
