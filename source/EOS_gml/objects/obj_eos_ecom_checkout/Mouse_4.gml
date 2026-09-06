
var _array = []

with(obj_eos_ecom_offer)
{
	if(selected)
		array_push(_array, data.id)
}

if(array_length(_array) == 0)
{
	show_message_async("Please select offers to checkout")
	return
}

show_debug_message("eos_ecom_checkout")
show_debug_message({_array})
eos_ecom_checkout(global.epic_account_id, _array, "", function(_checkout_data)
{
	if(_checkout_data.result_code != EpicResult.Success)
	{
		show_debug_message("Checkout failed: " + eos_api_result_to_string(_checkout_data.result_code))
		return
	}

	var _transaction_id = _checkout_data.transaction_id

	// The entitlement accessors work off a transaction handle, not the id - copy the
	// transaction first, then release it once we're done reading from it.
	var _transaction_handle_id = eos_ecom_copy_transaction_by_id(global.epic_account_id, _transaction_id)
	if(_transaction_handle_id == 0)
	{
		show_debug_message($"copy_transaction_by_id failed for {_transaction_id}: " + eos_api_last_error())
		return
	}

	var _entitlements_count = eos_ecom_transaction_get_entitlements_count(_transaction_handle_id)
	show_debug_message("Checkout successful. Entitlements: " + string(_entitlements_count))

	for(var i = 0; i < _entitlements_count; i++)
	{
		var entitlement = eos_ecom_transaction_copy_entitlement_by_index(_transaction_handle_id, i)
		if(is_undefined(entitlement))
			continue

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

	eos_ecom_transaction_release(_transaction_handle_id)

	with(obj_eos_ecom_offer)
	{
		if(selected)
		{
			show_message_async(data.title_text + " Purchased!")
			selected = false
		}
	}
})
