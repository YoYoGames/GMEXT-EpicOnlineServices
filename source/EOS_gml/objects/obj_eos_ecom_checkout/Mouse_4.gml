
var _array = []

with(obj_eos_ecom_offer)
{
	if(selected)
		array_push(_array, id)
}

if(array_length(_array) == 0)
{
	show_message_async("Please select offers to checkout")
	return
}

eos_ecom_checkout(global.epic_account_id, _array, "", function(_checkout_data)
{
	if(_checkout_data.result_code != EpicResult.Success)
	{
		show_debug_message("Checkout failed: " + eos_api_result_to_string(_checkout_data.result_code))
		return
	}

	var _transaction_id = _checkout_data.transaction_id
	var _entitlements_count = eos_ecom_transaction_get_entitlements_count_by_id_transaction(global.epic_account_id, _transaction_id)
	show_debug_message("Checkout successful. Entitlements: " + string(_entitlements_count))

	for(var i = 0; i < _entitlements_count; i++)
	{
		var entitlement = eos_ecom_transaction_copy_entitlement_by_index_by_id_transaction(global.epic_account_id, _transaction_id, i)
		show_debug_message(entitlement)

		eos_ecom_redeem_entitlements(global.epic_account_id, [entitlement.entitlement_id], function(_redeem_data)
		{
			if(_redeem_data.result_code != EpicResult.Success)
			{
				show_debug_message("Redeem failed")
				return
			}
			show_debug_message("Entitlement redeemed")
		})
	}

	with(obj_eos_ecom_offer)
	{
		if(selected)
		{
			show_message_async(title_text + " Purchased!")
			selected = false
		}
	}
})
