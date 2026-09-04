// Structs

/**
 * @struct EpicP2PReceivedPacket
 * @desc Returned by ${function.eos_p2p_receive_packet} when a packet was available and successfully copied into the caller's buffer.
 *
 * @member {String} peer_id The Product User ID of the remote user who sent this packet.
 * @member {String} socket_name The socket ID the packet was sent on.
 * @member {Real} channel The channel the packet was sent on.
 * @member {Bool} ok Whether the packet was read successfully.
 * @member {Real} bytes_written The number of bytes written into the caller's `out_data` buffer.
 *
 * @struct_end
 */

/**
 * @struct EpicP2PQueryNATTypeCallbackInfo
 * @desc Passed to the callback of ${function.eos_p2p_query_nat_type}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {Constant.EpicNATType} nat_type
 *
 * @struct_end
 */

/**
 * @struct EpicP2PConnectionRequestCallbackInfo
 * @desc Passed to the callback of ${function.eos_p2p_add_notify_peer_connection_request}.
 *
 * @member {String} local_user_id The Product User ID of the local user being asked to open a P2P connection.
 * @member {String} remote_user_id The Product User ID of the remote user requesting the connection.
 * @member {String} socket_name The socket ID the remote user wants to communicate on.
 *
 * @struct_end
 */

/**
 * @struct EpicP2PConnectionEstablishedCallbackInfo
 * @desc Passed to the callback of ${function.eos_p2p_add_notify_peer_connection_established}.
 *
 * @member {String} local_user_id The Product User ID of the local user being notified.
 * @member {String} remote_user_id The Product User ID of the remote user this connection is with.
 * @member {String} socket_name The socket ID of the connection.
 * @member {Constant.EpicConnectionEstablishedType} connection_type Whether this is a new connection or a reconnection.
 * @member {Constant.EpicNetworkConnectionType} network_type The kind of network path being used.
 *
 * @struct_end
 */

/**
 * @struct EpicP2PConnectionInterruptedCallbackInfo
 * @desc Passed to the callback of ${function.eos_p2p_add_notify_peer_connection_interrupted}.
 *
 * @member {String} local_user_id The Product User ID of the local user being notified.
 * @member {String} remote_user_id The Product User ID of the remote user this connection is with.
 * @member {String} socket_name The socket ID of the connection.
 *
 * @struct_end
 */

/**
 * @struct EpicP2PConnectionClosedCallbackInfo
 * @desc Passed to the callback of ${function.eos_p2p_add_notify_peer_connection_closed}.
 *
 * @member {String} local_user_id The Product User ID of the local user being notified.
 * @member {String} remote_user_id The Product User ID of the remote user this connection was with.
 * @member {String} socket_name The socket ID of the connection.
 * @member {Constant.EpicConnectionClosedReason} reason The reason the connection closed, if known.
 *
 * @struct_end
 */

/**
 * @struct EpicP2PPacketQueueInfo
 * @desc **Epic Online Services Struct:** [EOS_P2P_PacketQueueInfo](https://dev.epicgames.com/docs/api-ref/structs/eos-p-2-p-packet-queue-info)
 *
 * Returned by ${function.eos_p2p_get_packet_queue_info}. It's possible for a `current_size_bytes` value to be larger than its matching `max_size_bytes` if the maximum size changes, or if it was set to unlimited.
 *
 * @member {Real} incoming_packet_queue_max_size_bytes The maximum size in bytes of the incoming packet queue.
 * @member {Real} incoming_packet_queue_current_size_bytes The current size in bytes of the incoming packet queue.
 * @member {Real} incoming_packet_queue_current_packet_count The current number of queued packets in the incoming packet queue.
 * @member {Real} outgoing_packet_queue_max_size_bytes The maximum size in bytes of the outgoing packet queue.
 * @member {Real} outgoing_packet_queue_current_size_bytes The current size in bytes of the outgoing packet queue.
 * @member {Real} outgoing_packet_queue_current_packet_count The current number of queued packets in the outgoing packet queue.
 *
 * @struct_end
 */

/**
 * @struct EpicP2PPortRange
 * @desc Returned by ${function.eos_p2p_get_port_range}.
 *
 * @member {Real} port The currently configured preferred port.
 * @member {Real} num_additional_ports_to_try The number of ports above `port` that will also be tried if `port` is unavailable.
 *
 * @struct_end
 */

/**
 * @struct EpicP2PIncomingPacketQueueFullCallbackInfo
 * @desc Passed to the callback of ${function.eos_p2p_add_notify_incoming_packet_queue_full}.
 *
 * @member {Real} packet_queue_max_size_bytes The maximum size in bytes the incoming packet queue is allowed to use.
 * @member {Real} packet_queue_current_size_bytes The current size in bytes the incoming packet queue is using.
 * @member {String} overflow_packet_local_user_id The Product User ID of the local user who is receiving the packet that would overflow the queue.
 * @member {Real} overflow_packet_channel The channel the overflowing packet is for.
 * @member {Real} overflow_packet_size_bytes The size in bytes of the incoming packet (and related metadata) that would overflow the queue.
 *
 * @struct_end
 */


// Functions

/**
 * @function eos_p2p_send_packet
 * @desc **Epic Online Services Function:** [EOS_P2P_SendPacket](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-send-packet)
 *
 * Sends a packet to a peer at the specified socket. If there is already an open connection to this peer, the packet is sent immediately; otherwise a connection attempt is made. A `EpicResult.Success` result only means the data was accepted to be queued for sending, not that it has been delivered.
 *
 * @param {String} local_user_id The Product User ID of the local user sending this packet.
 * @param {String} remote_user_id The Product User ID of the peer to send the packet to.
 * @param {String} socket_name The socket ID for the data being sent.
 * @param {Real} channel The channel associated with this data.
 * @param {Buffer} data A buffer holding at least `bytes` bytes to send.
 * @param {Real} bytes The number of bytes from `data` to send. Must not exceed the buffer's length, and must not exceed `EOS_P2P_MAX_PACKET_SIZE`.
 * @param {Bool} allow_delayed_delivery If `false` and there isn't already an established connection to the peer, this packet is dropped instead of being queued while the connection is negotiated.
 * @param {Constant.EpicPacketReliability} reliability The reliability/ordering guarantee for this packet.
 * @param {Bool} disable_auto_accept_connection If `true`, this call won't automatically establish a connection with `remote_user_id` - call ${function.eos_p2p_accept_connection} first, or the packet is dropped with `EpicResult.NoConnection`. If `false` (the default), a connection is opened automatically the first time this is called for a given peer.
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_p2p_get_next_received_packet_size
 * @desc **Epic Online Services Function:** [EOS_P2P_GetNextReceivedPacketSize](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-get-next-received-packet-size)
 *
 * Gets the size of the next packet ${function.eos_p2p_receive_packet} would return for a particular user, if one is available.
 *
 * [[Note: Returns `-1` if no packet is available, or on error.]]
 *
 * @param {String} local_user_id The Product User ID of the local user receiving the packet.
 * @param {Real} channel The channel to check, `0`-`255`. Pass a negative value to check for the next packet on any channel.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_p2p_receive_packet
 * @desc **Epic Online Services Function:** [EOS_P2P_ReceivePacket](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-receive-packet)
 *
 * Reads the next queued packet for the local user into `out_data`, if one exists.
 *
 * [[Note: Returns `undefined` if no packet is available, or if `out_data` doesn't have enough room (starting at `offset`) for the packet's bytes.]]
 *
 * @param {String} local_user_id The Product User ID of the user receiving the packet.
 * @param {Buffer} out_data The buffer the packet's bytes are written into.
 * @param {Real} max_bytes The maximum number of bytes to request from the SDK for this call. Pass `0` to use `EOS_P2P_MAX_PACKET_SIZE`.
 * @param {Real} offset The offset in `out_data` to start writing at.
 * @param {Real} channel The channel to read from, `0`-`255`. Pass a negative value to read the next packet on any channel.
 *
 * @returns {Struct.EpicP2PReceivedPacket}
 *
 * @example
 * ```gml
 * var _size = eos_p2p_get_next_received_packet_size(my_id, -1);
 * if (_size > 0)
 * {
 *     var _buf = buffer_create(_size, buffer_fixed, 1);
 *     var _packet = eos_p2p_receive_packet(my_id, _buf, _size, 0, -1);
 *     if (!is_undefined(_packet))
 *     {
 *         show_debug_message($"Got {_packet.bytes_written} bytes from {_packet.peer_id}");
 *     }
 *     buffer_delete(_buf);
 * }
 * ```
 * @function_end
 */

/**
 * @function eos_p2p_accept_connection
 * @desc **Epic Online Services Function:** [EOS_P2P_AcceptConnection](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-accept-connection)
 *
 * Accepts or requests a connection with a specific peer on a specific socket ID. If the connection wasn't already locally accepted, EOS securely messages the peer and triggers a ${function.eos_p2p_add_notify_peer_connection_request} notification for them. If the remote peer accepts, ${function.eos_p2p_add_notify_peer_connection_established} fires once the connection is ready to send packets. Multiple socket IDs accepted with the same peer share one physical connection.
 *
 * @param {String} local_user_id The Product User ID of the local user accepting the connection.
 * @param {String} remote_user_id The Product User ID of the remote user.
 * @param {String} socket_name The socket ID of the connection to accept.
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_p2p_close_connection
 * @desc **Epic Online Services Function:** [EOS_P2P_CloseConnection](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-close-connection)
 *
 * Stops receiving packets on a specific socket ID with a specific peer, drops any locally queued packets for it, and - if no other socket ID is using the underlying connection with that peer - closes it. If you want to migrate an existing connection to a new socket ID, call ${function.eos_p2p_accept_connection} with the new socket ID before closing the old one, so the shared physical connection isn't torn down prematurely.
 *
 * [[Note: Pass an empty string for `socket_name` to close every socket with `remote_user_id`.]]
 *
 * @param {String} local_user_id The Product User ID of the local user closing the connection.
 * @param {String} remote_user_id The Product User ID of the remote user to disconnect from.
 * @param {String} socket_name The socket ID of the connection to close, or an empty string for all sockets with this peer.
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_p2p_close_connections
 * @desc **Epic Online Services Function:** [EOS_P2P_CloseConnections](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-close-connections)
 *
 * Closes every open connection using a specific socket ID, across all remote peers.
 *
 * @param {String} local_user_id The Product User ID of the local user closing the connections.
 * @param {String} socket_name The socket ID of the connections to close.
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_p2p_query_nat_type
 * @desc **Epic Online Services Function:** [EOS_P2P_QueryNATType](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-query-nat-type)
 *
 * Queries the current NAT strictness of the local connection. Once complete, read the result with ${function.eos_p2p_get_nat_type}.
 *
 * @param {Function} [callback] Called once the query completes.
 *
 * @event callback
 * @desc Fired once with the query result.
 * @member {Struct.EpicP2PQueryNATTypeCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_p2p_get_nat_type
 * @desc **Epic Online Services Function:** [EOS_P2P_GetNATType](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-get-nat-type)
 *
 * Gets the last NAT type successfully queried with ${function.eos_p2p_query_nat_type}.
 *
 * [[Note: Returns `EpicNATType.Unknown` if it hasn't been queried yet.]]
 *
 * @returns {Constant.EpicNATType}
 *
 * @function_end
 */

/**
 * @function eos_p2p_set_relay_control
 * @desc **Epic Online Services Function:** [EOS_P2P_SetRelayControl](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-set-relay-control)
 *
 * Sets how relay servers are used for P2P connections. This only affects new connections, or existing connections that renegotiate (e.g. after a temporary connectivity outage) - it doesn't apply retroactively to already-established connections. Peers with incompatible relay settings won't be able to connect to each other.
 *
 * @param {Constant.EpicRelayControl} relay_control
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_p2p_get_relay_control
 * @desc **Epic Online Services Function:** [EOS_P2P_GetRelayControl](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-get-relay-control)
 *
 * Gets the currently configured relay control setting.
 *
 * @returns {Constant.EpicRelayControl}
 *
 * @function_end
 */

/**
 * @function eos_p2p_set_port_range
 * @desc **Epic Online Services Function:** [EOS_P2P_SetPortRange](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-set-port-range)
 *
 * Sets the preferred port and fallback range for P2P traffic.
 *
 * @param {Real} port The preferred port to use. Default is `7777`. Pass `0` to let the OS choose a port - in that case `max_additional_ports_to_try` must also be `0`.
 * @param {Real} max_additional_ports_to_try The number of additional ports above `port` to try if `port` is unavailable (tried from `port` to `port + max_additional_ports_to_try`). Default is `99`.
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_p2p_get_port_range
 * @desc **Epic Online Services Function:** [EOS_P2P_GetPortRange](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-get-port-range)
 *
 * Gets the currently configured port and additional-ports-to-try count.
 *
 * @returns {Struct.EpicP2PPortRange}
 *
 * @function_end
 */

/**
 * @function eos_p2p_set_packet_queue_size
 * @desc **Epic Online Services Function:** [EOS_P2P_SetPacketQueueSize](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-set-packet-queue-size)
 *
 * Sets the maximum size, in bytes, of the incoming and outgoing packet queues. If a queue is shrunk below its current size, already-queued packets are kept, but no new packets can be added until enough are sent or received to make room.
 *
 * @param {Real} incoming_max_bytes The maximum size in bytes the incoming packet queue may use.
 * @param {Real} outgoing_max_bytes The maximum size in bytes the outgoing packet queue may use.
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_p2p_get_packet_queue_info
 * @desc **Epic Online Services Function:** [EOS_P2P_GetPacketQueueInfo](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-get-packet-queue-info)
 *
 * Gets the current state of the incoming and outgoing packet queues.
 *
 * @returns {Struct.EpicP2PPacketQueueInfo}
 *
 * @function_end
 */

/**
 * @function eos_p2p_clear_packet_queue
 * @desc **Epic Online Services Function:** [EOS_P2P_ClearPacketQueue](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-clear-packet-queue)
 *
 * Clears queued incoming and outgoing packets between the local user and a specific peer on a specific socket.
 *
 * @param {String} local_user_id The Product User ID of the local user whose queued packets should be cleared.
 * @param {String} remote_user_id The Product User ID the packets are queued to/from.
 * @param {String} socket_name The socket the packets are queued on.
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_p2p_add_notify_peer_connection_request
 * @desc **Epic Online Services Function:** [EOS_P2P_AddNotifyPeerConnectionRequest](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-add-notify-peer-connection-request)
 *
 * Registers to be notified of incoming connection requests on a socket ID (or all socket IDs). The callback only fires for connections that haven't already been accepted. If the network status changes from offline to online, register this again.
 *
 * [[Note: Returns `0` if registration failed.]]
 *
 * @param {String} local_user_id The Product User ID listening for incoming connection requests.
 * @param {String} socket_name The socket ID to filter on, or an empty string to receive requests for every socket.
 * @param {Function} [callback] Called every time a matching connection request arrives.
 *
 * @returns {Real}
 *
 * @event callback
 * @desc Fired every time a matching connection request arrives, for as long as this notification stays registered.
 * @member {Struct.EpicP2PConnectionRequestCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_p2p_remove_notify_peer_connection_request
 * @desc **Epic Online Services Function:** [EOS_P2P_RemoveNotifyPeerConnectionRequest](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-request)
 *
 * Unregisters a notification previously registered with ${function.eos_p2p_add_notify_peer_connection_request}.
 *
 * @param {Real} notification_id
 *
 * @function_end
 */

/**
 * @function eos_p2p_add_notify_peer_connection_established
 * @desc **Epic Online Services Function:** [EOS_P2P_AddNotifyPeerConnectionEstablished](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-add-notify-peer-connection-established)
 *
 * Registers to be notified when a connection is established - the first time it connects, after reconnecting from an interruption, and whenever the underlying network path changes (e.g. direct to relayed or vice versa; a path change is always reported with `EpicConnectionEstablishedType.Reconnection`, even if the connection itself was never interrupted). If the network status changes from offline to online, register this again.
 *
 * [[Note: Returns `0` if registration failed.]]
 *
 * @param {String} local_user_id The Product User ID listening for this notification.
 * @param {String} socket_name The socket ID to filter on, or an empty string to receive notifications for every socket.
 * @param {Function} [callback] Called every time a matching connection is established.
 *
 * @returns {Real}
 *
 * @event callback
 * @desc Fired every time a matching connection is established, for as long as this notification stays registered.
 * @member {Struct.EpicP2PConnectionEstablishedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_p2p_remove_notify_peer_connection_established
 * @desc **Epic Online Services Function:** [EOS_P2P_RemoveNotifyPeerConnectionEstablished](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-established)
 *
 * Unregisters a notification previously registered with ${function.eos_p2p_add_notify_peer_connection_established}.
 *
 * @param {Real} notification_id
 *
 * @function_end
 */

/**
 * @function eos_p2p_add_notify_peer_connection_interrupted
 * @desc **Epic Online Services Function:** [EOS_P2P_AddNotifyPeerConnectionInterrupted](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-add-notify-peer-connection-interrupted)
 *
 * Registers to be notified when a previously open or pending connection is interrupted. EOS automatically attempts to reestablish it - a successful reconnect fires ${function.eos_p2p_add_notify_peer_connection_established} with `EpicConnectionEstablishedType.Reconnection`; a failed one fires ${function.eos_p2p_add_notify_peer_connection_closed} instead. Queued packets survive an interruption, but are flushed once the connection actually closes.
 *
 * [[Note: Returns `0` if registration failed.]]
 *
 * @param {String} local_user_id The Product User ID listening for this notification.
 * @param {String} socket_name The socket ID to filter on, or an empty string to receive notifications for every socket.
 * @param {Function} [callback] Called every time a matching connection is interrupted.
 *
 * @returns {Real}
 *
 * @event callback
 * @desc Fired every time a matching connection is interrupted, for as long as this notification stays registered.
 * @member {Struct.EpicP2PConnectionInterruptedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_p2p_remove_notify_peer_connection_interrupted
 * @desc **Epic Online Services Function:** [EOS_P2P_RemoveNotifyPeerConnectionInterrupted](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-interrupted)
 *
 * Unregisters a notification previously registered with ${function.eos_p2p_add_notify_peer_connection_interrupted}.
 *
 * @param {Real} notification_id
 *
 * @function_end
 */

/**
 * @function eos_p2p_add_notify_peer_connection_closed
 * @desc **Epic Online Services Function:** [EOS_P2P_AddNotifyPeerConnectionClosed](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-add-notify-peer-connection-closed)
 *
 * Registers to be notified when a previously open or pending connection closes. Closing a connection flushes its packets, including reliable ones still in flight.
 *
 * [[Note: Returns `0` if registration failed.]]
 *
 * @param {String} local_user_id The Product User ID listening for this notification.
 * @param {String} socket_name The socket ID to filter on, or an empty string to receive notifications for every socket.
 * @param {Function} [callback] Called every time a matching connection closes.
 *
 * @returns {Real}
 *
 * @event callback
 * @desc Fired every time a matching connection closes, for as long as this notification stays registered.
 * @member {Struct.EpicP2PConnectionClosedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_p2p_remove_notify_peer_connection_closed
 * @desc **Epic Online Services Function:** [EOS_P2P_RemoveNotifyPeerConnectionClosed](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-closed)
 *
 * Unregisters a notification previously registered with ${function.eos_p2p_add_notify_peer_connection_closed}.
 *
 * @param {Real} notification_id
 *
 * @function_end
 */

/**
 * @function eos_p2p_add_notify_incoming_packet_queue_full
 * @desc **Epic Online Services Function:** [EOS_P2P_AddNotifyIncomingPacketQueueFull](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-add-notify-incoming-packet-queue-full)
 *
 * Registers to be notified when the incoming packet queue becomes full, giving you a chance to drain it with ${function.eos_p2p_receive_packet} before new packets start being silently discarded. If nothing is read and the queue isn't grown via ${function.eos_p2p_set_packet_queue_size}, packets received after this fires are dropped until room frees up.
 *
 * [[Note: Returns `0` if registration failed.]]
 *
 * @param {Function} [callback] Called every time the incoming packet queue becomes full.
 *
 * @returns {Real}
 *
 * @event callback
 * @desc Fired every time the incoming packet queue becomes full, for as long as this notification stays registered.
 * @member {Struct.EpicP2PIncomingPacketQueueFullCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_p2p_remove_notify_incoming_packet_queue_full
 * @desc **Epic Online Services Function:** [EOS_P2P_RemoveNotifyIncomingPacketQueueFull](https://dev.epicgames.com/docs/api-ref/functions/eos-p-2-p-remove-notify-incoming-packet-queue-full)
 *
 * Unregisters a notification previously registered with ${function.eos_p2p_add_notify_incoming_packet_queue_full}.
 *
 * @param {Real} notification_id
 *
 * @function_end
 */


/**
 * @module p2p
 * @title P2P
 * @desc **Epic Online Services Interface:** [P2P Interface](https://dev.epicgames.com/docs/game-services/p-2-p)
 *
 * Send and receive data directly between authenticated users, typically for a multiplayer game's own transport layer. P2P connections are secure by default, using Datagram Transport Layer Security ([DTLS](https://en.wikipedia.org/wiki/Datagram_Transport_Layer_Security)).
 *
 * @section_func
 * @desc Provided functions:
 *
 * @ref eos_p2p_send_packet
 * @ref eos_p2p_get_next_received_packet_size
 * @ref eos_p2p_receive_packet
 * @ref eos_p2p_accept_connection
 * @ref eos_p2p_close_connection
 * @ref eos_p2p_close_connections
 * @ref eos_p2p_query_nat_type
 * @ref eos_p2p_get_nat_type
 * @ref eos_p2p_set_relay_control
 * @ref eos_p2p_get_relay_control
 * @ref eos_p2p_set_port_range
 * @ref eos_p2p_get_port_range
 * @ref eos_p2p_set_packet_queue_size
 * @ref eos_p2p_get_packet_queue_info
 * @ref eos_p2p_clear_packet_queue
 * @ref eos_p2p_add_notify_peer_connection_request
 * @ref eos_p2p_remove_notify_peer_connection_request
 * @ref eos_p2p_add_notify_peer_connection_established
 * @ref eos_p2p_remove_notify_peer_connection_established
 * @ref eos_p2p_add_notify_peer_connection_interrupted
 * @ref eos_p2p_remove_notify_peer_connection_interrupted
 * @ref eos_p2p_add_notify_peer_connection_closed
 * @ref eos_p2p_remove_notify_peer_connection_closed
 * @ref eos_p2p_add_notify_incoming_packet_queue_full
 * @ref eos_p2p_remove_notify_incoming_packet_queue_full
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this API:
 *
 * @ref EpicP2PReceivedPacket
 * @ref EpicP2PQueryNATTypeCallbackInfo
 * @ref EpicP2PConnectionRequestCallbackInfo
 * @ref EpicP2PConnectionEstablishedCallbackInfo
 * @ref EpicP2PConnectionInterruptedCallbackInfo
 * @ref EpicP2PConnectionClosedCallbackInfo
 * @ref EpicP2PPacketQueueInfo
 * @ref EpicP2PPortRange
 * @ref EpicP2PIncomingPacketQueueFullCallbackInfo
 *
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this API:
 *
 * @ref EpicNATType
 * @ref EpicPacketReliability
 * @ref EpicConnectionEstablishedType
 * @ref EpicNetworkConnectionType
 * @ref EpicConnectionClosedReason
 * @ref EpicRelayControl
 *
 * @section_end
 *
 * @module_end
 */

// Constants

/**
 * @const EpicNATType
 * @desc **Epic Online Services Enum:** [EOS_ENATType](https://dev.epicgames.com/docs/api-ref/enums/eos-enat-type)
 *
 * The possible categories of NAT strictness, as reported by ${function.eos_p2p_get_nat_type}.
 *
 * @member Unknown The NAT type is either unknown (remote) or hasn't been determined yet (local).
 * @member Open All peers can directly connect to you.
 * @member Moderate You can directly connect to other Moderate and Open peers.
 * @member Strict You can only directly connect to Open peers.
 *
 * @const_end
 */

/**
 * @const EpicPacketReliability
 * @desc **Epic Online Services Enum:** [EOS_EPacketReliability](https://dev.epicgames.com/docs/api-ref/enums/eos-e-packet-reliability)
 *
 * Ordered packets are only ordered relative to other ordered packets. Reliable/unreliable and ordered/unordered traffic can share the same socket ID and channel.
 *
 * @member UnreliableUnordered Sent once; may arrive out of order or not at all.
 * @member ReliableUnordered May be resent; may arrive out of order.
 * @member ReliableOrdered May be resent; always arrives in order.
 *
 * @const_end
 */

/**
 * @const EpicConnectionEstablishedType
 * @desc **Epic Online Services Enum:** [EOS_EConnectionEstablishedType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-connection-established-type)
 *
 * @member NewConnection The connection is brand new.
 * @member Reconnection The connection was reestablished, or its network path changed.
 *
 * @const_end
 */

/**
 * @const EpicNetworkConnectionType
 * @desc **Epic Online Services Enum:** [EOS_ENetworkConnectionType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-network-connection-type)
 *
 * @member NoConnection There is no established connection.
 * @member DirectConnection A direct connection to the peer, over the internet or a local network.
 * @member RelayedConnection A connection relayed through Epic-provided servers.
 *
 * @const_end
 */

/**
 * @const EpicConnectionClosedReason
 * @desc **Epic Online Services Enum:** [EOS_EConnectionClosedReason](https://dev.epicgames.com/docs/api-ref/enums/eos-e-connection-closed-reason)
 *
 * @member Unknown The connection closed for unknown reasons - most notably during application shutdown.
 * @member ClosedByLocalUser The local user closed the connection via ${function.eos_p2p_close_connection}/${function.eos_p2p_close_connections}.
 * @member ClosedByPeer The remote user gracefully closed the connection.
 * @member TimedOut The connection was locally accepted but never remotely accepted in time.
 * @member TooManyConnections The connection was accepted, but couldn't be created due to too many other existing connections.
 * @member InvalidMessage The remote user sent an invalid message.
 * @member InvalidData The remote user sent invalid data.
 * @member ConnectionFailed A connection with the remote user could never be established, due to connectivity issues.
 * @member ConnectionClosed The connection was accepted and established, but the peer silently went away.
 * @member NegotiationFailed The connection was locally accepted but negotiation failed - most commonly because the local user went offline or logged out mid-negotiation.
 * @member UnexpectedError An internal error occurred and the connection couldn't be created or continued.
 *
 * @const_end
 */

/**
 * @const EpicRelayControl
 * @desc **Epic Online Services Enum:** [EOS_ERelayControl](https://dev.epicgames.com/docs/api-ref/enums/eos-e-relay-control)
 *
 * Connections between peers with incompatible relay-control settings may succeed in limited scenarios, but should be treated as unreliable.
 *
 * @member NoRelays Never use relay servers. Clients behind restrictive NATs may fail to connect to peers.
 * @member AllowRelays Try a direct connection first, fall back to a relay server. Default if not changed.
 * @member ForceRelays Always use relay servers. Adds latency to every connection, but hides IP addresses from peers.
 *
 * @const_end
 */
