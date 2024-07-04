
//bAvailableForPurchase
//CatalogNamespace
//CurrencyCode
//CurrentPrice64
//DecimalPoint
//DescriptionText
//DiscountPercentage
//EffectiveDateTimestamp
//Id
//LongDescriptionText
//OriginalPrice64
//PriceResult
//PurchaseLimit
//ReleaseDateTimestamp
//ServerIndex
//TitleText

selected = false

image_xscale = 0.2
image_yscale = 0.2

//show_debug_message("Count: " + string(EpicGames_Ecom_GetOfferImageInfoCount(AccountID,Id)))
			
for(var  j = 0 ; j < EpicGames_Ecom_GetOfferImageInfoCount(AccountID,Id) ; j++)
{
	var struct = EpicGames_Ecom_CopyOfferImageInfoByIndex(AccountID,Id,j)
	//{ Url : "", status_message : "", status : , Height : , Width : , Type : "OfferImageWide" }

	//OfferImageWide
	//OfferImageTall
	//Thumbnail//H: 1600, W: 1200
	//featuredMedia	
	if(struct.Type == "Thumbnail")
	{
		sprite_index = sprite_add(struct.Url,0,0,0,struct.Width/2,0)
	}

}

//show_debug_message("Count: " + string(EpicGames_Ecom_GetItemImageInfoCount(AccountID,offer.Id)))
