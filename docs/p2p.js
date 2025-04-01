

P2P REFERENCE PAGE: https://dev.epicgames.com/docs/en-US/api-ref/interfaces/p-2-p

------------------------------------------------------------------------------------

double eos_p2p_accept_connection(String local_user_id,String remote_user_id,String socket_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-accept-connection

------------------------------------------------------------------------------------

Struct {incoming_packet_queue_current_packet_count: double,incoming_packet_queue_current_size_bytes: double,incoming_packet_queue_max_size_bytes: double,outgoing_packet_queue_current_packet_count: double,outgoing_packet_queue_current_size_bytes: double, outgoing_packet_queue_max_size_bytes": double} eos_p2p_add_notify_incoming_packet_queue_full()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-add-notify-incoming-packet-queue-full

	String -> type eos_p2p_add_notify_incoming_packet_queue_full
	double -> overflow_packet_channel
	String -> overflow_packet_local_user_id
	double -> overflow_packet_size_bytes
	double -> packet_queue_current_size_bytes
	double -> packet_queue_max_size_bytes

------------------------------------------------------------------------------------

double eos_p2p_add_notify_peer_connection_closed(String local_user_id,String socket_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-add-notify-peer-connection-closed

	String -> type eos_p2p_add_notify_peer_connection_closed
	String -> local_user_id
	double -> reason
	String -> remote_user_id
	String -> socket_name

------------------------------------------------------------------------------------

double eos_p2p_add_notify_peer_connection_established(String local_user_id,String socket_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-add-notify-peer-connection-established

	String -> type eos_p2p_add_notify_peer_connection_established
	String -> local_user_id 
	double -> status
	double -> connection_type
	double -> network_type
	String -> socket_id
	String -> remote_user_id
	
------------------------------------------------------------------------------------

double eos_p2p_add_notify_peer_connection_interrupted(String local_user_id,String socket_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-add-notify-peer-connection-interrupted

	String -> type eos_p2p_add_notify_peer_connection_interrupted
	String -> local_user_id
	String -> remote_user_id
	String -> socket_name
	
------------------------------------------------------------------------------------

double eos_p2p_add_notify_peer_connection_request(String local_user_id,String socket_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-add-notify-peer-connection-request

	String -> type eos_p2p_add_notify_peer_connection_request
	String -> local_user_id
	String -> remote_user_id
	String -> socket_name
	
------------------------------------------------------------------------------------

double eos_p2p_clear_packet_queue(String local_user_id,String remote_user_id,String socket_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-clear-packet-queue

------------------------------------------------------------------------------------

double eos_p2p_close_connection(String local_user_id,String remote_user_id,String socket_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-close-connections

------------------------------------------------------------------------------------

double eos_p2p_close_connections(String local_user_id,String socket_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-close-connections

------------------------------------------------------------------------------------

double eos_p2p_get_nat_type()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-get-nat-type

------------------------------------------------------------------------------------

double eos_p2p_get_next_received_packet_size(String local_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-get-next-received-packet-size

------------------------------------------------------------------------------------

Struct {incoming_packet_queue_current_packet_count: double,incoming_packet_queue_current_size_bytes: double,incoming_packet_queue_max_size_bytes: double,outgoing_packet_queue_current_packet_count: double,outgoing_packet_queue_current_size_bytes: double ,outgoing_packet_queue_max_size_bytes: double} eos_p2p_get_packet_queue_info()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-get-packet-queue-info

------------------------------------------------------------------------------------

Struct {out_port:int, out_num_additional_ports_to_try:int} eos_p2p_get_port_range()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-get-port-range

------------------------------------------------------------------------------------

double eos_p2p_get_relay_control()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-get-relay-control

------------------------------------------------------------------------------------

double eos_p2p_query_nat_type()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-query-nat-type

	String -> type "eos_p2p_query_nat_type"
	double -> status
	String -> status_message
	double -> identifier
	double -> nat_type
	
------------------------------------------------------------------------------------

double eos_p2p_receive_packet(buff_adress,local_user_id,max_data_size_bytes,requested_channel)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-receive-packet

------------------------------------------------------------------------------------

double eos_p2p_remove_notify_incoming_packet_queue_full(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-remove-notify-incoming-packet-queue-full

------------------------------------------------------------------------------------

double eos_p2p_remove_notify_peer_connection_closed(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-closed

------------------------------------------------------------------------------------

double eos_p2p_remove_notify_peer_connection_established(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-established

------------------------------------------------------------------------------------

double eos_p2p_remove_notify_peer_connection_interrupted(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-interrupted

------------------------------------------------------------------------------------

double eos_p2p_remove_notify_peer_connection_request(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-remove-notify-peer-connection-request

------------------------------------------------------------------------------------

double eos_p2p_send_packet		[allow_delayed_delivery,buffer_bool],
		[disable_auto_accept_connection,buffer_bool],
		[channel,buffer_f32],
		[local_user_id,buffer_string],
		[reliability,buffer_u8],
		[remote_user_id,buffer_string],
		[socket_name,buffer_string],
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-send-packet

------------------------------------------------------------------------------------

double eos_p2p_set_packet_queue_size(double incoming_packet_queue_max_size_bytes, double outgoing_packet_queue_max_size_bytes)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-set-packet-queue-size

------------------------------------------------------------------------------------

double eos_p2p_set_port_range(double port, double max_additional_ports_to_try)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-set-port-range

------------------------------------------------------------------------------------

double eos_p2p_set_relay_control(double relay_control)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-p-2-p-set-relay-control

------------------------------------------------------------------------------------
