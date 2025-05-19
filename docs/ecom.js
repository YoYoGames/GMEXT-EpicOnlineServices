// Functions

/**
 * @function eos_ecom_query_ownership
 * @desc **Epic Online Services Function:** [EOS_Ecom_QueryOwnership](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-query-ownership)
 * 
 * This function queries the ownership status for a given list of catalog item IDs defined with Epic Online Services.
 * This data will be cached for a limited time and retrieved again from the backend when necessary.
 * Depending on the number of catalog item IDs passed, the SDK splits the query into smaller batch requests to the backend and aggregates the result.
 * 
 * [[Note: If one of the request batches fails, no data is cached and the entire query is marked as failed.]]
 * 
 * @param {string} user The Epic Account ID of the local user whose ownership to query
 * @param {array} CatalogItemIds The array of Catalog Item IDs to check for ownership
 * @param {string} catalogNamespace Optional product namespace, if not the one specified during initialisation
 * 
 * @event social
 * @member {string} type `"eos_ecom_query_ownership"`
 * @member {real} identifier The asynchronous listener ID
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors 
 * @member {string} status_message A text representation of the status code
 * @member {string} account_id The Epic Account ID of the local user whose ownership was queried
 * @event_end
 * 
 * @function_end
 */
function eos_ecom_query_ownership(user, CatalogItemIds, catalogNamespace) {}


/**
 * @function eos_ecom_query_ownership_by_sandbox_ids
 * @desc **Epic Online Services Function:** [EOS_Ecom_QueryOwnershipBySandboxIds](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-query-ownership-by-sandbox-ids)
 * 
 * This function queries the ownership status of all catalog item IDs under the given list of Sandbox IDs defined with Epic Online Services.
 * This data will be cached for a limited time and retrieved again from the backend when necessary.
 * 
 * @param {string} user The Epic Account ID of the local user whose ownership to query.
 * @param {array} SandboxIds The array of Sandbox IDs to check for ownership.
 * 
 * @event social
 * @member {string} type `"eos_ecom_query_ownership_by_sandbox_ids"`
 * @member {real} identifier The asynchronous listener ID
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message A text representation of the status code
 * @member {string} account_id The Epic Account ID of the local user whose ownership was queried
 * @event_end
 * 
 * @function_end
 */
function eos_ecom_query_ownership_by_sandbox_ids(user, SandboxIds) {}


/**
 * @function eos_ecom_query_ownership_token
 * @desc **Epic Online Services Function:** [EOS_Ecom_QueryOwnershipToken](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-query-ownership-token)
 * 
 * This function queries the ownership status for a given list of catalog item IDs defined with Epic Online Services.
 * The data is returned via the ${event.social} in the form of a signed JWT that should be verified by an external backend server using a public key for authenticity.
 * 
 * @param {string} user The Epic Account ID of the local user whose ownership token you want to query
 * @param {array} CatalogItemIds The array of Catalog Item IDs to check for ownership, matching in number to the CatalogItemIdCount
 * 
 * @event social
 * @member {string} type `"eos_ecom_query_ownership_token"`
 * @member {real} identifier The asynchronous listener ID
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} account_id The Epic Account ID of the local user whose ownership token was queried
 * @member {string} ownership_token Ownership token containing details about the catalog items queried
 * @event_end
 *
 * @function_end
 */
function eos_ecom_query_ownership_token(user, CatalogItemIds) {}


/**
 * @function eos_ecom_query_entitlements
 * @desc **Epic Online Services Function:** [EOS_Ecom_QueryEntitlements](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-query-entitlements)
 * 
 * This function queries the entitlement information defined with Epic Online Services.
 * 
 * A set of entitlement names can be provided to filter the set of entitlements associated with the account.
 * This data will be cached for a limited time and retrieved again from the backend when necessary.
 * Depending on the number of entitlements passed, the SDK splits the query into smaller batch requests to the backend and aggregates the result.
 * 
 * [[Note: If one of the request batches fails, no data is cached and the entire query is marked as failed.]]
 * 
 * Use ${function.eos_ecom_copy_entitlement_by_index}, ${function.eos_ecom_copy_entitlement_by_name_and_index}, and ${function.eos_ecom_copy_entitlement_by_id} to get the entitlement details.
 * Use ${function.eos_ecom_get_entitlements_by_name_count} to retrieve the number of entitlements with a specific entitlement name.
 * 
 * @param {string} user The Epic Account ID of the local user whose entitlements you want to retrieve
 * @param {array} EntitlementNames An array of entitlement names that you want to check
 * @param {bool} bIncludeRedeemed If `true`, entitlements that have been redeemed will be included in the results
 * 
 * @event social
 * @member {string} type `"eos_ecom_query_entitlements`
 * @member {real} identifier The asynchronous listener ID
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} account_id The Epic Account ID of the local user whose entitlement was queried
 * @event_end
 * 
 * @function_end
 */
function eos_ecom_query_entitlements(user, EntitlementNames, bIncludeRedeemed) {}


/**
 * @function eos_ecom_query_entitlement_token
 * @desc **Epic Online Services Function:** [EOS_Ecom_QueryEntitlementToken](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-query-entitlement-token)
 * 
 * This function queries the entitlement verification status defined with Epic Online Services.
 * 
 * An optional set of entitlement names can be provided to filter the set of entitlements associated with the account.
 * The data is returned via the ${event.social} in the form of a signed JWT that should be verified by an external backend server using a public key for authenticity.
 * 
 * @param {string} user The Epic Account ID of the local user whose Entitlements you want to retrieve
 * @param {array} EntitlementNames An array of Entitlement Names that you want to check

 * @event social
 * @member {string} type `"eos_ecom_query_entitlement_token"`
 * @member {real} identifier The asynchronous listener ID
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message A text representation of the status code
 * @member {string} account_id The Epic Account ID of the local user whose entitlement was queried
 * @member {string} entitlement_token Entitlements token containing details about the catalog items queried
 * @event_end

 * @function_end
 */
function eos_ecom_query_entitlement_token(user, EntitlementNames) {}


/**
 * @function eos_ecom_query_offers
 * @desc **Epic Online Services Function:** [EOS_Ecom_QueryOffers](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-query-offers)
 * 
 * This function queries for a list of catalog offers defined with Epic Online Services.
 * This data will be cached for a limited time and retrieved again from the backend when necessary.
 * 
 * @param {string} user The Epic Account ID of the local user whose offer to query
 * @param {string} OverrideCatalogNamespace If not provided then the SandboxId is used as the catalog namespace

 * @event social
 * @member {string} type `"eos_ecom_query_offers"`
 * @member {real} identifier The asynchronous listener ID
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} account_id The Epic Account ID of the local user whose offer was queried; needed for localisation of Catalog Item (Item) description text and pricing information
 * @event_end

 * @function_end
 */
function eos_ecom_query_offers(user, OverrideCatalogNamespace) {}


/**
 * @function eos_ecom_checkout
 * @desc **Epic Online Services Function:** [EOS_Ecom_Checkout](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-checkout)
 * 
 * This function initiates the purchase flow for a set of offers. The ${event.social} is triggered after the purchase flow.
 * 
 * On success, the set of entitlements that were unlocked will be cached.
 * On success, a Transaction ID will be returned. The Transaction ID can be used with the `eos_ecom_transaction_*` functions to retrieve the entitlements rewarded by the purchase.
 * 
 * @param {string} user The Epic Account ID of the local user who is making the purchase
 * @param {array[string]} Entries An array of strings, each containing the details of a single offer
 * @param {string} OverrideCatalogNamespace The catalog namespace will be the current Sandbox ID, unless overridden by this field
 *
 * @event social
 * @member {string} type `"eos_ecom_checkout"`
 * @member {real} identifier The asynchronous listener ID
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message A text representation of the status code
 * @member {string} account_id The Epic Account ID of the user who initiated the purchase
 * @member {string} transaction_id The transaction ID
 * @member {array[string]} offer_ids An array of offer IDs
 * @event_end
 * 
 * @function_end
 */
function eos_ecom_checkout(user, Entries, OverrideCatalogNamespace) {}


/**
 * @function eos_ecom_redeem_entitlements
 * @desc **Epic Online Services Function:** [EOS_Ecom_RedeemEntitlements](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-redeem-entitlements)
 * 
 * This function requests that the provided entitlement be marked redeemed. This will cause that entitlement to no longer be returned from ${function.eos_ecom_query_entitlements} unless the `bIncludeRedeemed` request flag is set to `true`.
 * 
 * @param {string} user The Epic Account ID of the user who is redeeming Entitlements
 * @param {array} EntitlementIds The array of Entitlements to redeem
 * 
 * @event social
 * @member {string} type `"eos_ecom_redeem_entitlements"`
 * @member {real} identifier The asynchronous listener ID
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} account_id The Epic Account ID of the user who has redeemed entitlements
 * @member {real} redeemed_entitlement_ids_count The number of redeemed entitlements
 * @event_end

 * @function_end
 */
function eos_ecom_redeem_entitlements(user, EntitlementIds) {}


/**
 * @function eos_ecom_get_last_redeemed_entitlements_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetLastRedeemedEntitlementsCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-get-last-redeemed-entitlements-count)
 * 
 * This function returns the number of entitlements that were redeemed during the last ${function.eos_ecom_redeem_entitlements} call.
 * 
 * @param {string} user The Epic Account ID of the local user for who to retrieve the last redeemed entitlements count
 * @returns {real}
 * 
 * @function_end
 */
function eos_ecom_get_last_redeemed_entitlements_count(user) {}


/**
 * @function eos_ecom_copy_last_redeemed_entitlement_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyLastRedeemedEntitlementByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-copy-last-redeemed-entitlement-by-index)
 * 
 * This function fetches a redeemed entitlement ID from a given index.
 * Only entitlements that were redeemed during the last ${function.eos_ecom_redeem_entitlements} call can be copied.
 * 
 * @param {string} user The Epic Account ID of the local user whose last redeemed entitlement ID is being copied
 * @param {real} RedeemedEntitlementIndex Index of the last redeemed entitlement ID to retrieve from the cache
 * @returns {string}
 * @function_end
 */
function eos_ecom_copy_last_redeemed_entitlement_by_index(user, RedeemedEntitlementIndex) {}


/**
 * @function eos_ecom_get_entitlements_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetEntitlementsCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-get-entitlements-count)
 * 
 * This function returns the number of entitlements that are cached for a given local user.
 * 
 * @param {string} user The Epic Account ID of the local user for which to retrieve the entitlement count
 * @returns {real}
 * 
 * @function_end
 */
function eos_ecom_get_entitlements_count(user) {}


/**
 * @function eos_ecom_get_entitlements_by_name_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetEntitlementsByNameCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-get-entitlements-by-name-count)
 * 
 * This function returns the number of entitlements with the given entitlement name that are cached for a given local user.
 * 
 * @param {string} user The Epic Account ID of the local user for which to retrieve the entitlement count
 * @param {string} entitlementName Name of the entitlement to count in the cache
 * @returns {real}
 * 
 * @function_end
 */
function eos_ecom_get_entitlements_by_name_count(user, entitlementName) {}


/**
 * @struct Entitlement
 * @desc  **Epic Online Services Struct:** [EOS_Ecom_Entitlement](https://dev.epicgames.com/docs/api-ref/structs/eos-ecom-entitlement)
 * 
 * This struct contains information about a single entitlement associated with an account.
 * 
 * [[Note: `status` and `status_message` will always be present in the struct, all other variables are only present on success (i.e. when `status` equals `EOS_SUCCESS`).]]
 * 
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {boolean} Redeemed If `true` then the catalog has this entitlement marked as redeemed
 * @member {string} CatalogItemId ID of the item associated with the offer which granted this entitlement
 * @member {int64} EndTimestamp If not -1 then this is a POSIX timestamp that this entitlement will end
 * @member {string} EntitlementId ID of the entitlement owned by an account
 * @member {string} EntitlementName Name of the entitlement
 * @member {real} ServerIndex If queried using pagination then `ServerIndex` represents the index of the entitlement as it exists on the server. If not queried using pagination then `ServerIndex` will be -1.
 * @struct_end
 */


/**
 * @function eos_ecom_copy_entitlement_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyEntitlementByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-copy-entitlement-by-index)
 * 
 * This function fetches an entitlement from a given index.
 * 
 * @param {string} user The Epic Account ID of the local user whose entitlement is being copied
 * @param {real} index Index of the entitlement to retrieve from the cache
 * @returns {struct.Entitlement}
 * 
 * @function_end
 */
function eos_ecom_copy_entitlement_by_index(user, index) {}


/**
 * @function eos_ecom_copy_entitlement_by_name_and_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyEntitlementByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-copy-entitlement-by-name-and-index)
 * 
 * This function fetches a single entitlement with a given Entitlement Name. The Index is used to access individual entitlements among those with the same Entitlement Name. The Index can be a value from 0 to one less than the result from ${function.eos_ecom_get_entitlements_by_name_count}.
 * 
 * @param {string} user The Epic Account ID of the local user whose entitlement is being copied
 * @param {string} EntitlementName Name of the entitlement to retrieve from the cache
 * @param {real} Index Index of the entitlement within the named set to retrieve from the cache
 * @returns {struct.Entitlement}
 * 
 * @function_end
 */
function eos_ecom_copy_entitlement_by_name_and_index(user, EntitlementName, Index) {}

/**
 * @function eos_ecom_copy_entitlement_by_id
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyEntitlementById](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-copy-entitlement-by-id)
 * 
 * This function fetches the entitlement with the given ID.
 * 
 * @param {string} user The Epic Account ID of the local user whose entitlement is being copied
 * @param {string} EntitlementName ID of the entitlement to retrieve from the cache
 * @returns {struct.Entitlement}
 *
 * @function_end
 */
function eos_ecom_copy_entitlement_by_id(user, EntitlementName) {}


/**
 * @function eos_ecom_get_offer_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetOfferCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-get-offer-count)
 * 
 * This function returns the number of offers that are cached for a given local user.
 * 
 * @param {string} user The Epic Account ID of the local user whose offers are being accessed
 * @returns {real}
 * 
 * @function_end
 */
function eos_ecom_get_offer_count(user) {}

/**
 * @struct CatalogOffer
 * @desc **Epic Online Services Struct:** [EOS_Ecom_CatalogOffer](https://dev.epicgames.com/docs/api-ref/structs/eos-ecom-catalog-offer)
 * 
 * This struct contains information about a single offer within the catalog.
 * 
 * Prices are stored in the lowest denomination for the associated currency. If CurrencyCode is "USD" then a price of 299 represents "$2.99".
 * 
 * [[Note: `status` and `status_message` will always be present in the struct, all other variables are only present on success (i.e. when `status` equals `EOS_SUCCESS`).]]
 * 
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {boolean} bAvailableForPurchase True if the user can purchase this offer.
 * @member {string} CatalogNamespace Product namespace in which this offer exists
 * @member {string} CurrencyCode The Currency Code for this offer
 * @member {int64} CurrentPrice64 The current price including discounts of this offer as a 64-bit number.
 * @member {real} DecimalPoint The decimal point for the provided price. For example, DecimalPoint '2' and CurrentPrice64 '12345' would be '123.45'.
 * @member {string} DescriptionText Localised UTF-8 description of this offer
 * @member {real} DiscountPercentage A value from 0 to 100 define the percentage of the OrignalPrice that the CurrentPrice represents
 * @member {int64} EffectiveDateTimestamp Timestamp indicating the effective date of the offer. Can be ignored if set to -1.
 * @member {real} Id The ID of this offer
 * @member {string} LongDescriptionText Localised UTF-8 long description of this offer
 * @member {int64} OriginalPrice64 The original price of this offer as a 64-bit number
 * @member {constant.eos_result} PriceResult If this value is `EOS_SUCCESS` then `OriginalPrice64`, `CurrentPrice64`, and `DiscountPercentage` contain valid data. Otherwise, this value represents the error that occurred on the price query.
 * @member {real} PurchaseLimit The maximum number of times that the offer can be purchased. A negative value implies there is no limit.
 * @member {int64} ReleaseDateTimestamp Timestamp indicating when the time when the offer was released. Can be ignored if set to -1.
 * @member {real} ServerIndex The index of this offer as it exists on the server. This is useful for understanding pagination data.
 * @member {string} TitleText Localised UTF-8 title of this offer
 * @struct_end
 */


/**
 * @function eos_ecom_copy_offer_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyOfferByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-copy-offer-by-index)
 * 
 * This function fetches an offer from a given index. The pricing and text are localised to the provided account.
 * 
 * @param {string} user The Epic Account ID of the local user whose offer is being copied
 * @param {real} OfferIndex The index of the offer to get.
 * @returns {struct.CatalogOffer}
 * 
 * @function_end
 */
function eos_ecom_copy_offer_by_index(user, OfferIndex) {}


/**
 * @function eos_ecom_copy_offer_by_id
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyOfferById](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-copy-offer-by-id)
 * 
 * This function fetches an offer with a given ID. The pricing and text are localised to the provided account.
 * 
 * @param {string} user The Epic Account ID of the local user whose offer is being copied
 * @param {string} OfferId The ID of the offer to get.
 * @returns {struct.CatalogOffer}
 * 
 * @function_end
 */
function eos_ecom_copy_offer_by_id(user, OfferId) {}

/**
 * @function eos_ecom_get_offer_item_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetOfferItemCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-get-offer-item-count)
 * 
 * This function fetches the number of items that are associated with a given cached offer for a local user.
 * 
 * @param {string} user The Epic Account ID of the local user who made the initial request for the Catalog Offer through ${function.eos_ecom_query_offers}
 * @param {string} OfferId An ID that corresponds to a cached Catalog Offer (retrieved by ${function.eos_ecom_copy_offer_by_index})
 * @returns {real}
 * @function_end
 */
function eos_ecom_get_offer_item_count(user, OfferId) {}


/**
 * @struct CatalogItem
 * @desc  **Epic Online Services Struct:** [EOS_Ecom_CatalogItem](https://dev.epicgames.com/docs/api-ref/structs/eos-ecom-catalog-item)
 * 
 * This struct contains information about a single item within the catalog.
 * 
 * [[Note: `status` and `status_message` will always be present in the struct, all other variables are only present on success (i.e. when `status` equals `EOS_SUCCESS`).]]
 * 
 * @member {real} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {boolean} bAvailableForPurchase
 * @member {string} CatalogNamespace Product namespace in which this item exists
 * @member {string} DescriptionText Localised UTF-8 description of this item
 * @member {string} DeveloperText Localised UTF-8 developer of this item
 * @member {int64} EntitlementEndTimestamp If not -1 then this is the POSIX timestamp that the entitlement will end
 * @member {string} EntitlementName The entitlement name associated with this item
 * @member {real} Id The ID of this item
 * @member {real} ItemType The type of item as defined in the catalog
 * @member {string} LongDescriptionText Localised UTF-8 long description of this item
 * @member {string} TechnicalDetailsText Localised UTF-8 technical details of this item 
 * @member {string} TitleText Localised UTF-8 title of this item
 * @struct_end
 */


/**
 * @function eos_ecom_copy_offer_item_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyOfferItemByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-copy-offer-item-by-index)
 * 
 * This function fetches an item from a given index.
 * 
 * @param {string} user The Epic Account ID of the local user whose item is being copied
 * @param {string} OfferId The ID of the offer to get the items for.
 * @param {real} ItemIndex The index of the item to get
 * @returns {struct.CatalogItem}
 * 
 * @function_end
 */
function eos_ecom_copy_offer_item_by_index(user, OfferId, ItemIndex) {}


/**
 * @function eos_ecom_copy_item_by_id
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyItemById](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-copy-item-by-id)
 * 
 * This function fetches an item with a given ID.
 * 
 * @param {string} user The Epic Account ID of the local user whose item is being copied
 * @param {string} ItemId The ID of the item to get
 * @returns {struct.CatalogItem}
 * 
 * @function_end
 */
function eos_ecom_copy_item_by_id(user, ItemId) {}

/**
 * @function eos_ecom_get_offer_image_info_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetOfferImageInfoCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-get-offer-image-info-count)
 * 
 * This function returns the number of images that are associated with a given cached offer for a local user.
 * 
 * @param {string} user The Epic Account ID of the local user whose offer image is being accessed.
 * @param {string} OfferId The ID of the offer to get the images for.
 * @returns {real}
 * 
 * @function_end
 */
function eos_ecom_get_offer_image_info_count(user, OfferId) {}


/**
 * @struct KeyImageInfo
 * @desc  **Epic Online Services Struct:** [EOS_Ecom_KeyImageInfo](https://dev.epicgames.com/docs/api-ref/structs/eos-ecom-key-image-info)
 * 
 * This struct contains information about a key image used by the catalog.
 * 
 * A Key Image is defined within Dev Portal and is associated with a Catalog Item. It is intended to be used to provide imagery for an in-game store.
 * 
 * [[Note: `status` and `status_message` will always be present in the struct, all other variables are only present on success (i.e. when `status` equals `EOS_SUCCESS`).]]
 * 
 * @member {real} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} Height The expected height in pixels of the image
 * @member {real} Width The expected width in pixels of the image
 * @member {string} Type Describes the usage of the image (ex home_thumbnail)
 * @member {string} Url The URL of the image
 * @struct_end
 */


/**
 * @function eos_ecom_copy_offer_image_info_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyOfferByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-copy-offer-image-info-by-index)
 * 
 * This function fetches an image from a given index.
 * 
 * @param {string} user The Epic Account ID of the local user whose offer image is being copied.
 * @param {string} OfferId The ID of the offer to get the images for.
 * @param {real} ImageInfoIndex The index of the image to get.
 * @returns {struct.KeyImageInfo}
 * 
 * @function_end
 */
function eos_ecom_copy_offer_image_info_by_index(user, OfferId, ImageInfoIndex) {}


/**
 * @function eos_ecom_get_item_image_info_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetItemImageInfoCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-get-item-image-info-count)
 * 
 * This function returns the number of images that are associated with a given cached item for a local user.
 * 
 * @param {string} user The Epic Account ID of the local user whose item image is being accessed
 * @param {string} ItemId The ID of the item to get the images for.
 * @returns {real}
 * 
 * @function_end
 */
function eos_ecom_get_item_image_info_count(user, ItemId) {}


/**
 * @function eos_ecom_copy_item_image_info_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyItemImageInfoByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-copy-item-image-info-by-index)
 * 
 * This function fetches an image from a given index.
 * 
 * @param {string} user The Epic Account ID of the local user whose item image is being copied
 * @param {string} ItemId The ID of the item to get the images for
 * @param {real} ImageInfoIndex The index of the image to get
 * @returns {struct.KeyImageInfo}
 * 
 * @function_end
 */
function eos_ecom_copy_item_image_info_by_index(user, ItemId, ImageInfoIndex) {}


/**
 * @function eos_ecom_get_item_release_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetItemReleaseCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-get-item-release-count)
 * 
 * This function returns the number of releases that are associated with a given cached item for a local user.
 * 
 * @param {string} user The Epic Account ID of the local user whose item release is being accessed
 * @param {string} ItemId The ID of the item to get the releases for
 * @returns {real}
 * 
 * @function_end
 */
function eos_ecom_get_item_release_count(user, ItemId) {}


/**
 * @struct CatalogRelease
 * @desc **Epic Online Services Function:** [EOS_Ecom_CatalogRelease](https://dev.epicgames.com/docs/api-ref/structs/eos-ecom-catalog-release)
 * 
 * This struct contains information about a single release within the catalog.
 * 
 * [[Note: `status` and `status_message` will always be present in the struct, all other variables are only present on success (i.e. when `status` equals `EOS_SUCCESS`).]]
 * 
 * @member {real} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {array[string]} CompatibleAppIds An array of compatible App IDs
 * @member {array[string]} CompatiblePlatforms An array of compatible platforms 
 * @member {string} ReleaseNote Release note for compatible versions
 * @struct_end
 */


/**
 * @function eos_ecom_copy_item_release_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyItemReleaseByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-copy-item-release-by-index)
 * 
 * This function fetches a release from a given index.
 * 
 * @param {string} user The Epic Account ID of the local user whose item release is being copied
 * @param {string} ItemId The ID of the item to get the releases for
 * @param {real} ReleaseIndex The index of the release to get
 * @returns {struct.CatalogRelease}
 * 
 * @function_end
 */
function eos_ecom_copy_item_release_by_index(user, ItemId, ReleaseIndex) {}


/**
 * @function eos_ecom_get_transaction_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetTransactionCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-get-transaction-count)
 * 
 * This function returns the number of transactions that are cached for a given local user.
 * 
 * @param {string} user The Epic Account ID of the local user whose transaction count to get
 * @returns {real}
 * 
 * @function_end
 */
function eos_ecom_get_transaction_count(user) {}


/**
 * @function eos_ecom_transaction_get_transaction_id_by_index_transaction()
 * @desc **Epic Online Services Function:** [EOS_Ecom_Transaction_GetTransactionId](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-transaction-get-transaction-id)
 * 
 * This function gets the ID of the transaction with the given index.
 * 
 * @param {string} user The Epic Account ID of the local user who is associated with the transaction
 * @param {real} index The index of the transaction to get
 * @returns {string}
 * 
 * @function_end
 */

/**
 * @function eos_ecom_transaction_get_entitlements_count_by_index_transaction()
 * @desc **Epic Online Services Function:** [EOS_Ecom_Transaction_GetEntitlementsCount](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-get-entitlements-count)
 * 
 * This function returns the number of entitlements that are part of this transaction.
 * 
 * @param {string} user The Epic Account ID of the local user who is associated with the transaction
 * @param {real} index The index of the transaction to get
 * 
 * @returns {real}
 * 
 * @function_end
 */

/**
 * @function eos_ecom_transaction_get_entitlements_count_by_id_transaction
 * @desc **Epic Online Services Function:** [EOS_Ecom_Transaction_GetEntitlementsCount](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-get-entitlements-count)
 * 
 * This function returns the number of entitlements that are part of this transaction.
 * 
 * @param {string} user The Epic Account ID of the local user who is associated with the transaction
 * @param {string} TransactionId The ID of the transaction to get
 * 
 * @returns {real}
 * 
 * @function_end
 */

/**
 * @function eos_ecom_transaction_copy_entitlement_by_index_by_index_transaction
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyEntitlementByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-copy-entitlement-by-index)
 * 
 * This function fetches an entitlement from a given index.
 * 
 * @param {string} user The Epic Account ID of the local user who is associated with the transaction
 * @param {real} TransactionIndex The index of the transaction to get
 * @param {real} EntitlementIndex The index of the entitlement to get
 * @returns {struct.Entitlement}
 * 
 * @function_end
 */
function eos_ecom_transaction_copy_entitlement_by_index_by_index_transaction(user, TransactionIndex, EntitlementIndex) {}


/**
 * @function eos_ecom_transaction_copy_entitlement_by_index_by_id_transaction
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyEntitlementById](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-ecom-copy-entitlement-by-id)
 * 
 * This function fetches an entitlement from a given index.
 * 
 * @param {string} user The Epic Account ID of the local user who is associated with the transaction
 * @param {string} TransactionId The ID of the transaction to get
 * @param {real} EntitlementIndex The index of the entitlement to get
 * @returns {struct.Entitlement}
 * 
 * @function_end
 */
function eos_ecom_transaction_copy_entitlement_by_index_by_id_transaction(user, TransactionId, EntitlementIndex) {}


/**
 * @module ecom
 * @title Ecom
 * @desc **Epic Online Services Interface:** [Ecom](https://dev.epicgames.com/docs/api-ref/interfaces/ecom)
 * 
 * The Ecom module gives developers using Epic Online Services the ability to interact with the Epic Games Store. With this interface, you can manage products ranging from full games and downloadable content (DLC) to virtual goods and in-game currency. This includes making offers, completing purchase transactions, verifying ownership, and redeeming purchased items.
 * 
 * @section_func Functions
 * @desc These are the functions of the Ecom module: 
 * @ref eos_ecom_query_ownership
 * @ref eos_ecom_query_ownership_by_sandbox_ids
 * @ref eos_ecom_query_ownership_token
 * @ref eos_ecom_query_entitlements
 * @ref eos_ecom_query_entitlement_token
 * @ref eos_ecom_query_offers
 * @ref eos_ecom_checkout
 * @ref eos_ecom_redeem_entitlements
 * @ref eos_ecom_get_last_redeemed_entitlements_count
 * @ref eos_ecom_copy_last_redeemed_entitlement_by_index
 * @ref eos_ecom_get_entitlements_count
 * @ref eos_ecom_get_entitlements_by_name_count
 * @ref eos_ecom_copy_entitlement_by_index
 * @ref eos_ecom_copy_entitlement_by_name_and_index
 * @ref eos_ecom_copy_entitlement_by_id
 * @ref eos_ecom_get_offer_count
 * @ref eos_ecom_copy_offer_by_index
 * @ref eos_ecom_copy_offer_by_id
 * @ref eos_ecom_get_offer_item_count
 * @ref eos_ecom_copy_offer_item_by_index
 * @ref eos_ecom_copy_item_by_id
 * @ref eos_ecom_get_offer_image_info_count
 * @ref eos_ecom_copy_offer_image_info_by_index
 * @ref eos_ecom_get_item_image_info_count
 * @ref eos_ecom_copy_item_image_info_by_index
 * @ref eos_ecom_get_item_release_count
 * @ref eos_ecom_copy_item_release_by_index
 * @ref eos_ecom_get_transaction_count
 * @ref eos_ecom_transaction_get_transaction_id_by_index_transaction
 * @ref eos_ecom_transaction_get_entitlements_count_by_index_transaction
 * @ref eos_ecom_transaction_get_entitlements_count_by_id_transaction
 * @ref eos_ecom_transaction_copy_entitlement_by_index_by_index_transaction
 * @ref eos_ecom_transaction_copy_entitlement_by_index_by_id_transaction
 * @section_end
 * 
 * @section_struct Structs
 * @desc These are the structs in the Ecom module:
 * @ref Entitlement
 * @ref CatalogOffer
 * @ref CatalogItem
 * @ref KeyImageInfo
 * @ref CatalogRelease
 * @section_end
 * 
 * @module_end
 */
