
selected = false

image_xscale = 0.2
image_yscale = 0.2

//show_debug_message("Count: " + string(eos_ecom_get_offer_image_info_count(AccountID,Id)))

for(var  j = 0 ; j < eos_ecom_get_offer_image_info_count(AccountID,offer_id) ; j++)
{
	var struct = eos_ecom_copy_offer_image_info_by_index(AccountID,offer_id,j)
	if(struct.Type == "thumbnail")
	{
		sprite_index = sprite_add(struct.url,0,0,0,struct.width/2,0)
	}

}

//show_debug_message("Count: " + string(eos_ecom_get_item_image_info_count(AccountID,offer.offer_id)))
