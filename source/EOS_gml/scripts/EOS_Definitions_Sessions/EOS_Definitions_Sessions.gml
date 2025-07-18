
/** All possible states of an existing named session */
enum EOS_ONLINE_SESSION_STATE
{
	/** An online session has not been created yet */
	NO_SESSION = 0,
	/** An online session is in the process of being created */
	CREATING = 1,
	/** Session has been created but the session hasn't started (pre match lobby) */
	PENDING = 2,
	/** Session has been asked to start (may take time due to communication with backend) */
	STARTING = 3,
	/** The current session has started. Sessions with join in progress disabled are no longer joinable */
	IN_PROGRESS = 4,
	/** The session is still valid, but the session is no longer being played (post match lobby) */
	ENDING = 5,
	/** The session is closed and any stats committed */
	ENDED = 6,
	/** The session is being destroyed */
	DESTROYING = 7
}

/** Advertisement properties for a single attribute associated with a session */
enum EOS_SESSION_ATTRIBUTE_ADVERTISEMENT_TYPE
{
	/** Don't advertise via the online service */
	DONT_ADVERTISE = 0,
	/** Advertise via the online service only */
	ADVERTISE = 1
}


/** Permission level gets more restrictive further down */
enum EOS_ONLINE_SESSION_PERMISSION_LEVEL
{
	/** Anyone can find this session as long as it isn't full */
	PUBLIC_ADVERTISED = 0,
	/** Players who have access to presence can see this session */
	JOIN_VIA_PRESENCE = 1,
	/** Only players with invites registered can see this session */
	INVITE_ONLY = 2
};




/** Maximum number of attributes allowed on the session */
#macro EOS_SESSIONMODIFICATION_MAX_SESSION_ATTRIBUTES 64
/** Maximum length of the name of the attribute associated with the session */
#macro EOS_SESSIONMODIFICATION_MAX_SESSION_ATTRIBUTE_LENGTH 64

/** Minimum number of characters allowed in the session id override */
#macro EOS_SESSIONMODIFICATION_MIN_SESSIONIDOVERRIDE_LENGTH 16
/** Maximum number of characters allowed in the session id override */
#macro EOS_SESSIONMODIFICATION_MAX_SESSIONIDOVERRIDE_LENGTH 64


/** Max length of an invite ID */
#macro EOS_SESSIONS_INVITEID_MAX_LENGTH 64



/** Maximum number of search results allowed with a given query */
#macro EOS_SESSIONS_MAX_SEARCH_RESULTS 200
/** Search for a matching bucket ID (value is string) */
#macro EOS_SESSIONS_SEARCH_BUCKET_ID "bucket"
/** Search for empty servers only (value is true/false) */
#macro EOS_SESSIONS_SEARCH_EMPTY_SERVERS_ONLY "emptyonly"
/** Search for non empty servers only (value is true/false) */
#macro EOS_SESSIONS_SEARCH_NONEMPTY_SERVERS_ONLY "nonemptyonly"
/** Search for a match with min free space (value is int) */
#macro EOS_SESSIONS_SEARCH_MINSLOTSAVAILABLE "minslotsavailable"




