
/**
 * A packet's maximum size in bytes
 */
#macro EOS_P2P_MAX_PACKET_SIZE 1170

/**
 * The maximum amount of unique Socket ID connections that can be opened with each remote user. As this limit is only per remote user, you may have more
 * than this number of Socket IDs across multiple remote users.
 */
#macro EOS_P2P_MAX_CONNECTIONS 32

/**
 * Categories of NAT strictness.
 */
enum EOS_NAT_TYPE
{
	/** NAT type either unknown (remote) or we are unable to determine it (local) */
	UNKNOWN = 0,
	/** All peers can directly-connect to you */
	OPEN = 1,
	/** You can directly-connect to other Moderate and Open peers */
	MODERATE = 2,
	/** You can only directly-connect to Open peers */
	STRICT = 3
};


/** The total buffer size of a EOS_P2P_SocketId SocketName, including space for the null-terminator */
#macro EOS_P2P_SOCKETID_SOCKETNAME_SIZE 33

/**
 * Types of packet reliability.
 *
 * Ordered packets will only be ordered relative to other ordered packets. Reliable/unreliable and ordered/unordered communication
 * can be sent on the same Socket ID and Channel.
 */
enum EOS_PACKET_RELIABILITY
{
	/** Packets will only be sent once and may be received out of order */
	UNRELIABLE_UNORDERED = 0,
	/** Packets may be sent multiple times and may be received out of order */
	RELIABLE_UNORDERED = 1,
	/** Packets may be sent multiple times and will be received in order */
	RELIABLE_ORDERED = 2
};

/**
 * Type of established connection
 */
enum EOS_CONNECTION_ESTABLISHED_TYPE
{
	/** The connection is brand new */
	NEW_CONNECTION = 0,
	/** The connection is reestablished (reconnection) */
	RECONNECTION = 1
};

/**
 * Types of network connections.
 */
enum EOS_NETWORK_CONNECTION_TYPE
{
	/** There is no established connection */
	NO_CONNECTION = 0,
	/** A direct connection to the peer over the Internet or Local Network */
	DIRECT_CONNECTION = 1,
	/** A relayed connection using Epic-provided servers to the peer over the Internet */
	RELAYED_CONNECTION = 2
};


/**
 * Reasons why a P2P connection was closed
 */
enum EOS_CONNECTION_CLOSED_REASON
{
	/** The connection was closed for unknown reasons. This most notably happens during application shutdown. */
	UNKNOWN = 0,
	/** The connection was at least locally accepted, but was closed by the local user via a call to EOS_P2P_CloseConnection / EOS_P2P_CloseConnections. */
	CLOSED_BY_LOCAL_USER = 1,
	/** The connection was at least locally accepted, but was gracefully closed by the remote user via a call to EOS_P2P_CloseConnection / EOS_P2P_CloseConnections. */
	CLOSED_BY_PEER = 2,
	/** The connection was at least locally accepted, but was not remotely accepted in time. */
	TIMED_OUT = 3,
	/** The connection was accepted, but the connection could not be created due to too many other existing connections */
	TOO_MANY_CONNECTIONS = 4,
	/** The connection was accepted, The remote user sent an invalid message */
	INVALID_MESSAGE = 5,
	/** The connection was accepted, but the remote user sent us invalid data */
	INVALID_DATA = 6,
	/** The connection was accepted, but we failed to ever establish a connection with the remote user due to connectivity issues. */
	CONNECTION_FAILED = 7,
	/** The connection was accepted and established, but the peer silently went away. */
	CONNECTION_CLOSED = 8,
	/** The connection was locally accepted, but we failed to negotiate a connection with the remote user. This most commonly occurs if the local user goes offline or is logged-out during the connection process. */
	NEGOTIATION_FAILED = 9,
	/** The connection was accepted, but there was an internal error occurred and the connection cannot be created or continue. */
	UNEXPECTED_ERROR = 10
}

/**
 * Setting for controlling whether relay servers are used.
 *
 * Please see the following EOS_ERelayControl value compatibility-chart to better understand how changing this value
 * can affect compatibility between clients with different settings.
 *
 * +------------------------------+---------------------+-------------------------------+---------------------+
 * |                              |   EOS_RC_NoRelays   |  EOS_RC_AllowRelays (Default) |  EOS_RC_ForceRelays |
 * +------------------------------+---------------------+-------------------------------+---------------------+
 * | EOS_RC_NoRelays              |  Compatible         |  Compatible                   |  Connection Failure |
 * | EOS_RC_AllowRelays (Default) |  Compatible         |  Compatible                   |  Compatible         |
 * | EOS_RC_ForceRelays           |  Connection Failure |  Compatible                   |  Compatible         |
 * +------------------------------+---------------------+-------------------------------+---------------------+
 */
enum EOS_RELAY_CONTROL
{
	/** Peer connections will never attempt to use relay servers. Clients with restrictive NATs may not be able to connect to peers. */
	NO_RELAYS = 0,
	/** Peer connections will attempt to use relay servers, but only after direct connection attempts fail. This is the default value if not changed. */
	ALLOW_RELAYS = 1,
	/** Peer connections will only ever use relay servers. This will add latency to all connections, but will hide IP Addresses from peers. */
	FORCE_RELAYS = 2
};
