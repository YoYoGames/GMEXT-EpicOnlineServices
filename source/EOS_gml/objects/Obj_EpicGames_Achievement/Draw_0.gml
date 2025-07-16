
if(locked)
{
	if(sprite_exists(spr_locked))
		draw_sprite_stretched(spr_locked,0,x-100,y-100,200,200)
}
else
{
	if(sprite_exists(spr_unlocked))
		draw_sprite_stretched(spr_unlocked,0,x-100,y-100,200,200)
}

draw_set_valign(fa_left)
draw_set_halign(fa_center)
draw_set_font(Font_YoYo_15)

if(locked)
{
	draw_text(x,y+110,locked_display_name)
	draw_text(x,y+140,locked_description)
}
else
{
	draw_text(x,y+110,unlocked_display_name)
	draw_text(x,y+140,unlocked_description)
}

draw_text(x,y+170,flavor_text)
draw_text(x,y+200,is_hidden)
