event_inherited();

eos_ecom_query_offers(global.epic_account_id, "", function(_data)
	{
		show_debug_message($"eos_ecom_query_offers: {_data}")
		if(_data.result_code != EpicResult.Success)
		{
			show_debug_message("Query offers failed: " + eos_api_result_to_string(_data.result_code))
			return
		}

		var _array_of_offer_ids = []
		var _array_of_item_ids = []
		var pos = 0
		
		var _offer_count = eos_ecom_get_offer_count(global.epic_account_id)
		show_debug_message($"_offer_count: {_offer_count}")
		for(var i = 0; i < _offer_count ; i++)
		{
			var offer = eos_ecom_copy_offer_by_index(global.epic_account_id, i)
			show_debug_message($"Offer {i}: {offer}")
			if(offer.available_for_purchase)
			{
				instance_create_depth(200 + 250*pos, 200, 0, obj_eos_ecom_offer, {data: offer})
				pos++
			}

			array_push(_array_of_offer_ids, offer.id)
			
			var _item_count = eos_ecom_get_offer_item_count(global.epic_account_id, offer.id)
			show_debug_message($"_item_count: {_item_count}")
			for(var j = 0; j < _item_count ; j++)
			{
				var item = eos_ecom_copy_offer_item_by_index(global.epic_account_id, offer.id, j)
				show_debug_message($"item {j}: {item}")
				array_push(_array_of_item_ids, item.id)
			}
		}

		show_debug_message("Offers: " + string(_array_of_offer_ids))
		show_debug_message("Items: " + string(_array_of_item_ids))

		var _query_ownership_callback = function(_ownership_data)
		{
			if(_ownership_data.result_code != EpicResult.Success)
			{
				show_debug_message("Query ownership failed")
			}
		}

		var _query_entitlements_callback = function(_entitlements_data)
		{
			if(_entitlements_data.result_code != EpicResult.Success)
			{
				show_debug_message("Query entitlements failed")
				return
			}

			show_debug_message("Entitlements count: " + string(eos_ecom_get_entitlements_count(global.epic_account_id)))
			for(var i = 0; i < eos_ecom_get_entitlements_count(global.epic_account_id); i++)
			{
				show_debug_message(eos_ecom_copy_entitlement_by_index(global.epic_account_id, i))
			}
		}

		eos_ecom_query_ownership(global.epic_account_id, _array_of_item_ids, "", _query_ownership_callback)
		eos_ecom_query_entitlements(global.epic_account_id, _array_of_item_ids, true, "", _query_entitlements_callback)
	})
