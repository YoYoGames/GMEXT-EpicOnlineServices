
var _array = []

with(obj_eos_ecom_offer)
{
	if(selected)
    	array_push(_array,offer_id)
}

eos_ecom_checkout(global.epic_account_id,_array)
