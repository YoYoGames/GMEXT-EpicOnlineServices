/**
 * @module p2p
 * @title P2P
 * @desc **Epic Online Services Interface**: [P2P Interface](https://dev.epicgames.com/docs/en-US/api-ref/interfaces/p-2-p)
 * 
 * This module contains functionality to interact with the [NAT P2P Interface](https://dev.epicgames.com/docs/game-services/p-2-p), which has functionality to send and receive data between users, and related networking functionality.
 * 
 * @section_func
 * @desc The following are the functions of the P2P module:
 * @ref eos_p2p_*
 * @section_end
 * 
 * @module_end
 */

/**
 * @func eos_p2p_accept_connection
 * @desc **Epic Online Services Function:** [EOS_P2P_AcceptConnection](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-accept-connection)
 * 
 * This function accepts or requests a connection with a specific peer on a specific Socket ID. If this connection was not already locally accepted, Epic Games will securely message the peer, and trigger a PeerConnectionRequest notification notifying them of the connection request. If the PeerConnectionRequest notification is not bound for all Socket IDs or for the requested Socket ID in particular, the request will be silently ignored. If the remote peer accepts the connection, a notification will be broadcast to the ${function.eos_p2p_add_notify_peer_connection_established} when the connection is ready to send packets. If multiple Socket IDs are accepted with one peer, they will share one physical socket. Even if a connection is already locally accepted, `EOS_Success` will still be returned if the input was valid. `EOS_InvalidParameters` will be returned if the input is invalid.
 *
 * @param {string} local_user_id The Product User ID of the local user who is accepting any pending or future connections with `remote_user_id`
 * @param {string} remote_user_id The Product User ID of the remote user who has either sent a connection request or is expected to in the future
 * @param {string} socket_name The socket ID of the connection to accept on
 *
 * @returns {constant.eos_result}
 * 
 * @func_end
 */

/**
 * @struct PacketQueueInfo
 * @desc 
 * 
 * @member {real} incoming_packet_queue_current_packet_count 
 * @member {real} incoming_packet_queue_current_size_bytes 
 * @member {real} incoming_packet_queue_max_size_bytes 
 * @member {real} outgoing_packet_queue_current_packet_count 
 * @member {real} outgoing_packet_queue_current_size_bytes 
 * @member {real} outgoing_packet_queue_max_size_bytes 
 * 
 * @struct_end
 */

/**
 * @func eos_p2p_add_notify_incoming_packet_queue_full
 * @desc **Epic Online Services Function:** [EOS_P2P_AddNotifyIncomingPacketQueueFull](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-add-notify-incoming-packet-queue-full)
 * 
 * This function listens for when the packet queue has become full. This event gives an opportunity to read packets to make room for new incoming packets. If this event fires and no packets are read by calling ${function.eos_p2p_receive_packet} or the packet queue size is not increased by ${function.eos_p2p_set_packet_queue_size}, any packets that are received after this event are discarded until there is room again in the queue.
 * 
 * @returns {struct.PacketQueueInfo}
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
 * The function returns a valid notification ID if successfully bound, or EOS_INVALID_NOTIFICATIONID otherwise.
 * 
 * @param {string} local_user_id The Product User ID of the local user who would like notifications
 * @param {string} socket_name The optional socket ID to listen for to be closed. If not provided, this function handler will be called for all closed connections.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_p2p_add_notify_peer_connection_closed"`
 * @member {string} local_user_id The local user who is being notified of a connection being closed
 * @member {real} reason The reason the connection was closed (if known)
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
 * This function listens for when a connection is established. This is fired when we first connect to a peer, when we reconnect to a peer after a connection interruption, and when our underlying network connection type changes (for example, from a direct connection to relay, or vice versa). Network Connection Type changes will always be broadcast with a EOS_CET_Reconnection connection type, even if the connection was not interrupted. If the network status changes from offline to online, you must call this function again.
 * 
 * @param {string} local_user_id The Product User ID of the local user who would like to receive notifications
 * @param {string} socket_name The optional socket ID, used as a filter for established connections. If NULL, this function handler will be called for all sockets.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_p2p_add_notify_peer_connection_established"`
 * @member {string} local_user_id The Product User ID of the local user who is being notified of a connection being established
 * @member {real} status 
 * @member {real} connection_type Information if this is a new connection or reconnection
 * @member {real} network_type What type of network connection is being used for this connection
 * @member {string} socket_id The socket ID of the connection being established
 * @member {string} remote_user_id The Product User ID of the remote user who this connection was with
	
 * @func_end
 */

/**
 * @func eos_p2p_add_notify_peer_connection_interrupted
 * @desc **Epic Online Services Function:** [EOS_P2P_AddNotifyPeerConnectionInterrupted](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-add-notify-peer-connection-interrupted)
 * 
 * This function listens for when a previously opened connection is interrupted. The connection will automatically attempt to reestablish, but it may not be successful. If a connection reconnects, it will trigger the P2P PeerConnectionEstablished notification with the EOS_CET_Reconnection connection type. If a connection fails to reconnect, it will trigger the P2P PeerConnectionClosed notification. Packets remain queued during connection interruptions. When a connection closes, packets are flushed. This includes reliable packets.
 *
 * @param {string} local_user_id The Product User ID of the local user who would like notifications
 * @param {string} socket_name An optional socket ID to filter interrupted connections on. If NULL, this function handler will be called for all interrupted connections
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
 * @param {string} local_user_id The Product User ID of the user who is listening for incoming connection requests
 * @param {string} socket_name The optional socket ID to listen for, used as a filter for incoming connection requests; If NULL, incoming connection requests will not be filtered
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
 * @returns {constant.eos_result}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_close_connection
 * @desc **Epic Online Services Function:** [EOS_P2P_CloseConnection](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-close-connection)
 * 
 * For all (or optionally one specific) Socket ID(s) with a specific peer: stop receiving packets, drop any locally queued packets, and if no other Socket ID is using the connection with the peer, close the underlying connection. If your application wants to migrate an existing connection with a peer it already connected to, it is recommended to call ${function.eos_p2p_accept_connection} with the new Socket ID first before calling $ {function.eos_p2p_close_connection}, to prevent the shared physical socket from being torn down prematurely.
 * 
 * The function returns `EOS_Success` if the provided data is valid, `EOS_InvalidParameters` otherwise.
 *
 * @param {string} local_user_id The Product User ID of the local user who would like to close a previously accepted connection (or decline a pending invite)
 * @param {string} remote_user_id The Product User ID of the remote user to disconnect from (or to reject a pending invite from)
 * @param {string} socket_name The socket ID of the connection to close (or optionally NULL to not accept any connection requests from the Remote User)
 *
 * @returns {constant.eos_result}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_close_connections
 * @desc **Epic Online Services Function:** [EOS_P2P_CloseConnections](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-close-connections)
 * 
 * This function closes any open Connections for a specific Peer Connection ID.
 * 
 * The function returns `EOS_Success` if the provided data is valid, `EOS_InvalidParameters` otherwise.
 *
 * @param {string} local_user_id The Product User ID of the local user who would like to close all connections that use a particular socket ID
 * @param {string} socket_name The socket ID of the connections to close
 *
 * @returns {constant.eos_result}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_get_nat_type
 * @desc **Epic Online Services Function:** [EOS_P2P_GetNATType](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-get-nat-type)
 *
 * This function gets the last-queried NAT-type, if it has been successfully queried.
 * 
 * The function returns `EOS_Success` if cached data is available, `EOS_NotFound` otherwise.
 *
 * @returns {constant.eos_result}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_get_next_received_packet_size
 * @desc **Epic Online Services Function:** [EOS_P2P_GetNextReceivedPacketSize](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-get-next-received-packet-size)
 * 
 * This function gets the size of the packet that will be returned by $ {function.eos_p2p_receive_packet} for a particular user, if there are any available packets to be retrieved.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Success` - If OutPacketSizeBytes was successfully set and there is data to be received
 * * `EOS_InvalidParameters` -  If the input was invalid
 * * `EOS_NotFound` - If there are no packets available for the requesting user
 * 
 * @param {string} local_user_id The Product User ID of the local user who is receiving the packet
 *
 * @returns {constant.eos_result}
 * 
 * @func_end
 */

/**
 * @struct PacketQueueInfo
 * @desc 
 * 
 * @member {real} incoming_packet_queue_current_packet_count 
 * @member {real} incoming_packet_queue_current_size_bytes 
 * @member {real} incoming_packet_queue_max_size_bytes 
 * @member {real} outgoing_packet_queue_current_packet_count 
 * @member {real} outgoing_packet_queue_current_size_bytes 
 * @member {real} outgoing_packet_queue_max_size_bytes 
 * 
 * @struct_end
 */

/**
 * @func eos_p2p_get_packet_queue_info
 * @desc **Epic Online Services Function:** [EOS_P2P_GetPacketQueueInfo](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-get-packet-queue-info)
 * 
 * This function gets the current cached information related to the incoming and outgoing packet queues.
 * 
 * @returns {struct.PacketQueueInfo}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_get_port_range
 * @desc **Epic Online Services Function:** [EOS_P2P_GetPortRange](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-get-port-range)
 * 
 * This function gets the current chosen port and the amount of other ports to try above the chosen port if the chosen port is unavailable.
 * 
 * @returns {constant.eos_result}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_get_relay_control
 * @desc **Epic Online Services Function:** [EOS_P2P_GetRelayControl](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-get-relay-control)
 *
 * This function gets the current relay control setting.
 *
 * @returns {constant.eos_result}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_query_nat_type
 * @desc **Epic Online Services Function:** [EOS_P2P_QueryNATType](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-query-nat-type)
 *
 * This function queries the current NAT-type of the connection. It returns the async ID.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_p2p_query_nat_type"`
 * @member {constant.eos_result} status 
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier 
 * @member {constant.eos_nattype} nat_type The queried NAT type
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
 * @param {real} buff_adress 
 * @param {string} local_user_id The Product User ID of the user who is receiving the packet
 * @param {real} max_data_size_bytes The maximum amount of data in bytes that can be safely copied to OutData in the function call
 * @param {real} requested_channel An optional channel to request the data for. If NULL, we're retrieving the next packet on any channel
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
 * @param {int64} notification_id The previously bound notification ID
 * 
 * @func_end
 */

/**
 * @func eos_p2p_remove_notify_peer_connection_closed
 * @desc **Epic Online Services Function:** [EOS_P2P_RemoveNotifyPeerConnectionClosed](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-closed)
 * 
 * This function stops notifications for connections being closed on a previously bound handler.
 * 
 * @param {int64} notification_id The previously bound notification ID
 * 
 * @func_end
 */

/**
 * @func eos_p2p_remove_notify_peer_connection_established
 * @desc **Epic Online Services Function:** [EOS_P2P_RemoveNotifyPeerConnectionEstablished](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-established)
 * 
 * This function stops notifications for connections being established on a previously bound handler.
 *
 * @param {int64} notification_id The previously bound notification ID
 * 
 * @func_end
 */

/**
 * @func eos_p2p_remove_notify_peer_connection_interrupted
 * @desc **Epic Online Services Function:** [EOS_P2P_RemoveNotifyPeerConnectionInterrupted](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-interrupted)
 * 
 * This function stops notifications for connections being interrupted on a previously bound handler.
 *
 * @param {int64} notification_id The previously bound notification ID
 * 
 * @func_end
 */

/**
 * @func eos_p2p_remove_notify_peer_connection_request
 * @desc **Epic Online Services Function:** [EOS_P2P_RemoveNotifyPeerConnectionRequest](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-request)
 * 
 * This function stops listening for connection requests on a previously bound handler.
 *
 * @param {int64} notification_id The previously bound notification ID
 * 
 * @func_end
 */

/**
 * @func eos_p2p_send_packet
 * @desc **Epic Online Services Function:** [EOS_P2P_SendPacket](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-send-packet)
 * 
 * This function sends a packet to a peer at the specified address. If there is already an open connection to this peer, it will be sent immediately. If there is no open connection, an attempt to connect to the peer will be made. An EOS_Success result only means the data was accepted to be sent, not that it has been successfully delivered to the peer.
 * 
 * The function returns one of the following:
 * 
 * * EOS_Success - If the packet was queued to be sent successfully
 * * EOS_InvalidParameters - If the input was invalid
 * * EOS_LimitExceeded - If the amount of data being sent is too large, or the outgoing packet queue was full
 * * EOS_NoConnection -  If `disable_auto_accept_connection` was set to `true` and the connection was not currently accepted (call ${function.eos_p2p_accept_connection} first, or set `disable_auto_accept_connection` to `false`)
 * 
 * @param {bool} allow_delayed_delivery If `false` and we do not already have an established connection to the peer, this data will be dropped
 * @param {bool} disable_auto_accept_connection If set to `true`, ${function.eos_p2p_send_packet} will not automatically establish a connection with the `remote_user_id` and will require explicit calls to ${function.eos_p2p_accept_connection} first whenever the connection is closed. If set to `false`, ${function.eos_p2p_send_packet} will automatically accept and start the connection any time it is called and the connection is not already open.
 * @param {real} channel The channel associated with this data
 * @param {string} local_user_id The Product User ID of the local user who is sending this packet
 * @param {EOS_PacketReliability} reliability Sets the reliability of the delivery of this packet. The reliability can be EOS_PR_UnreliableUnordered, EOS_PR_ReliableUnordered, or EOS_PR_ReliableOrdered.
 * @param {string} remote_user_id The Product User ID of the Peer you would like to send a packet to
 * @param {buffer_string} socket_name The socket ID for data you are sending in this packet
 * 
 * @returns {constant.eos_result}
 * 
 * @func_end
 */

/**
 * @func eos_p2p_set_packet_queue_size
 * @desc **Epic Online Services Function:** [EOS_P2P_SetPacketQueueSize](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-set-packet-queue-size)
 * 
 * This function sets the maximum packet queue sizes that packets waiting to be sent or received can use. If the packet queue size is made smaller than the current queue size while there are packets in the queue that would push this packet size over, existing packets are kept but new packets may not be added to the full queue until enough packets are sent or received.
 * 
 * The function returns EOS_Success if the input options were valid, or EOS_InvalidParameters if the input was invalid in some way.
 * 
 * @param {real} incoming_packet_queue_max_size_bytes The ideal maximum amount of bytes the incoming packet queue can consume
 * @param {real} outgoing_packet_queue_max_size_bytes The ideal maximum amount of bytes the outgoing packet queue can consume
 * 
 * @returns {constant.eos_result}
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
 * * EOS_Success - if the options were set successfully
 * * EOS_InvalidParameters - if the options are invalid in some way
 * 
 * @param {real} port The ideal port to use for P2P traffic. The default value is 7777. If set to 0, the OS will choose a port. If set to 0, `max_additional_ports_to_try` must be set to 0.
 * @param {real} max_additional_ports_to_try The maximum amount of additional ports to try if `port` is unavailable. Ports will be tried from `port` to `port + max_additional_ports_to_try` inclusive, until one is available or we run out of ports. If no ports are available, P2P connections will fail. The default value is 99.
 *
 * @returns {constant.eos_result}
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
 * * EOS_Success - if the options were set successfully
 * * EOS_InvalidParameters - if the options are invalid in some way
 *
 * @param {real} relay_control The requested level of relay servers for P2P connections. This setting is only applied to new P2P connections, or when existing P2P connections reconnect during a temporary connectivity outage. Peers with an incompatible setting to the local setting will not be able to connect.
 *
 * @returns {constant.eos_success}
 * 
 * @func_end
 */
