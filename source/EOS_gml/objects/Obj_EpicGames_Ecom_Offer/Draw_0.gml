
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

draw_text(x,bbox_top-30,TitleText)// + string(bAvailableForPurchase))
draw_text(x,bbox_bottom+30,string(CurrentPrice64/power(10,DecimalPoint)) + CurrencyCode)

if(sprite_exists(sprite_index))
	draw_self()
