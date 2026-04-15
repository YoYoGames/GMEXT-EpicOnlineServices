
draw_set_valign(fa_center)
draw_set_halign(fa_left)

draw_rectangle_color(x,y-30,x+100*5,y+30,c_white,c_white,c_white,c_white,true)
draw_rectangle_color(x,y-30,x+porcent*5,y+30,color_current,color_current,color_current,color_current,false)

draw_text(x,y,filename + ": " + string(porcent) + "%")

