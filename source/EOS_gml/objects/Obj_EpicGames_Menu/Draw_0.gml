
draw_set_font(Font_YoYo_15)
draw_set_valign(fa_left)
draw_set_halign(fa_left)

//draw_text(100,130,string(StructTest({yoyo:"opera"})))
//draw_text(100,130,SimpleDesktopExample_ReturnString())

//draw_text(100,100,"Return String: " + string(SimpleDesktopExample_ReturnString()))
//show_debug_message(SimpleDesktopExample_ReturnString())

draw_text(100,100,"EOS Version: " + string(eos_get_version()))
//show_debug_message(eos_get_version())

//draw_text(100,130,"CountryCode: " + eos_platform_get_override_country_code())
//draw_text(100,160,"LocaleCode: " + eos_platform_get_override_locale_code())

switch(eos_auth_get_login_status(AccountID))
{
	case EOS_LOGIN_STATUS.NOT_LOGGED_IN:
		draw_text(100,190,"LoginStatus: NotLoggedIn");
	break;
	
	case EOS_LOGIN_STATUS.USING_LOCAL_PROFILE:
		draw_text(100,190,"LoginStatus: UsingLocalProfile");
	break;
	
	case EOS_LOGIN_STATUS.LOGGED_IN:
		draw_text(100,190,"LoginStatus: LoggedIn");
	break;
}


draw_text(100,220,"AccountsCount: " + string(eos_auth_get_logged_in_accounts_count()))
draw_text(100,250,"AccountID: " + AccountID)
draw_text(100,280,"userID: " + userID)

//if(AccountID != "")
//{
//	show_debug_message(eos_platform_get_active_country_code(AccountID))
//	show_debug_message(eos_platform_get_active_country_code(AccountID))
//}


