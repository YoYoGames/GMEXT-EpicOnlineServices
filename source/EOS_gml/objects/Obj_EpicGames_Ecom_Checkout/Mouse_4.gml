
var _array = []

with(Obj_EpicGames_Ecom_Offer)
{
	if(selected)
    	array_push(_array,offer_id)
}

eos_ecom_checkout(AccountID,_array)
