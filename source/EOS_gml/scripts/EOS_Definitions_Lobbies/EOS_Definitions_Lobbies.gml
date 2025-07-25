
#macro EOS_LOBBY_MAX_LOBBIES 16
#macro EOS_LOBBY_MAX_LOBBY_MEMBERS 64
#macro EOS_LOBBY_MAX_SEARCH_RESULTS 200

/** Minimum number of characters allowed in the lobby id override */
#macro EOS_LOBBY_MIN_lobby_idOVERRIDE_LENGTH 4
/** Maximum number of characters allowed in the lobby id override */
#macro EOS_LOBBY_MAX_lobby_idOVERRIDE_LENGTH 60

/** Maximum number of attributes allowed on the lobby */
#macro EOS_LOBBYMODIFICATION_MAX_ATTRIBUTES 64
/** Maximum length of the name of the attribute associated with the lobby */
#macro EOS_LOBBYMODIFICATION_MAX_ATTRIBUTE_LENGTH 64

#macro EOS_LOBBY_PARSECONNECTSTRING_BUFFER_SIZE 256
/** The buffer size to provide to the  EOS_Lobby_GetConnectString API. */
#macro EOS_LOBBY_GETCONNECTSTRING_BUFFER_SIZE 256
#macro EOS_LOBBY_INVITEID_MAX_LENGTH 64
/** Search for a matching bucket ID (value is string) */
#macro EOS_LOBBY_SEARCH_BUCKET_ID "bucket"
/** Search for lobbies that contain at least this number of members (value is int) */
#macro EOS_LOBBY_SEARCH_MINCURRENTMEMBERS "mincurrentmembers"
/** Search for a match with min free space (value is int) */
#macro EOS_LOBBY_SEARCH_MINSLOTSAVAILABLE "minslotsavailable"


/** Permission level gets more restrictive further down */
enum EOS_LOBBY_PERMISSION_LEVEL
{
	/** Anyone can find this lobby as long as it isn't full */
	PUBLIC_ADVERTISED = 0,
	/** Players who have access to presence can see this lobby */
	JOIN_VIA_PRESENCE = 1,
	/** Only players with invites registered can see this lobby */
	INVITE_ONLY = 2
};

/** Advertisement properties for a single attribute associated with a lobby */
enum EOS_LOBBY_ATTRIBUTE_VISIBILITY
{
	/** Data is visible to lobby members, searchable and visible in search results. */
	PUBLIC = 0,
	/** Data is only visible to the user setting the data. Data is not visible to lobby members, not searchable, and not visible in search results. */
	PRIVATE = 1
};

/** Various types of lobby member updates */
enum EOS_LOBBY_MEMBER_STATUS
{
	/** The user has joined the lobby */
	JOINED = 0,
	/** The user has explicitly left the lobby */
	LEFT = 1,
	/** The user has unexpectedly left the lobby */
	DISCONNECTED = 2,
	/** The user has been kicked from the lobby */
	KICKED = 3,
	/** The user has been promoted to lobby owner */
	PROMOTED = 4,
	/** The lobby has been closed and user has been removed */
	CLOSED = 5
};

