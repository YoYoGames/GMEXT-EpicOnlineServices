
switch(async_load[?"type"])
{
	case "EpicGames_Ecom_QueryOffers":
		
		if(async_load[?"status"] != EpicGames_Success)
			break
		
		var _array_of_offer_ids = []
		var _array_of_item_ids = []
		var pos = 0;
		for(var i = 0 ; i < EpicGames_Ecom_GetOfferCount(AccountID) ; i++)
		{
			var offer = EpicGames_Ecom_CopyOfferByIndex(AccountID,i)
			//show_debug_message(offer)
			
			if(offer.bAvailableForPurchase)
			{
				instance_create_depth(200+250*pos,200,0,Obj_EpicGames_Ecom_Offer,offer)
				pos++
			}
			
			array_push(_array_of_offer_ids,offer.Id)
			
			//show_debug_message("EpicGames_Ecom_GetOfferCount: " + string(EpicGames_Ecom_GetOfferCount(AccountID)))
			//show_debug_message("OfferItems: " + string(EpicGames_Ecom_GetOfferItemCount(AccountID,offer.Id)))
			for(var j = 0 ; j < EpicGames_Ecom_GetOfferItemCount(AccountID,offer.Id) ; j++)
			{
				var item = EpicGames_Ecom_CopyOfferItemByIndex(AccountID,offer.Id,j)
				show_debug_message(item)
				array_push(_array_of_item_ids,item.Id)
			}
			show_debug_message("-----------")
		}
		
		show_debug_message("Requesting: ")
		show_debug_message(_array_of_offer_ids)
		show_debug_message(_array_of_item_ids)
		
		EpicGames_Ecom_QueryOwnership(AccountID,_array_of_item_ids)
		EpicGames_Ecom_QueryEntitlements(AccountID,_array_of_item_ids,true)
		
	break
	
	case "EpicGames_Ecom_QueryOwnership":
		
		if(async_load[?"status"] != EpicGames_Success)
			break
		
	break
	
	case "EpicGames_Ecom_QueryEntitlements":
	
		if(async_load[?"status"] != EpicGames_Success)
			break
		
		//EpicGames_Ecom_QueryEntitlementToken(AccountID,_array_of_item_ids)
		show_debug_message("GetEntitlementsCount: " + string(EpicGames_Ecom_GetEntitlementsCount(AccountID)))
		for(var i = 0 ; i < EpicGames_Ecom_GetEntitlementsCount(AccountID) ; i++)
		{
			show_debug_message(EpicGames_Ecom_CopyEntitlementByIndex(AccountID,i))
		}
	
	break
	
	case "EpicGames_Ecom_Checkout":
		
		if(async_load[?"status"] != EpicGames_Success)
			break
		
		var _transaction_id = async_load[?"transaction_id"]
		var _entitlements_count = EpicGames_Ecom_Transaction_GetEntitlementsCountByIdTransaction(AccountID,_transaction_id)
		show_debug_message("Entitlements" + string(_entitlements_count))
		
		for(var i = 0 ; i < array_length(async_load[?"offer_ids"]); i++)
		{
			with(Obj_EpicGames_Ecom_Offer)
			if(async_load[?"offer_ids"][i] == Id)
			{
				show_debug_message(Id)//(offer)
				var title_offer = TitleText//offer.TitleText
				show_message_async(title_offer + " Bought")
			}
		}
		
		
		//[OPTIONAL]
		for(var i = 0 ; i < _entitlements_count ; i++)
		{
			show_debug_message(EpicGames_Ecom_Transaction_CopyEntitlementByIndexByIdTransaction(AccountID,_transaction_id,i))
			var _EntitlementId = EpicGames_Ecom_Transaction_CopyEntitlementByIndexByIdTransaction(AccountID,_transaction_id,i).EntitlementId
			EpicGames_Ecom_RedeemEntitlements(AccountID,[_EntitlementId])
		}
		
	break
	
	case "RedeemEntitlementsCallback":
	break
	
	case "":
	break
}

