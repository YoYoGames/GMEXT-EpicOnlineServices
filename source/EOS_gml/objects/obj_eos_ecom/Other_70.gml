
switch(async_load[? "type"])
{
	case "eos_ecom_query_offers":
		
		if(async_load[? "status"] != EpicResult.Success)
			break
		
		var _array_of_offer_ids = []
		var _array_of_item_ids = []
		var pos = 0;
		for(var i = 0 ; i < eos_ecom_get_offer_count(global.epic_account_id) ; i++)
		{
			var offer = eos_ecom_copy_offer_by_index(global.epic_account_id,i)
			//show_debug_message(offer)
			
			if(offer.available_for_purchase)
			{
				instance_create_depth(200+250*pos,200,0,obj_eos_ecom_offer,offer)
				pos++
			}
			
			array_push(_array_of_offer_ids,offer.offer_id)
			
			//show_debug_message("eos_ecom_get_offer_count: " + string(eos_ecom_get_offer_count(global.epic_account_id)))
			//show_debug_message("OfferItems: " + string(eos_ecom_get_offer_item_count(global.epic_account_id,offer.offer_id)))
			for(var j = 0 ; j < eos_ecom_get_offer_item_count(global.epic_account_id,offer.offer_id) ; j++)
			{
				var item = eos_ecom_copy_offer_item_by_index(global.epic_account_id,offer.offer_id,j)
				show_debug_message(item)
				array_push(_array_of_item_ids,item.offer_id)
			}
			show_debug_message("-----------")
		}
		
		show_debug_message("Requesting: ")
		show_debug_message(_array_of_offer_ids)
		show_debug_message(_array_of_item_ids)
		
		eos_ecom_query_ownership(global.epic_account_id,_array_of_item_ids)
		eos_ecom_query_entitlements(global.epic_account_id,_array_of_item_ids,true)
		
	break
	
	case "eos_ecom_query_ownership":
		
		if(async_load[? "status"] != EpicResult.Success)
			break
		
	break
	
	case "eos_ecom_query_entitlements":
	
		if(async_load[? "status"] != EpicResult.Success)
			break
		
		//eos_ecom_query_entitlement_token(global.epic_account_id,_array_of_item_ids)
		show_debug_message("GetEntitlementsCount: " + string(eos_ecom_get_entitlements_count(global.epic_account_id)))
		for(var i = 0 ; i < eos_ecom_get_entitlements_count(global.epic_account_id) ; i++)
		{
			show_debug_message(eos_ecom_copy_entitlement_by_index(global.epic_account_id,i))
		}
	
	break
	
	case "eos_ecom_checkout":
		
		if(async_load[? "status"] != EpicResult.Success)
			break
		
		var _transaction_id = async_load[? "transaction_id"]
		var _entitlements_count = eos_ecom_transaction_get_entitlements_count_by_id_transaction(global.epic_account_id,_transaction_id)
		show_debug_message("Entitlements" + string(_entitlements_count))
		
		for(var i = 0 ; i < array_length(async_load[? "offer_ids"]); i++)
		{
			with(obj_eos_ecom_offer)
			if(async_load[? "offer_ids"][i] == offer_id)
			{
				show_debug_message(offer_id)//(offer)
				var title_offer = title_text//offer.TitleText
				show_message_async(title_offer + " Bought")
			}
		}
		
		
		//[OPTIONAL]
		for(var i = 0 ; i < _entitlements_count ; i++)
		{
			show_debug_message(eos_ecom_transaction_copy_entitlement_by_index_by_id_transaction(global.epic_account_id,_transaction_id,i))
			var _EntitlementId = eos_ecom_transaction_copy_entitlement_by_index_by_id_transaction(global.epic_account_id,_transaction_id,i).entitlement_id
			eos_ecom_redeem_entitlements(global.epic_account_id,[_EntitlementId])
		}
		
	break
	
	case "RedeemEntitlementsCallback":
	break
	
	case "":
	break
}

