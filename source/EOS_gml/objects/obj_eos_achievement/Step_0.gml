/// @description PRESSED

if(mouse_check_button_pressed(mb_left))
if(point_in_rectangle(mouse_x,mouse_y,x-100,y-100,x+100,y+100))
{
	show_debug_message(data.achievement_id)
	eos_achievements_unlock_achievements(global.product_user_id,[data.achievement_id],function(_data){
			show_debug_message(_data)
		})
}

