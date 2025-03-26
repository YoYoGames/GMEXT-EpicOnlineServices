
alarm[0] = RefreshPeriod_AccountID

var struct = eos_auth_copy_user_auth_token(AccountID)

eos_auth_login(
	EOS_LCT_REFRESH_TOKEN,
	EOS_AS_BASIC_PROFILE | EOS_AS_FRIENDS_LIST | EOS_AS_PRESENCE,
	"",
	struct.RefreshToken,
	noone
	)
