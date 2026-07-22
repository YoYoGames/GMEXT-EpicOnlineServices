// Functions

/**
 * @function eos_ecom_query_ownership
 * @desc **Epic Online Services Function:** [EOS_Ecom_QueryOwnership](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-query-ownership)
 *
 * Queries the ownership status for a list of catalog item IDs defined with Epic Online Services. The
 * result is cached locally — read it back with ${function.eos_ecom_get_item_ownership_count} and
 * ${function.eos_ecom_copy_item_ownership_at_index} once the callback fires with success. A fresh call
 * to this function replaces the previously cached result for `local_user_id`.
 *
 * [[Warning: You should only use this function for startup checks — use Auth or Connect events to more
 * reliably determine when to query for ownership changes.]]
 *
 * @param {String} local_user_id The Epic Account ID of the local user whose ownership is being queried.
 * @param {Array[String]} catalog_item_ids The catalog item IDs to query.
 * @param {String} catalog_namespace The product namespace to use, or an empty string `""` to use the
 * configured default namespace.
 * @param {Function} [callback] Called once the query completes.
 *
 * @event callback
 * @desc Fires once with the query result.
 * @member {Struct.EpicEcomQueryOwnershipCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_ecom_query_ownership(local_user_id, ["catalog_item_1", "catalog_item_2"], "", function(_result)
 * {
 *     if (_result.status == EpicResult.Success)
 *     {
 *         var _count = eos_ecom_get_item_ownership_count(local_user_id);
 *         for (var i = 0; i < _count; i++)
 *         {
 *             var _entry = eos_ecom_copy_item_ownership_at_index(local_user_id, i);
 *             show_debug_message($"{_entry.id}: {_entry.ownership_status}");
 *         }
 *     }
 * });
 * ```
 * The above code queries ownership for two catalog items and lists the cached result once resolved.
 * @function_end
 */

/**
 * @function eos_ecom_query_ownership_by_sandbox_ids
 * @desc **Epic Online Services Function:** [EOS_Ecom_QueryOwnershipBySandboxIds](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-query-ownership-by-sandbox-ids)
 *
 * Queries the ownership status of catalog items across a set of sandboxes, for the currently logged in
 * user. Unlike ${function.eos_ecom_query_ownership}, this can be queried using an ${function.eos_connect_login}
 * logged in user, and does not require an Epic Account. The result is cached locally — read it back with
 * ${function.eos_ecom_get_sandbox_ownership_count} and ${function.eos_ecom_copy_sandbox_ownership_at_index}.
 *
 * @param {String} local_user_id The Product User ID of the local user whose ownership is being queried.
 * @param {Array[String]} sandbox_ids The sandbox IDs to query ownership within.
 * @param {Function} [callback] Called once the query completes.
 *
 * @event callback
 * @desc Fires once with the query result.
 * @member {Struct.EpicEcomQueryOwnershipBySandboxIdsCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_ecom_query_ownership_token
 * @desc **Epic Online Services Function:** [EOS_Ecom_QueryOwnershipToken](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-query-ownership-token)
 *
 * Retrieves an ownership proof token for a list of catalog item IDs. This token can be verified by an
 * external service (such as a backend server) to confirm ownership without trusting the client.
 *
 * @param {String} local_user_id The Epic Account ID of the local user whose ownership token is being retrieved.
 * @param {Array[String]} catalog_item_ids The catalog item IDs to include in the token.
 * @param {String} catalog_namespace The product namespace to use, or an empty string `""` to use the
 * configured default namespace.
 * @param {Function} [callback] Called once the request completes.
 *
 * @event callback
 * @desc Fires once with the request result.
 * @member {Struct.EpicEcomQueryOwnershipTokenCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_ecom_query_entitlements
 * @desc **Epic Online Services Function:** [EOS_Ecom_QueryEntitlements](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-query-entitlements)
 *
 * Queries the backend for the local user's entitlements. Any Epic Games-based entitlements can only be
 * queried from the running application defined by the Product ID configured with
 * ${page.extension_options}. The result is cached in the SDK's own entitlement cache — read it back with
 * ${function.eos_ecom_get_entitlements_count}/${function.eos_ecom_get_entitlements_by_name_count} and
 * the matching `eos_ecom_copy_entitlement_*` accessors.
 *
 * @param {String} local_user_id The Epic Account ID of the local user whose entitlements are being queried.
 * @param {Array[String]} entitlement_names Optional list of entitlement names to query. Pass an empty
 * array to query all entitlements for the product.
 * @param {Bool} include_redeemed Whether to include already-redeemed entitlements in the result.
 * @param {String} catalog_namespace The product namespace to use, or an empty string `""` to use the
 * configured default namespace.
 * @param {Function} [callback] Called once the query completes.
 *
 * @event callback
 * @desc Fires once with the query result.
 * @member {Struct.EpicEcomQueryEntitlementsCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_ecom_query_entitlement_token
 * @desc **Epic Online Services Function:** [EOS_Ecom_QueryEntitlementToken](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-query-entitlement-token)
 *
 * Retrieves an entitlement proof token for a list of entitlement names, which an external service can
 * verify without trusting the client.
 *
 * @param {String} local_user_id The Epic Account ID of the local user whose entitlement token is being retrieved.
 * @param {Array[String]} entitlement_names The entitlement names to include in the token.
 * @param {Function} [callback] Called once the request completes.
 *
 * @event callback
 * @desc Fires once with the request result.
 * @member {Struct.EpicEcomQueryEntitlementTokenCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_ecom_query_offers
 * @desc **Epic Online Services Function:** [EOS_Ecom_QueryOffers](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-query-offers)
 *
 * Queries the backend catalog for the store offers available to the local user. The result is cached in
 * the SDK's own offer cache — read it back with ${function.eos_ecom_get_offer_count} and
 * ${function.eos_ecom_copy_offer_by_index}/${function.eos_ecom_copy_offer_by_id}.
 *
 * @param {String} local_user_id The Epic Account ID of the local user whose offers are being queried.
 * @param {String} catalog_namespace The product namespace to use, or an empty string `""` to use the
 * configured default namespace.
 * @param {Function} [callback] Called once the query completes.
 *
 * @event callback
 * @desc Fires once with the query result.
 * @member {Struct.EpicEcomQueryOffersCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_ecom_checkout
 * @desc **Epic Online Services Function:** [EOS_Ecom_Checkout](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-checkout)
 *
 * Starts a checkout for one or more offers. This opens the Epic Overlay's purchase flow; the callback
 * fires once the player finishes, cancels, or the purchase flow otherwise closes.
 *
 * [[Note: `EpicResult.EcomPurchaseProcessing` can be returned in the callback if the player closed the
 * purchase flow overlay after clicking the purchase button — the purchase may still be processing, so
 * re-query entitlements shortly afterward rather than treating this as a hard failure.]]
 *
 * @param {String} local_user_id The Epic Account ID of the local user starting the checkout.
 * @param {Array[String]} offer_ids The offer IDs to purchase.
 * @param {String} catalog_namespace The product namespace to use, or an empty string `""` to use the
 * configured default namespace.
 * @param {Function} [callback] Called once the checkout flow completes.
 *
 * @event callback
 * @desc Fires once with the checkout result.
 * @member {Struct.EpicEcomCheckoutCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_ecom_redeem_entitlements
 * @desc **Epic Online Services Function:** [EOS_Ecom_RedeemEntitlements](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-redeem-entitlements)
 *
 * Redeems one or more consumable entitlements, decrementing their available uses. Once redeemed, the
 * redeemed entitlements can be read back with ${function.eos_ecom_get_last_redeemed_entitlements_count}
 * and ${function.eos_ecom_copy_last_redeemed_entitlement_by_index}.
 *
 * @param {String} local_user_id The Epic Account ID of the local user redeeming entitlements.
 * @param {Array[String]} entitlement_ids The entitlement IDs to redeem.
 * @param {Function} [callback] Called once the redemption completes.
 *
 * @event callback
 * @desc Fires once with the redemption result.
 * @member {Struct.EpicEcomRedeemEntitlementsCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_ecom_get_item_ownership_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetItemOwnershipCount](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-get-item-ownership-count)
 *
 * Returns the number of item ownership records cached locally for `local_user_id` by the last successful
 * ${function.eos_ecom_query_ownership} call. Returns `0` if no query has completed yet.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_ecom_copy_item_ownership_at_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyItemOwnershipByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-copy-item-ownership-by-index)
 *
 * Fetches an item ownership record from the local ownership cache by index, populated by
 * ${function.eos_ecom_query_ownership}.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {Real} index Index into the ownership cache, between 0 and ${function.eos_ecom_get_item_ownership_count} - 1.
 *
 * @returns {Struct.EpicEcomItemOwnership} Returns `undefined` if `index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_ecom_get_sandbox_ownership_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetSandboxOwnershipCount](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-get-sandbox-ownership-count)
 *
 * Returns the number of sandbox ownership records cached locally for `local_user_id` by the last
 * successful ${function.eos_ecom_query_ownership_by_sandbox_ids} call. Returns `0` if no query has
 * completed yet.
 *
 * @param {String} local_user_id The Product User ID of the local user.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_ecom_copy_sandbox_ownership_at_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopySandboxOwnershipByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-copy-sandbox-ownership-by-index)
 *
 * Fetches a sandbox ownership record from the local cache by index, populated by
 * ${function.eos_ecom_query_ownership_by_sandbox_ids}.
 *
 * @param {String} local_user_id The Product User ID of the local user.
 * @param {Real} index Index into the sandbox ownership cache, between 0 and ${function.eos_ecom_get_sandbox_ownership_count} - 1.
 *
 * @returns {Struct.EpicEcomSandboxIdItemOwnership} Returns `undefined` if `index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_ecom_get_entitlements_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetEntitlementsCount](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-get-entitlements-count)
 *
 * Returns the total number of entitlements cached for `local_user_id` by the last successful
 * ${function.eos_ecom_query_entitlements} call.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_ecom_get_entitlements_by_name_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetEntitlementsByNameCount](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-get-entitlements-by-name-count)
 *
 * Returns the number of cached entitlements matching `entitlement_name`. There can be more than one
 * instance of a given entitlement for players who own multiple copies (e.g. gifted or repurchased).
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {String} entitlement_name The entitlement name to count.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_ecom_copy_entitlement_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyEntitlementByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-copy-entitlement-by-index)
 *
 * Fetches a cached entitlement by index, populated by ${function.eos_ecom_query_entitlements}.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {Real} index Index into the entitlement cache, between 0 and ${function.eos_ecom_get_entitlements_count} - 1.
 *
 * @returns {Struct.EpicEcomEntitlement} Returns `undefined` if `index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_ecom_copy_entitlement_by_name_and_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyEntitlementByNameAndIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-copy-entitlement-by-name-and-index)
 *
 * Fetches a cached entitlement matching `entitlement_name` by index within that name's own count, as
 * returned by ${function.eos_ecom_get_entitlements_by_name_count}.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {String} entitlement_name The entitlement name to look up.
 * @param {Real} index Index within the matching entitlements for `entitlement_name`.
 *
 * @returns {Struct.EpicEcomEntitlement} Returns `undefined` if `index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_ecom_copy_entitlement_by_id
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyEntitlementById](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-copy-entitlement-by-id)
 *
 * Fetches a cached entitlement by its unique entitlement ID.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {String} entitlement_id The entitlement ID to look up.
 *
 * @returns {Struct.EpicEcomEntitlement} Returns `undefined` if the entitlement isn't cached.
 *
 * @function_end
 */

/**
 * @function eos_ecom_get_last_redeemed_entitlements_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetLastRedeemedEntitlementsCount](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-get-last-redeemed-entitlements-count)
 *
 * Returns the number of entitlement IDs redeemed by the last successful
 * ${function.eos_ecom_redeem_entitlements} call.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_ecom_copy_last_redeemed_entitlement_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyLastRedeemedEntitlementByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-copy-last-redeemed-entitlement-by-index)
 *
 * Fetches an entitlement ID redeemed by the last successful ${function.eos_ecom_redeem_entitlements} call.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {Real} index Index into the redeemed entitlements list, between 0 and ${function.eos_ecom_get_last_redeemed_entitlements_count} - 1.
 *
 * @returns {String} Returns an empty string `""` if `index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_ecom_get_offer_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetOfferCount](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-get-offer-count)
 *
 * Returns the number of offers cached for `local_user_id` by the last successful
 * ${function.eos_ecom_query_offers} call.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_ecom_copy_offer_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyOfferByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-copy-offer-by-index)
 *
 * Fetches a cached catalog offer by index, populated by ${function.eos_ecom_query_offers}.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {Real} index Index into the offer cache, between 0 and ${function.eos_ecom_get_offer_count} - 1.
 *
 * @returns {Struct.EpicEcomCatalogOffer} Returns `undefined` if `index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_ecom_copy_offer_by_id
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyOfferById](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-copy-offer-by-id)
 *
 * Fetches a cached catalog offer by its offer ID.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {String} offer_id The offer ID to look up.
 *
 * @returns {Struct.EpicEcomCatalogOffer} Returns `undefined` if the offer isn't cached.
 *
 * @function_end
 */

/**
 * @function eos_ecom_get_offer_item_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetOfferItemCount](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-get-offer-item-count)
 *
 * Returns the number of catalog items included in the given offer.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {String} offer_id The offer ID to inspect.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_ecom_copy_offer_item_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyOfferItemByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-copy-offer-item-by-index)
 *
 * Fetches a catalog item included in `offer_id` by index.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {String} offer_id The offer ID to look up items from.
 * @param {Real} item_index Index into the offer's item list, between 0 and ${function.eos_ecom_get_offer_item_count} - 1.
 *
 * @returns {Struct.EpicEcomCatalogItem} Returns `undefined` if `item_index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_ecom_copy_item_by_id
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyItemById](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-copy-item-by-id)
 *
 * Fetches a cached catalog item by its item ID.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {String} item_id The catalog item ID to look up.
 *
 * @returns {Struct.EpicEcomCatalogItem} Returns `undefined` if the item isn't cached.
 *
 * @function_end
 */

/**
 * @function eos_ecom_get_offer_image_info_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetOfferImageInfoCount](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-get-offer-image-info-count)
 *
 * Returns the number of key images available for the given offer.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {String} offer_id The offer ID to inspect.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_ecom_copy_offer_image_info_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyOfferImageInfoByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-copy-offer-image-info-by-index)
 *
 * Fetches a key image for the given offer by index.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {String} offer_id The offer ID to look up images from.
 * @param {Real} image_info_index Index into the offer's image list, between 0 and ${function.eos_ecom_get_offer_image_info_count} - 1.
 *
 * @returns {Struct.EpicEcomKeyImageInfo} Returns `undefined` if `image_info_index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_ecom_get_item_image_info_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetItemImageInfoCount](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-get-item-image-info-count)
 *
 * Returns the number of key images available for the given catalog item.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {String} item_id The catalog item ID to inspect.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_ecom_copy_item_image_info_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyItemImageInfoByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-copy-item-image-info-by-index)
 *
 * Fetches a key image for the given catalog item by index.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {String} item_id The catalog item ID to look up images from.
 * @param {Real} image_info_index Index into the item's image list, between 0 and ${function.eos_ecom_get_item_image_info_count} - 1.
 *
 * @returns {Struct.EpicEcomKeyImageInfo} Returns `undefined` if `image_info_index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_ecom_get_item_release_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetItemReleaseCount](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-get-item-release-count)
 *
 * Returns the number of release records available for the given catalog item.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {String} item_id The catalog item ID to inspect.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_ecom_copy_item_release_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyItemReleaseByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-copy-item-release-by-index)
 *
 * Fetches a release record for the given catalog item by index.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {String} item_id The catalog item ID to look up releases from.
 * @param {Real} release_index Index into the item's release list, between 0 and ${function.eos_ecom_get_item_release_count} - 1.
 *
 * @returns {Struct.EpicEcomCatalogRelease} Returns `undefined` if `release_index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_ecom_get_transaction_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_GetTransactionCount](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-get-transaction-count)
 *
 * Returns the number of successful transactions the SDK is currently caching for `local_user_id`
 * (accumulates across every checkout since the platform was created).
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_ecom_copy_transaction_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyTransactionByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-copy-transaction-by-index)
 *
 * Retrieves a transaction handle by index. The handle is registered locally the first time it's copied
 * — release it with ${function.eos_ecom_transaction_release} once you're done with it.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {Real} transaction_index Index into the transaction list, between 0 and ${function.eos_ecom_get_transaction_count} - 1.
 *
 * @returns {Real} An opaque transaction handle, or `0` if the copy failed.
 *
 * @function_end
 */

/**
 * @function eos_ecom_copy_transaction_by_id
 * @desc **Epic Online Services Function:** [EOS_Ecom_CopyTransactionById](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-copy-transaction-by-id)
 *
 * Retrieves a transaction handle by its transaction ID (as reported in
 * ${struct.EpicEcomCheckoutCallbackInfo}'s `transaction_id`). Release it with
 * ${function.eos_ecom_transaction_release} once you're done with it.
 *
 * @param {String} local_user_id The Epic Account ID of the local user.
 * @param {String} transaction_id The transaction ID to look up.
 *
 * @returns {Real} An opaque transaction handle, or `0` if the copy failed.
 *
 * @function_end
 */

/**
 * @function eos_ecom_transaction_get_transaction_id
 * @desc **Epic Online Services Function:** [EOS_Ecom_Transaction_GetTransactionId](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-transaction-get-transaction-id)
 *
 * Returns the transaction ID of the given transaction handle.
 *
 * @param {Real} tx_handle_id A transaction handle from ${function.eos_ecom_copy_transaction_by_index} or ${function.eos_ecom_copy_transaction_by_id}.
 *
 * @returns {String} Returns an empty string `""` if `tx_handle_id` is invalid.
 *
 * @function_end
 */

/**
 * @function eos_ecom_transaction_get_entitlements_count
 * @desc **Epic Online Services Function:** [EOS_Ecom_Transaction_GetEntitlementsCount](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-transaction-get-entitlements-count)
 *
 * Returns the number of entitlements granted by the given transaction.
 *
 * @param {Real} tx_handle_id A transaction handle from ${function.eos_ecom_copy_transaction_by_index} or ${function.eos_ecom_copy_transaction_by_id}.
 *
 * @returns {Real} Returns `0` if `tx_handle_id` is invalid.
 *
 * @function_end
 */

/**
 * @function eos_ecom_transaction_copy_entitlement_by_index
 * @desc **Epic Online Services Function:** [EOS_Ecom_Transaction_CopyEntitlementByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-transaction-copy-entitlement-by-index)
 *
 * Fetches an entitlement granted by the given transaction, by index.
 *
 * @param {Real} tx_handle_id A transaction handle from ${function.eos_ecom_copy_transaction_by_index} or ${function.eos_ecom_copy_transaction_by_id}.
 * @param {Real} index Index into the transaction's entitlement list, between 0 and ${function.eos_ecom_transaction_get_entitlements_count} - 1.
 *
 * @returns {Struct.EpicEcomEntitlement} Returns `undefined` if `tx_handle_id` is invalid or `index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_ecom_transaction_release
 * @desc **Epic Online Services Function:** [EOS_Ecom_Transaction_Release](https://dev.epicgames.com/docs/api-ref/functions/eos-ecom-transaction-release)
 *
 * Releases a transaction handle obtained from ${function.eos_ecom_copy_transaction_by_index} or
 * ${function.eos_ecom_copy_transaction_by_id}. Using the handle after release is invalid.
 *
 * [[Note: Any transaction handles still outstanding when the platform shuts down are released automatically.]]
 *
 * @param {Real} tx_handle_id The transaction handle to release.
 *
 * @function_end
 */

// Structs

/**
 * @struct EpicEcomEntitlement
 * @desc A single entitlement owned by the local user.
 *
 * @member {String} entitlement_name The name of the entitlement.
 * @member {String} entitlement_id The unique ID of this specific entitlement instance.
 * @member {String} catalog_item_id The catalog item ID this entitlement is associated with.
 * @member {Real} server_index Index of this entitlement on the server, used with the transaction API.
 * @member {Bool} redeemed Whether this entitlement has already been redeemed.
 * @member {Real} end_timestamp POSIX timestamp the entitlement expires at, or `-1` if it doesn't expire.
 *
 * @struct_end
 */

/**
 * @struct EpicEcomItemOwnership
 * @desc A single catalog item's ownership status, as returned by ${function.eos_ecom_query_ownership}.
 *
 * @member {String} id The catalog item ID.
 * @member {Constant.EpicOwnershipStatus} ownership_status Whether the local user owns this item.
 *
 * @struct_end
 */

/**
 * @struct EpicEcomSandboxIdItemOwnership
 * @desc A single sandbox's ownership result, as returned by ${function.eos_ecom_query_ownership_by_sandbox_ids}.
 *
 * @member {String} sandbox_id The sandbox ID this result is for.
 * @member {String} owned_catalog_item_ids The catalog item IDs owned by the local user within this
 * sandbox, joined with `|`. Split on `|` to get the individual IDs; empty if none are owned.
 *
 * @struct_end
 */

/**
 * @struct EpicEcomCatalogOffer
 * @desc A single purchasable offer from the catalog.
 *
 * @member {Real} server_index Index of this offer on the server.
 * @member {String} catalog_namespace The product namespace this offer belongs to.
 * @member {String} id The offer's unique ID.
 * @member {String} title_text Localized title of the offer.
 * @member {String} description_text Localized short description of the offer.
 * @member {String} long_description_text Localized long description of the offer.
 * @member {String} currency_code The 3-letter ISO 4217 currency code for the offer's price.
 * @member {Constant.EpicResult} price_result Whether pricing information is available for this offer.
 * @member {Real} discount_percentage The discount percentage currently applied, `0`-`100`.
 * @member {Real} expiration_timestamp POSIX timestamp the offer expires at, or `-1` if it doesn't expire.
 * @member {Real} purchase_limit The maximum number of times this offer can be purchased, or `-1` if unlimited.
 * @member {Real} available_for_purchase Whether the offer is currently purchasable, as `1`/`0`.
 * @member {Real} original_price64 The pre-discount price, in the smallest currency unit (e.g. cents), as
 * a fixed-point value using `decimal_point`.
 * @member {Real} current_price64 The current (possibly discounted) price, same units as `original_price64`.
 * @member {Real} decimal_point The number of decimal digits `original_price64`/`current_price64` are scaled by.
 * @member {Real} release_date_timestamp POSIX timestamp the offer's item releases, or `-1` if not applicable.
 * @member {Real} effective_date_timestamp POSIX timestamp the offer's price became effective, or `-1` if not applicable.
 *
 * @struct_end
 */

/**
 * @struct EpicEcomCatalogItem
 * @desc A single catalog item included in an offer.
 *
 * @member {String} catalog_namespace The product namespace this item belongs to.
 * @member {String} id The catalog item's unique ID.
 * @member {String} entitlement_name The entitlement name granted when this item is owned.
 * @member {String} title_text Localized title of the item.
 * @member {String} description_text Localized short description of the item.
 * @member {String} long_description_text Localized long description of the item.
 * @member {String} technical_details_text Localized technical details of the item.
 * @member {String} developer_text Localized name of the item's developer.
 * @member {Constant.EpicEcomItemType} item_type The kind of item this is.
 * @member {Real} entitlement_end_timestamp POSIX timestamp the granted entitlement expires at, or `-1` if it doesn't expire.
 *
 * @struct_end
 */

/**
 * @struct EpicEcomKeyImageInfo
 * @desc A single key image (artwork) associated with an offer or catalog item.
 *
 * @member {String} type The image's type/slot name (e.g. `"Thumbnail"`).
 * @member {String} url The URL the image can be downloaded from.
 * @member {Real} width The image width, in pixels.
 * @member {Real} height The image height, in pixels.
 *
 * @struct_end
 */

/**
 * @struct EpicEcomCatalogRelease
 * @desc A single release record for a catalog item, describing which app builds/platforms it's compatible with.
 *
 * @member {String} compatible_app_ids The compatible application IDs, joined with `|`.
 * @member {String} compatible_platforms The compatible platform names, joined with `|`.
 * @member {String} release_note Localized release note text for this release.
 *
 * @struct_end
 */

/**
 * @struct EpicEcomQueryOwnershipCallbackInfo
 * @desc Result of ${function.eos_ecom_query_ownership}.
 *
 * @member {Constant.EpicResult} result_code The result of the operation.
 * @member {String} local_user_id The Epic Account ID of the local user this result is for.
 * @member {Real} item_ownership_count The number of ownership records now cached — see ${function.eos_ecom_get_item_ownership_count}.
 *
 * @struct_end
 */

/**
 * @struct EpicEcomQueryOwnershipBySandboxIdsCallbackInfo
 * @desc Result of ${function.eos_ecom_query_ownership_by_sandbox_ids}.
 *
 * @member {Constant.EpicResult} result_code The result of the operation.
 * @member {String} local_user_id The Product User ID of the local user this result is for.
 * @member {Real} sandbox_ownership_count The number of sandbox ownership records now cached — see ${function.eos_ecom_get_sandbox_ownership_count}.
 *
 * @struct_end
 */

/**
 * @struct EpicEcomQueryOwnershipTokenCallbackInfo
 * @desc Result of ${function.eos_ecom_query_ownership_token}.
 *
 * @member {Constant.EpicResult} result_code The result of the operation.
 * @member {String} local_user_id The Epic Account ID of the local user this result is for.
 * @member {String} ownership_token The ownership proof token. Empty on failure.
 *
 * @struct_end
 */

/**
 * @struct EpicEcomQueryEntitlementsCallbackInfo
 * @desc Result of ${function.eos_ecom_query_entitlements}.
 *
 * @member {Constant.EpicResult} result_code The result of the operation.
 * @member {String} local_user_id The Epic Account ID of the local user this result is for.
 *
 * @struct_end
 */

/**
 * @struct EpicEcomQueryEntitlementTokenCallbackInfo
 * @desc Result of ${function.eos_ecom_query_entitlement_token}.
 *
 * @member {Constant.EpicResult} result_code The result of the operation.
 * @member {String} local_user_id The Epic Account ID of the local user this result is for.
 * @member {String} entitlement_token The entitlement proof token. Empty on failure.
 *
 * @struct_end
 */

/**
 * @struct EpicEcomQueryOffersCallbackInfo
 * @desc Result of ${function.eos_ecom_query_offers}.
 *
 * @member {Constant.EpicResult} result_code The result of the operation.
 * @member {String} local_user_id The Epic Account ID of the local user this result is for.
 *
 * @struct_end
 */

/**
 * @struct EpicEcomCheckoutCallbackInfo
 * @desc Result of ${function.eos_ecom_checkout}.
 *
 * @member {Constant.EpicResult} result_code The result of the checkout flow.
 * @member {String} local_user_id The Epic Account ID of the local user this result is for.
 * @member {String} transaction_id The resulting transaction ID on success. Pass this to
 * ${function.eos_ecom_copy_transaction_by_id} to inspect the granted entitlements.
 *
 * @struct_end
 */

/**
 * @struct EpicEcomRedeemEntitlementsCallbackInfo
 * @desc Result of ${function.eos_ecom_redeem_entitlements}.
 *
 * @member {Constant.EpicResult} result_code The result of the operation.
 * @member {String} local_user_id The Epic Account ID of the local user this result is for.
 * @member {Real} redeemed_count The number of entitlements redeemed — see ${function.eos_ecom_get_last_redeemed_entitlements_count}.
 *
 * @struct_end
 */

// Constants

/**
 * @const EpicOwnershipStatus
 * @desc **Epic Online Services Enum:** [EOS_EOwnershipStatus](https://dev.epicgames.com/docs/api-ref/enums/eos-e-ownership-status)
 *
 * Whether a catalog item is owned by the local user, as reported by ${function.eos_ecom_query_ownership}.
 *
 * @member NotOwned The catalog item is not owned by the local user.
 * @member Owned The catalog item is owned by the local user.
 *
 * @const_end
 */

/**
 * @const EpicEcomItemType
 * @desc **Epic Online Services Enum:** [EOS_EEcomItemType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-ecom-item-type)
 *
 * The kind of a ${struct.EpicEcomCatalogItem}.
 *
 * @member Durable A durable item, owned permanently once purchased.
 * @member Consumable A consumable item, whose entitlement can be redeemed/decremented via ${Function.eos_ecom_redeem_entitlements}.
 * @member Other An item that isn't a durable or consumable (e.g. a subscription).
 *
 * @const_end
 */

/**
 * @const EpicCheckoutOrientation
 * @desc **Epic Online Services Enum:** [EOS_Ecom_ECheckoutOrientation](https://dev.epicgames.com/docs/api-ref/enums/eos-ecom-e-checkout-orientation)
 *
 * The preferred screen orientation for the checkout overlay.
 *
 * [[Note: This extension always requests `Default` — there is currently no way to override it from GML.]]
 *
 * @member Default Use the platform's default orientation.
 * @member Portrait Prefer portrait orientation.
 * @member Landscape Prefer landscape orientation.
 *
 * @const_end
 */

/**
 * @module ecom
 * @title Ecom
 * @desc **Epic Online Services Interface:** [Ecom Interface](https://dev.epicgames.com/docs/game-services/eos-ecom-interface)
 *
 * The Ecom (E-Commerce) Interface lets you query and sell your game's catalog items, manage entitlements,
 * and check ownership — covering the full loop from browsing offers to completing a purchase through the
 * Epic Overlay.
 *
 * @section_func
 * @desc Provided functions:
 *
 * @ref eos_ecom_query_ownership
 * @ref eos_ecom_query_ownership_by_sandbox_ids
 * @ref eos_ecom_query_ownership_token
 * @ref eos_ecom_query_entitlements
 * @ref eos_ecom_query_entitlement_token
 * @ref eos_ecom_query_offers
 * @ref eos_ecom_checkout
 * @ref eos_ecom_redeem_entitlements
 * @ref eos_ecom_get_item_ownership_count
 * @ref eos_ecom_copy_item_ownership_at_index
 * @ref eos_ecom_get_sandbox_ownership_count
 * @ref eos_ecom_copy_sandbox_ownership_at_index
 * @ref eos_ecom_get_entitlements_count
 * @ref eos_ecom_get_entitlements_by_name_count
 * @ref eos_ecom_copy_entitlement_by_index
 * @ref eos_ecom_copy_entitlement_by_name_and_index
 * @ref eos_ecom_copy_entitlement_by_id
 * @ref eos_ecom_get_last_redeemed_entitlements_count
 * @ref eos_ecom_copy_last_redeemed_entitlement_by_index
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
 * @ref eos_ecom_copy_transaction_by_index
 * @ref eos_ecom_copy_transaction_by_id
 * @ref eos_ecom_transaction_get_transaction_id
 * @ref eos_ecom_transaction_get_entitlements_count
 * @ref eos_ecom_transaction_copy_entitlement_by_index
 * @ref eos_ecom_transaction_release
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this API:
 *
 * @ref EpicEcomEntitlement
 * @ref EpicEcomItemOwnership
 * @ref EpicEcomSandboxIdItemOwnership
 * @ref EpicEcomCatalogOffer
 * @ref EpicEcomCatalogItem
 * @ref EpicEcomKeyImageInfo
 * @ref EpicEcomCatalogRelease
 * @ref EpicEcomQueryOwnershipCallbackInfo
 * @ref EpicEcomQueryOwnershipBySandboxIdsCallbackInfo
 * @ref EpicEcomQueryOwnershipTokenCallbackInfo
 * @ref EpicEcomQueryEntitlementsCallbackInfo
 * @ref EpicEcomQueryEntitlementTokenCallbackInfo
 * @ref EpicEcomQueryOffersCallbackInfo
 * @ref EpicEcomCheckoutCallbackInfo
 * @ref EpicEcomRedeemEntitlementsCallbackInfo
 *
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this API:
 *
 * @ref EpicOwnershipStatus
 * @ref EpicEcomItemType
 * @ref EpicCheckoutOrientation
 *
 * @section_end
 *
 * @module_end
 */
