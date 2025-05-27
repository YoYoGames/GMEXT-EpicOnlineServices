
/** Maximum size of the custom invite payload string */
#macro EOS_CUSTOMINVITES_MAX_PAYLOAD_LENGTH 500



/** Response to an invite request. */
enum EOS_REQUEST_TO_JOIN_RESPONSE
{
	/** The target of the invite request has accepted. */
	ACCEPTED = 0,
	/** The target of the invite request has rejected. */
	REJECTED = 1
}

