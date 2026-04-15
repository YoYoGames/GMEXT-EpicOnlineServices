
draw_set_font(Font_YoYo_15)
draw_set_valign(fa_left)
draw_set_halign(fa_left)

draw_text(100,100,"EOS Version: " + string(eos_api_get_version()))

//draw_text(100,130,"CountryCode: " + eos_platform_get_override_country_code())
//draw_text(100,160,"LocaleCode: " + eos_platform_get_override_locale_code())

switch(eos_auth_get_login_status(global.epic_account_id))
{
	case EpicLoginStatus.NotLoggedIn:
		draw_text(100,190,"LoginStatus: NotLoggedIn");
	break;
	
	case EpicLoginStatus.UsingLocalProfile:
		draw_text(100,190,"LoginStatus: UsingLocalProfile");
	break;
	
	case EpicLoginStatus.LoggedIn:
		draw_text(100,190,"LoginStatus: LoggedIn");
	break;
}


draw_text(100,220,"AccountsCount: " + string(eos_auth_get_logged_in_accounts_count()))
draw_text(100,250,"global.epic_account_id: " + global.epic_account_id)
draw_text(100,280,"global.product_user_id: " + global.product_user_id)

//if(global.epic_account_id != "")
//{
//	show_debug_message(eos_platform_get_active_country_code(global.epic_account_id))
//	show_debug_message(eos_platform_get_active_country_code(global.epic_account_id))
//}


