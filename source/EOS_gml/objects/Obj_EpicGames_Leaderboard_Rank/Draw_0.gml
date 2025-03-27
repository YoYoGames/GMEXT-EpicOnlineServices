
event_inherited()

draw_set_valign(fa_left)
draw_set_halign(fa_left)
draw_text(bbox_left,y,rank)
if(variable_instance_exists(id,"user_display_name"))
    draw_text(bbox_left+50,y,user_display_name)
draw_set_halign(fa_right)
draw_text(bbox_right-50,y,id.score)
