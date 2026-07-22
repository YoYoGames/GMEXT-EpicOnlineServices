
selected = false

spr = noone

var _image_info_count = eos_ecom_get_offer_image_info_count(global.epic_account_id, data.id);
show_debug_message($"_image_info_count: {_image_info_count}")
for(var j = 0; j < _image_info_count; j++)
{
	var img_info = eos_ecom_copy_offer_image_info_by_index(global.epic_account_id, data.id, j)
	show_debug_message($"{j}: {img_info}")
	if(img_info.type == "Thumbnail")
		spr = sprite_add(img_info.url, 0, 0, 0, 0, 0)
}
