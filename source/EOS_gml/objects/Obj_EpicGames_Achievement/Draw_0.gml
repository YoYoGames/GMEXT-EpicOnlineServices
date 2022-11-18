
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
draw_set_font(Font_Yoyo_20)

if(locked)
{
	draw_text(x,y+110,LockedDisplayName)
	draw_text(x,y+140,LockedDescription)
}
else
{
	draw_text(x,y+110,UnlockedDisplayName)
	draw_text(x,y+140,UnlockedDescription)
}

draw_text(x,y+170,FlavorText)
draw_text(x,y+200,bIsHidden)
