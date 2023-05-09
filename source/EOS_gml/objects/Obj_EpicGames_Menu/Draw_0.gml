
draw_set_font(Font_YoYo_15)
draw_set_valign(fa_left)
draw_set_halign(fa_left)

//draw_text(100,130,string(StructTest({yoyo:"opera"})))
//draw_text(100,130,SimpleDesktopExample_ReturnString())

//draw_text(100,100,"Return String: " + string(SimpleDesktopExample_ReturnString()))
//show_debug_message(SimpleDesktopExample_ReturnString())

draw_text(100,100,"EOS Version: " + string(EpicGames_GetVersion()))
//show_debug_message(EpicGames_GetVersion())

//draw_text(100,130,"CountryCode: " + EpicGames_Platform_GetOverrideCountryCode())
//draw_text(100,160,"LocaleCode: " + EpicGames_Platform_GetOverrideLocaleCode())

switch(EpicGames_Auth_GetLoginStatus(AccountID))
{
	case EpicGames_LS_NotLoggedIn:
		draw_text(100,190,"LoginStatus: NotLoggedIn");
	break;
	
	case EpicGames_LS_UsingLocalProfile:
		draw_text(100,190,"LoginStatus: UsingLocalProfile");
	break;
	
	case EpicGames_LS_LoggedIn:
		draw_text(100,190,"LoginStatus: LoggedIn");
	break;
}


draw_text(100,220,"AccountsCount: " + string(EpicGames_Auth_GetLoggedInAccountsCount()))
draw_text(100,250,"AccountID: " + AccountID)
draw_text(100,280,"userID: " + userID)

//if(AccountID != "")
//{
//	show_debug_message(EpicGames_Platform_GetActiveCountryCode(AccountID))
//	show_debug_message(EpicGames_Platform_GetActiveCountryCode(AccountID))
//}


