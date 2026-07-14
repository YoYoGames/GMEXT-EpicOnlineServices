
selected = false

image_xscale = 0.2
image_yscale = 0.2

for(var j = 0; j < eos_ecom_get_offer_image_info_count(global.epic_account_id, id); j++)
{
	var img_info = eos_ecom_copy_offer_image_info_by_index(global.epic_account_id, id, j)
	if(img_info.type == "thumbnail")
	{
		sprite_index = sprite_add(img_info.url, 0, 0, 0, img_info.width/2, 0)
	}
}
