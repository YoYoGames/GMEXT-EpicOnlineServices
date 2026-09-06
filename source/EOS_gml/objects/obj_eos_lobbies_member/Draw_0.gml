
draw_set_font(Font_YoYo_20)
draw_set_valign(fa_bottom)
draw_set_halign(fa_left)

var AudioStatus_txt = ""
switch(AudioStatus)
{
	
	case EpicRTCAudioStatus.AdminDisabled: AudioStatus_txt = "AdminDisabled" break
	case EpicRTCAudioStatus.Disabled: AudioStatus_txt = "Disabled" break
	case EpicRTCAudioStatus.Enabled: AudioStatus_txt = "Enabled" break
	case EpicRTCAudioStatus.NotListeningDisabled: AudioStatus_txt = "NotListeningDisabled" break
	case EpicRTCAudioStatus.Unsupported: AudioStatus_txt = "Unsupported" break 
}

draw_text(x,y,$"{data.display_name} - Audio {AudioStatus_txt} - {Speaking?"Speaking":"Silence"}")


