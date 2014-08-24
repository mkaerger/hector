<?php

$socket = socket_create(AF_INET,SOCK_STREAM,0);

@socket_connect($socket,"127.0.0.1",30000) or die(json_encode('Service not running'));

$service = $_REQUEST['function'] . "|" . trim($_REQUEST['data']);

print json_encode(get_stuff($service, $socket));

socket_close($socket);

function get_stuff($in, $socket) {
    socket_write($socket,$in,strlen($in));
    return socket_read($socket, 1024);
}
