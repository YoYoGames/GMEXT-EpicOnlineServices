/// @description PRESSED

if(mouse_check_button_pressed(mb_left))
if(point_in_rectangle(mouse_x,mouse_y,x-100,y-100,x+100,y+100))
{
	show_debug_message(achievement_id)
	eos_achievements_unlock_achievement(userID,achievement_id)
}

