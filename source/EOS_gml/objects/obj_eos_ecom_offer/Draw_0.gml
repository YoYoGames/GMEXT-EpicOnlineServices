
if(selected)
{
	draw_set_color(c_gray)
	image_alpha = 0.5
}
else
{
	draw_set_color(c_white)
	image_alpha = 1.0
}

draw_text(x,bbox_top-30,title_text)// + string(available_for_purchase))
draw_text(x,bbox_bottom+30,string(current_price64/power(10,decimal_point)) + currency_code)

if(sprite_exists(sprite_index))
	draw_self()
