
/**
 * An enumeration of the different ownership statuses.
 */
enum EOS_OWNERSHIP_STATUS
{
	/** The catalog item is not owned by the local user */
	NotOwned = 0,
	/** The catalog item is owned by the local user */
	Owned = 1
}

/**
 * An enumeration defining the type of catalog item.  The primary use is to identify how the item is expended.
 */
enum EOS_ECOM_ITEM_TYPE
{
	/** This entitlement is intended to persist. */
	Durable = 0,
	/**
	 * This entitlement is intended to be transient and redeemed.
	 *
	 * @see EOS_Ecom_RedeemEntitlements
	 */
	Consumable = 1,
	/** This entitlement has a type that is not currently intended for an in-game store. */
	Other = 2
}

/** Timestamp value representing an undefined ExpirationTimestamp for EOS_Ecom_CatalogOffer */
#macro EOS_ECOM_CATALOGOFFER_EXPIRATIONTIMESTAMP_UNDEFINED -1
/** Timestamp value representing an undefined ReleaseDateTimestamp for EOS_Ecom_CatalogOffer */
#macro EOS_ECOM_CATALOGOFFER_RELEASEDATETIMESTAMP_UNDEFINED -1
/** Timestamp value representing an undefined EffectiveDateTimestamp for EOS_Ecom_CatalogOffer */
#macro EOS_ECOM_CATALOGOFFER_EFFECTIVEDATETIMESTAMP_UNDEFINED -1


/**
 * The maximum number of Sandbox Ids that may be queried in a single pass.
 */
#macro EOS_ECOM_QUERYOWNERSHIP_MAX_SANDBOX_IDS 10


/**
 * The maximum number of catalog items that may be queried in a single pass
 */
#macro EOS_ECOM_QUERYOWNERSHIPTOKEN_MAX_CATALOGITEM_IDS 32


/**
 * The maximum number of entitlements that may be queried in a single QueryEntitlements API call.
 */
#macro EOS_ECOM_QUERYENTITLEMENTS_MAX_ENTITLEMENT_IDS 256

/** The maximum number of entitlements that may be queried in a single pass. */
#macro EOS_ECOM_QUERYENTITLEMENTTOKEN_MAX_ENTITLEMENT_IDS 32


/** The maximum number of entries in a single checkout. */
#macro EOS_ECOM_CHECKOUT_MAX_ENTRIES 10

/** The maximum length of a transaction ID. */
#macro EOS_ECOM_TRANSACTIONID_MAXIMUM_LENGTH 64

/**
 * The maximum number of entitlement IDs that may be redeemed in a single pass
 */
#macro EOS_ECOM_REDEEMENTITLEMENTS_MAX_IDS 32

/**
* The maximum length of an entitlement ID
*/
#macro EOS_ECOM_ENTITLEMENTID_MAX_LENGTH 32
