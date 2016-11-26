var express = require('express');
var http = require('http');
var io = require('socket.io');
// var gpio = require("pi-gpio");

// Specifying the public folder of the server to make the html accesible using the static middleware
var app = express();
app.use(express.static ('./public'));

// Server listens on the port 8124
var server = http.createServer(app).listen(8124);
io = io.listen(server);

/*initializing the websockets communication , server instance has to be sent as the argument */
io.sockets.on("connection", function(socket) {
    /*Associating the callback function to be executed when client visits the page and
     *  websocket connection is made */

    var message_to_client = {
        data: "Connection with the server established."
    }

    /*sending data to the client , this triggers a message event at the client side */
    socket.send(JSON.stringify(message_to_client));
        console.log('Socket.io Connection with the client established');
    socket.on("message", function(data) {
        /*This event is triggered at the server side when client sends the data using socket.send() method */
        data = JSON.parse(data);

        /*Print the data */
        console.log(data);

        var ack_to_client = {
            data:"Server Received the message"
        }

        /*Sending the Acknowledgement back to the client , this will trigger "message" event on the clients side*/
        socket.send(JSON.stringify(ack_to_client));
    });
});
