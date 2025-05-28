/**
 * @module p2p
 * @title P2P
 * @desc **Epic Online Services Interface**: [P2P Interface](https://dev.epicgames.com/docs/en-US/api-ref/interfaces/p-2-p)
 * 
 * This module contains functionality to interact with the [NAT P2P Interface](https://dev.epicgames.com/docs/game-services/p-2-p), which has functionality to send and receive data between users, and related networking functionality.
 * 
 * P2P connections enable game clients to send and receive data between one another directly, typically for the purpose of a multiplayer game. Connections made with the EOS P2P Interface are only established between authenticated users, and are secure-by-default using Datagram Transport Layer ([DTLS](https://en.wikipedia.org/wiki/Datagram_Transport_Layer_Security)). DTLS provides two distinct advantages over other communications protocols: *The speed of handling P2P connections is significantly increased, resulting in EOS's authentication having a greatly reduced need for connections to be re-negotiated.
 * 
 * @section_func
 * @desc The following are the functions of the P2P module:
 * @ref eos_p2p_*
 * @section_end
 * 
 * @section_struct
 * @desc The following are the structs of the P2P module:
 * @ref PacketQueueInfo
 * @section_end
 * 
 * @section_const
 * @desc The following are the constants and enums of the P2P module:
 * @ref EOS_CONNECTION_CLOSED_REASON
 * @ref EOS_CONNECTION_ESTABLISHED_TYPE
 * @ref EOS_NAT_TYPE
 * @ref EOS_NETWORK_CONNECTION_TYPE
 * @ref EOS_PACKET_RELIABILITY
 * @ref EOS_RELAY_CONTROL
 * @section_end
 * 
 * @module_end
 */

// Functions

/**
 * @func eos_p2p_accept_connection
 * @desc **Epic Online Services Function:** [EOS_P2P_AcceptConnection](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-accept-connection)
 * 
 * This function accepts or requests a connection with a specific peer on a specific Socket ID. If this connection was not already locally accepted, EOS will securely message the peer, and trigger a PeerConnectionRequest notification notifying them of the connection request. If the PeerConnectionRequest notification is not bound for all socket IDs or for the requested socket ID in particular, the request will be silently ignored. If the remote peer accepts the connection, a notification will be broadcast to the EOS_P2P_AddNotifyPeerConnectionEstablished when the connection is ready to send packets. If multiple Socket IDs are accepted with one peer, they will share one physical socket. Even if a connection is already locally accepted, `EOS_RESULT.SUCCESS` will still be returned if the input was valid. `EOS_RESULT.INVALID_PARAMETERS` will be returned if the input is invalid.
 *
 * @param {string} local_user_id The Product User ID of the local user who is accepting any pending or future connections with `remote_user_id`
 * @param {string} remote_user_id The Product User ID of the remote user who has either sent a connection request or is expected to in the future
 * @param {string} socket_name The socket ID of the connection to accept on
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_add_notify_incoming_packet_queue_full
 * @desc **Epic Online Services Function:** [EOS_P2P_AddNotifyIncomingPacketQueueFull](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-add-notify-incoming-packet-queue-full)
 * 
 * This function listens for when the packet queue has become full. This event gives an opportunity to read packets to make room for new incoming packets. If this event fires and no packets are read by calling ${function.eos_p2p_receive_packet} or the packet queue size is not increased by ${function.eos_p2p_set_packet_queue_size}, any packets that are received after this event are discarded until there is room again in the queue.
 * 
 * The function returns a valid notification ID if successfully bound, or ${constant.EOS_INVALID_NOTIFICATIONID} otherwise.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_p2p_add_notify_incoming_packet_queue_full"`
 * @member {real} overflow_packet_channel The channel the incoming packet is for
 * @member {string} overflow_packet_local_user_id The Product User ID of the local user who is receiving the packet that would overflow the queue
 * @member {real} overflow_packet_size_bytes The size in bytes of the incoming packet (and related metadata) that would overflow the queue
 * @member {real} packet_queue_current_size_bytes The current size in bytes the incoming packet queue is currently using
 * @member {real} packet_queue_max_size_bytes The maximum size in bytes the incoming packet queue is allowed to use
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_p2p_add_notify_peer_connection_closed
 * @desc **Epic Online Services Function:** [EOS_P2P_AddNotifyPeerConnectionClosed](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-add-notify-peer-connection-closed)
 * 
 * This function listens for when a previously accepted connection that was either open or pending is closed. When a connection closes, packets are flushed. This includes reliable packets.
 * 
 * The function returns a valid notification ID if successfully bound, or ${constant.EOS_INVALID_NOTIFICATIONID} otherwise.
 * 
 * @param {string} local_user_id The Product User ID of the local user who would like notifications
 * @param {string} socket_name The optional socket ID to listen for to be closed. If an empty string `""` is passed, this function handler will be called for all closed connections.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_p2p_add_notify_peer_connection_closed"`
 * @member {string} local_user_id The local user who is being notified of a connection being closed
 * @member {constant.EOS_CONNECTION_CLOSED_REASON} reason The reason the connection was closed (if known)
 * @member {string} remote_user_id The Product User ID of the remote user who this connection was with
 * @member {string} socket_name The socket ID of the connection being closed
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_p2p_add_notify_peer_connection_established
 * @desc **Epic Online Services Function:** [EOS_P2P_AddNotifyPeerConnectionEstablished](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-add-notify-peer-connection-established)
 * 
 * This function listens for when a connection is established. This is fired when we first connect to a peer, when we reconnect to a peer after a connection interruption, and when our underlying network connection type changes (for example, from a direct connection to relay, or vice versa). Network Connection Type changes will always be broadcast with a `EOS_CONNECTION_ESTABLISHED_TYPE.RECONNECTION` connection type, even if the connection was not interrupted. If the network status changes from offline to online, you must call this function again.
 * 
 * @param {string} local_user_id The Product User ID of the local user who would like to receive notifications
 * @param {string} socket_name The optional socket ID, used as a filter for established connections. If an empty string `""` is passed, this function handler will be called for all sockets.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_p2p_add_notify_peer_connection_established"`
 * @member {string} local_user_id The Product User ID of the local user who is being notified of a connection being established
 * @member {constant.EOS_CONNECTION_ESTABLISHED_TYPE} connection_type Whether this is a new connection or reconnection
 * @member {constant.EOS_NETWORK_CONNECTION_TYPE} network_type What type of network connection is being used for this connection
 * @member {string} socket_id The socket ID of the connection being established
 * @member {string} remote_user_id The Product User ID of the remote user who this connection was with
 * @event_end
	
 * @func_end
 */

/**
 * @func eos_p2p_add_notify_peer_connection_interrupted
 * @desc **Epic Online Services Function:** [EOS_P2P_AddNotifyPeerConnectionInterrupted](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-add-notify-peer-connection-interrupted)
 * 
 * This function listens for when a previously opened connection is interrupted. The connection will automatically attempt to reestablish, but it may not be successful. If a connection reconnects, it will trigger the P2P PeerConnectionEstablished notification with the `EOS_CONNECTION_ESTABLISHED_TYPE.RECONNECTION` connection type. If a connection fails to reconnect, it will trigger the P2P PeerConnectionClosed notification. Packets remain queued during connection interruptions. When a connection closes, packets are flushed. This includes reliable packets.
 * 
 * The function returns the notification ID.
 *
 * @param {string} local_user_id The Product User ID of the local user who would like notifications
 * @param {string} socket_name An optional socket ID to filter interrupted connections on. If an empty string, this function handler will be called for all interrupted connections.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_p2p_add_notify_peer_connection_interrupted"`
 * @member {string} local_user_id The local user who is being notified of a connection that was interrupted
 * @member {string} remote_user_id The Product User ID of the remote user who this connection was with
 * @member {string} socket_name The socket ID of the connection that was interrupted
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_p2p_add_notify_peer_connection_request
 * @desc **Epic Online Services Function:** [EOS_P2P_AddNotifyPeerConnectionRequest](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-add-notify-peer-connection-request)
 * 
 * This function listens for incoming connection requests on a particular Socket ID, or optionally all Socket IDs. The ${event.social} will only be called if the connection has not already been accepted. If the network status changes from offline to online, you must call this function again.
 * 
 * The function returns the notification ID.
 *
 * @param {string} local_user_id The Product User ID of the user who is listening for incoming connection requests
 * @param {string} socket_name The optional socket ID to listen for, used as a filter for incoming connection requests; If an empty string, incoming connection requests will not be filtered
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_p2p_add_notify_peer_connection_request"`
 * @member {string} local_user_id The Product User ID of the local user who is being requested to open a P2P session with `remote_user_id`
 * @member {string} remote_user_id The Product User ID of the remote user who requested a peer connection with the local user
 * @member {string} socket_name The ID of the socket the Remote User wishes to communicate on
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_p2p_clear_packet_queue
 * @desc **Epic Online Services Function:** [EOS_P2P_ClearPacketQueue](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-clear-packet-queue)
 * 
 * This function clears queued incoming and outgoing packets.
 *
 * @param {string} local_user_id The Product User ID of the local user for whom we want to clear the queued packets
 * @param {string} remote_user_id The Product User ID to who (outgoing) or from who (incoming) packets are queued
 * @param {string} socket_name The socket used for packets to be cleared
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_close_connection
 * @desc **Epic Online Services Function:** [EOS_P2P_CloseConnection](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-close-connection)
 * 
 * For all (or optionally one specific) Socket ID(s) with a specific peer: stop receiving packets, drop any locally queued packets, and if no other Socket ID is using the connection with the peer, close the underlying connection. If your application wants to migrate an existing connection with a peer it already connected to, it is recommended to call ${function.eos_p2p_accept_connection} with the new Socket ID first before calling $ {function.eos_p2p_close_connection}, to prevent the shared physical socket from being torn down prematurely.
 * 
 * The function returns `EOS_RESULT.SUCCESS` if the provided data is valid, `EOS_RESULT.INVALID_PARAMETERS` otherwise.
 *
 * @param {string} local_user_id The Product User ID of the local user who would like to close a previously accepted connection (or decline a pending invite)
 * @param {string} remote_user_id The Product User ID of the remote user to disconnect from (or to reject a pending invite from)
 * @param {string} socket_name The socket ID of the connection to close (or optionally an empty string to not accept any connection requests from the Remote User)
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_close_connections
 * @desc **Epic Online Services Function:** [EOS_P2P_CloseConnections](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-close-connections)
 * 
 * This function closes any open Connections for a specific Peer Connection ID.
 * 
 * The function returns `EOS_RESULT.SUCCESS` if the provided data is valid, `EOS_RESULT.INVALID_PARAMETERS` otherwise.
 *
 * @param {string} local_user_id The Product User ID of the local user who would like to close all connections that use a particular socket ID
 * @param {string} socket_name The socket ID of the connections to close
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_get_nat_type
 * @desc **Epic Online Services Function:** [EOS_P2P_GetNATType](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-get-nat-type)
 *
 * This function gets the last queried NAT type, if it has been successfully queried with ${function.eos_p2p_query_nat_type} before.
 * 
 * The function returns the previously queried NAT type if cached data is available, or `EOS_NAT_TYPE.UNKNOWN` otherwise.
 *
 * @returns {constant.EOS_NAT_TYPE}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_get_next_received_packet_size
 * @desc **Epic Online Services Function:** [EOS_P2P_GetNextReceivedPacketSize](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-get-next-received-packet-size)
 * 
 * This function gets the size of the packet that will be returned by ${function.eos_p2p_receive_packet} for a particular user, if there are any available packets to be retrieved.
 * 
 * @param {string} local_user_id The Product User ID of the local user who is receiving the packet
 * @param {real} requested_channel The channel to request the data for, a value from 0 to 255 (inclusive). If a negative value is passed, we're retrieving the size of the next packet on any channel.
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_get_packet_queue_info
 * @desc **Epic Online Services Function:** [EOS_P2P_GetPacketQueueInfo](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-get-packet-queue-info)
 * 
 * This function gets the current cached information related to the incoming and outgoing packet queues. An empty struct is returned if the input was invalid in some way.
 * 
 * @returns {struct.PacketQueueInfo}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_get_port_range
 * @desc **Epic Online Services Function:** [EOS_P2P_GetPortRange](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-get-port-range)
 * 
 * This function gets the current chosen port and the number of other ports to try above the chosen port if the chosen port is unavailable.
 * 
 * The function returns a struct with two variables: `out_port` and `out_num_additional_ports_to_try`. An empty struct is returned if the input was invalid in some way.
 * 
 * @returns {struct}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_get_relay_control
 * @desc **Epic Online Services Function:** [EOS_P2P_GetRelayControl](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-get-relay-control)
 *
 * This function gets the current relay control setting, or a negative value if the operation failed.
 *
 * @returns {constant.EOS_RELAY_CONTROL}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_query_nat_type
 * @desc **Epic Online Services Function:** [EOS_P2P_QueryNATType](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-query-nat-type)
 *
 * This function queries the current NAT-type of the connection. It returns an async ID.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_p2p_query_nat_type"`
 * @member {constant.EOS_RESULT} status The result code for the query
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the call to the function
 * @member {constant.EOS_NAT_TYPE} nat_type The queried NAT type
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_p2p_receive_packet
 * @desc **Epic Online Services Function:** [EOS_P2P_ReceivePacket](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-receive-packet)
 * 
 * This function receives the next packet for the local user, and information associated with this packet, if it exists.
 * 
 * The function returns the number of bytes written to the buffer if successful.
 *
 * @param {real} buff The buffer to write the data to
 * @param {string} local_user_id The Product User ID of the user who is receiving the packet
 * @param {real} max_data_size_bytes The maximum amount of data in bytes that can be safely copied to OutData in the function call
 * @param {real} requested_channel An optional channel to request the data for. If a value < 0 is passed, the next packet is retrieved on any channel
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_remove_notify_incoming_packet_queue_full
 * @desc **Epic Online Services Function:** [EOS_P2P_RemoveNotifyIncomingPacketQueueFull](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-remove-notify-incoming-packet-queue-full)
 * 
 * This function stops listening for full incoming packet queue events on a previously bound handler.
 * 
 * @param {real} notification_id The previously bound notification ID
 * 
 * @func_end
 */

/**
 * @func eos_p2p_remove_notify_peer_connection_closed
 * @desc **Epic Online Services Function:** [EOS_P2P_RemoveNotifyPeerConnectionClosed](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-closed)
 * 
 * This function stops notifications for connections being closed on a previously bound handler.
 * 
 * @param {real} notification_id The previously bound notification ID
 * 
 * @func_end
 */

/**
 * @func eos_p2p_remove_notify_peer_connection_established
 * @desc **Epic Online Services Function:** [EOS_P2P_RemoveNotifyPeerConnectionEstablished](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-established)
 * 
 * This function stops notifications for connections being established on a previously bound handler.
 *
 * @param {real} notification_id The previously bound notification ID
 * 
 * @func_end
 */

/**
 * @func eos_p2p_remove_notify_peer_connection_interrupted
 * @desc **Epic Online Services Function:** [EOS_P2P_RemoveNotifyPeerConnectionInterrupted](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-interrupted)
 * 
 * This function stops notifications for connections being interrupted on a previously bound handler.
 *
 * @param {real} notification_id The previously bound notification ID
 * 
 * @func_end
 */

/**
 * @func eos_p2p_remove_notify_peer_connection_request
 * @desc **Epic Online Services Function:** [EOS_P2P_RemoveNotifyPeerConnectionRequest](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-request)
 * 
 * This function stops listening for connection requests on a previously bound handler.
 *
 * @param {real} notification_id The previously bound notification ID
 * 
 * @func_end
 */

/**
 * @func eos_p2p_send_packet
 * @desc **Epic Online Services Function:** [EOS_P2P_SendPacket](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-send-packet)
 * 
 * This function sends a packet to a peer at the specified address. If there is already an open connection to this peer, it will be sent immediately. If there is no open connection, an attempt to connect to the peer will be made. An `EOS_RESULT.SUCCESS` result only means the data was accepted to be sent, not that it has been successfully delivered to the peer.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` - If the packet was queued to be sent successfully
 * * `EOS_RESULT.INVALID_PARAMETERS` - If the input was invalid
 * * `EOS_RESULT.LIMIT_EXCEEDED` - If the amount of data being sent is too large, or the outgoing packet queue was full
 * * `EOS_RESULT.NO_CONNECTION` -  If `disable_auto_accept_connection` was set to `true` and the connection was not currently accepted (call ${function.eos_p2p_accept_connection} first, or set `disable_auto_accept_connection` to `false`)
 * 
 * @param {bool} allow_delayed_delivery If `false` and we do not already have an established connection to the peer, this data will be dropped
 * @param {bool} disable_auto_accept_connection If set to `true`, ${function.eos_p2p_send_packet} will not automatically establish a connection with the `remote_user_id` and will require explicit calls to ${function.eos_p2p_accept_connection} first whenever the connection is closed. If set to `false`, ${function.eos_p2p_send_packet} will automatically accept and start the connection any time it is called and the connection is not already open.
 * @param {real} channel The channel associated with this data
 * @param {string} local_user_id The Product User ID of the local user who is sending this packet
 * @param {constant.EOS_PACKET_RELIABILITY} reliability Sets the reliability of the delivery of this packet.
 * @param {string} remote_user_id The Product User ID of the Peer you would like to send a packet to
 * @param {string} socket_name The socket ID for data you are sending in this packet
 * 
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_set_packet_queue_size
 * @desc **Epic Online Services Function:** [EOS_P2P_SetPacketQueueSize](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-set-packet-queue-size)
 * 
 * This function sets the maximum packet queue sizes that packets waiting to be sent or received can use. If the packet queue size is made smaller than the current queue size while there are packets in the queue that would push this packet size over, existing packets are kept but new packets may not be added to the full queue until enough packets are sent or received.
 * 
 * The function returns `EOS_RESULT.SUCCESS` if the input options were valid, or `EOS_RESULT.INVALID_PARAMETERS` if the input was invalid in some way.
 * 
 * @param {real} incoming_packet_queue_max_size_bytes The ideal maximum amount of bytes the incoming packet queue can consume
 * @param {real} outgoing_packet_queue_max_size_bytes The ideal maximum amount of bytes the outgoing packet queue can consume
 * 
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_set_port_range
 * @desc **Epic Online Services Function:** [EOS_P2P_SetPortRange](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-set-port-range)
 *
 * This function sets configuration options related to network ports.
 * 
 * It returns one of the following: 
 * 
 * * `EOS_RESULT.SUCCESS` - if the options were set successfully
 * * `EOS_RESULT.INVALID_PARAMETERS` - if the options are invalid in some way
 * 
 * @param {real} port The ideal port to use for P2P traffic. The default value is 7777. If set to 0, the OS will choose a port. If set to 0, `max_additional_ports_to_try` must be set to 0.
 * @param {real} max_additional_ports_to_try The maximum amount of additional ports to try if `port` is unavailable. Ports will be tried from `port` to `port + max_additional_ports_to_try` inclusive, until one is available or we run out of ports. If no ports are available, P2P connections will fail. The default value is 99.
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_set_relay_control
 * @desc **Epic Online Services Function:** [EOS_P2P_SetRelayControl](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-set-relay-control)
 * 
 * This function sets how relay servers are to be used. This setting does not immediately apply to existing connections, but may apply to existing connections if the connection requires renegotiation.
 * 
 * The function returns one of the following: 
 * 
 * * `EOS_RESULT.SUCCESS` - if the options were set successfully
 * * `EOS_RESULT.INVALID_PARAMETERS` - if the options are invalid in some way
 *
 * @param {constant.EOS_RELAY_CONTROL} relay_control The requested level of relay servers for P2P connections. This setting is only applied to new P2P connections, or when existing P2P connections reconnect during a temporary connectivity outage. Peers with an incompatible setting to the local setting will not be able to connect.
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

// Structs

/**
 * @struct PacketQueueInfo
 * @desc **Epic Online Services Struct:** [EOS_P2P_PacketQueueInfo](https://dev.epicgames.com/docs/api-ref/structs/eos-p-2-p-packet-queue-info)
 * 
 * This struct contains information related to the current state of the packet queues. It is possible for the current size to be larger than the maximum size if the maximum size changes or if the maximum queue size is set to `EOS_P2P_MAX_QUEUE_SIZE_UNLIMITED`.
 * 
 * @member {real} incoming_packet_queue_current_packet_count The current number of queued packets in the incoming packet queue
 * @member {real} incoming_packet_queue_current_size_bytes The current size in bytes of the incoming packet queue
 * @member {real} incoming_packet_queue_max_size_bytes The maximum size in bytes of the incoming packet queue
 * @member {real} outgoing_packet_queue_current_packet_count The current amount of queued packets in the outgoing packet queue
 * @member {real} outgoing_packet_queue_current_size_bytes The current size in bytes of the outgoing packet queue
 * @member {real} outgoing_packet_queue_max_size_bytes The maximum size in bytes of the outgoing packet queue
 * 
 * @struct_end
 */

// Constants & Enums

/**
 * @constant EOS_NAT_TYPE
 * @desc **Epic Online Services Enum:** [EOS_ENATType](https://dev.epicgames.com/docs/api-ref/enums/eos-enat-type)
 * 
 * This enum holds the possible categories of NAT strictness.
 * 
 * @member UNKNOWN The NAT type is either unknown (remote) or EOS is unable to determine it (local)
 * @member OPEN All peers can directly-connect to you
 * @member MODERATE You can directly-connect to other Moderate and Open peers
 * @member STRICT You can only directly-connect to Open peers
 * 
 * @constant_end
 */

/**
 * @constant EOS_CONNECTION_ESTABLISHED_TYPE
 * @desc **Epic Online Services Enum:** [EOS_EConnectionEstablishedType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-connection-established-type)
 * 
 * This enum holds the possible types of established connection.
 * 
 * @member NEW_CONNECTION The connection is brand new
 * @member RECONNECTION The connection is reestablished (reconnection)
 * 
 * @constant_end
 */

/**
 * @constant EOS_CONNECTION_CLOSED_REASON
 * @desc **Epic Online Services Enum:** [EOS_EConnectionClosedReason](https://dev.epicgames.com/docs/api-ref/enums/eos-e-connection-closed-reason)
 * 
 * This enum holds the possible reasons why a P2P connection was closed.
 * 
 * @member UNKNOWN The connection was closed for unknown reasons. This most notably happens during application shutdown.
 * @member CLOSED_BY_LOCAL_USER The connection was at least locally accepted, but was closed by the local user via a call to ${function.eos_p2p_close_connection} / ${function.eos_p2p_close_connections}.
 * @member CLOSED_BY_PEER The connection was at least locally accepted, but was gracefully closed by the remote user via a call to ${function.eos_p2p_close_connection} / ${function.eos_p2p_close_connections}.
 * @member TIMED_OUT The connection was at least locally accepted, but was not remotely accepted in time.
 * @member TOO_MANY_CONNECTIONS The connection was accepted, but the connection could not be created due to too many other existing connections.
 * @member INVALID_MESSAGE The connection was accepted, The remote user sent an invalid message.
 * @member INVALID_DATA The connection was accepted, but the remote user sent us invalid data.
 * @member CONNECTION_FAILED The connection was accepted, but we failed to ever establish a connection with the remote user due to connectivity issues.
 * @member CONNECTION_CLOSED The connection was accepted and established, but the peer silently went away.
 * @member NEGOTIATION_FAILED The connection was locally accepted, but we failed to negotiate a connection with the remote user. This most commonly occurs if the local user goes offline or is logged-out during the connection process.
 * @member UNEXPECTED_ERROR The connection was accepted, but there was an internal error occurred and the connection cannot be created or continue.
 * 
 * @constant_end
 */

/**
 * @constant EOS_NETWORK_CONNECTION_TYPE
 * @desc **Epic Online Services Enum:** [EOS_ENetworkConnectionType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-network-connection-type)
 * 
 * This enum holds the possible types of network connection.
 * 
 * @member NO_CONNECTION There is no established connection
 * @member DIRECT_CONNECTION A direct connection to the peer over the Internet or Local Network
 * @member RELAYED_CONNECTION A relayed connection using Epic-provided servers to the peer over the Internet
 * 
 * @constant_end
 */

/**
 * @constant EOS_PACKET_RELIABILITY
 * @desc **Epic Online Services Enum:** [EOS_EPacketReliability](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-packet-reliability)
 * 
 * This enum holds the different types of packet reliability. Ordered packets will only be ordered relative to other ordered packets. Reliable/unreliable and ordered/unordered communication can be sent on the same Socket ID and Channel.
 * 
 * @member UNRELIABLE_UNORDERED Packets will only be sent once and may be received out of order
 * @member RELIABLE_UNORDERED Packets may be sent multiple times and may be received out of order
 * @member RELIABLE_ORDERED Packets may be sent multiple times and will be received in order
 * 
 * @constant_end
 */

/**
 * @constant EOS_RELAY_CONTROL
 * @desc **Epic Online Services Enum:** [EOS_ERelayControl](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-relay-control)
 * 
 * This enum holds the possible settings for controlling whether relay servers are used. Please see the relay control value compatibility-chart in the Epic Online Services documentation to better understand how changing this value can affect compatibility between clients with different settings. Connections between clients using Incompatible settings may succeed in limited scenarios but should be treated as though they will consistently fail.
 * 
 * @member NO_RELAYS Peer connections will never attempt to use relay servers. Clients with restrictive NATs may not be able to connect to peers.
 * @member ALLOW_RELAYS Peer connections will attempt to use relay servers, but only after direct connection attempts fail. This is the default value if not changed.
 * @member FORCE_RELAYS Peer connections will only ever use relay servers. This will add latency to all connections, but will hide IP Addresses from peers.
 * 
 * @constant_end
 */