
draw_set_font(Font_YoYo_20)
draw_set_valign(fa_bottom)
draw_set_halign(fa_left)

var AudioStatus_txt = ""
switch(AudioStatus)
{
	case EOS_RTCAudioStatus.AdminDisabled: AudioStatus_txt = "AdminDisabled" break
	case EOS_RTCAudioStatus.Disabled: AudioStatus_txt = "Disabled" break
	case EOS_RTCAudioStatus.Enabled: AudioStatus_txt = "Enabled" break
	case EOS_RTCAudioStatus.NotListeningDisabled: AudioStatus_txt = "NotListeningDisabled" break
	case EOS_RTCAudioStatus.Unsupported: AudioStatus_txt = "Unsupported" break 
}

draw_text(x,y,$"{display_name} - Audio {AudioStatus_txt} - {Speaking?"Speaking":"Silence"}")


