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
        console.log(data.mode)
        /* Leave these if's commented until you are running
         * this file on a board with gpio pins
         *

        if (data.mode == 'reset') {
            // 000 => do nothing for a bit
            gpio.open(11, "output", function(err) {     // Open pin 16 for output
                gpio.write(11, 0, function() {          // Set pin 16 high (1)
                    gpio.close(11);                     // Close pin 16
                });
            });
            gpio.open(12, "output", function(err) {
                gpio.write(12, 0, function() {
                    gpio.close(12);
                });
            });
            gpio.open(13, "output", function(err) {
                gpio.write(13, 0, function() {
                    gpio.close(13);
                });
            });

            // 001 => Start Position Mode, aka reset paddle
            gpio.open(11, "output", function(err) {
                gpio.write(11, 0, function() {
                    gpio.close(11);
                });
            });
            gpio.open(12, "output", function(err) {
                gpio.write(12, 0, function() {
                    gpio.close(12);
                });
            });
            gpio.open(13, "output", function(err) {
                gpio.write(13, 1, function() {
                    gpio.close(13);
                });
            });
        }
        else if (data.mode == 'single') {
            // 000 => do nothing for a bit
            gpio.open(11, "output", function(err) {     // Open pin 16 for output
                gpio.write(11, 0, function() {          // Set pin 16 high (1)
                    gpio.close(11);                     // Close pin 16
                });
            });
            gpio.open(12, "output", function(err) {
                gpio.write(12, 0, function() {
                    gpio.close(12);
                });
            });
            gpio.open(13, "output", function(err) {
                gpio.write(13, 0, function() {
                    gpio.close(13);
                });
            });

            // 010 => Start Single Wave Pulse mode 
            gpio.open(11, "output", function(err) {
                gpio.write(11, 0, function() {
                    gpio.close(11);
                });
            });
            gpio.open(12, "output", function(err) {
                gpio.write(12, 1, function() {
                    gpio.close(12);
                });
            });
            gpio.open(13, "output", function(err) {
                gpio.write(13, 0, function() {
                    gpio.close(13);
                });
            });
        }  
        // else if(data.mode == 'somethingelse') {
        // }
        */

        var ack_to_client = {
            data:"Server Received the message"
        }

        /*Sending the Acknowledgement back to the client , this will trigger "message" event on the clients side*/
        socket.send(JSON.stringify(ack_to_client));
    });
});
