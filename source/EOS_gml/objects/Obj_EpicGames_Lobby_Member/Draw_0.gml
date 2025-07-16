
draw_set_font(Font_YoYo_20)
draw_set_valign(fa_bottom)
draw_set_halign(fa_left)

var AudioStatus_txt = ""
switch(AudioStatus)
{
	case EOS_RTC_AUDIO_STATUS.ADMIN_DISABLED: AudioStatus_txt = "AdminDisabled" break
	case EOS_RTC_AUDIO_STATUS.DISABLED: AudioStatus_txt = "Disabled" break
	case EOS_RTC_AUDIO_STATUS.ENABLED: AudioStatus_txt = "Enabled" break
	case EOS_RTC_AUDIO_STATUS.NOT_LISTENING_DISABLED: AudioStatus_txt = "NotListeningDisabled" break
	case EOS_RTC_AUDIO_STATUS.UNSUPPORTED: AudioStatus_txt = "Unsupported" break 
}

draw_text(x,y,$"{display_name} - Audio {AudioStatus_txt} - {Speaking?"Speaking":"Silence"}")


