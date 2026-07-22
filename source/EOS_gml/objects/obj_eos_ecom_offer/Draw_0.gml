
draw_text(x,y+65,data.title_text)// + string(available_for_purchase))
draw_text(x,y+95,string(data.current_price64/power(10,data.decimal_point)) + data.currency_code)

if(sprite_exists(spr))
{
	draw_set_alpha(selected?1.0:0.5)
	draw_sprite_stretched(spr,0,x-50,y-50,100,100)
	draw_set_alpha(1.0)
}
