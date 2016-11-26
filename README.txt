1. Set-up adhoc network on Raspberry Pi: http://wind.cs.purdue.edu/doc/adhoc.html
2. Install npm:
    sudo apt-get install npm
3. Install express & socket.io (https://hackintoshrao.com/2014/01/23/sending-data-to-the-node-js-server-using-websockets/)
    npm install express
    npm install socket.io
4. Download and configure Quick2Wire GPIO Admin:
    https://github.com/quick2wire/quick2wire-gpio-admin
    You'll need need N ports to control N-1 modes on the arduino.
        000 => Toggle (Set when switching modes to avoid transient-state errors)
        001 => Start Position (resets paddle to x=0) 
        010 => Single Wave Pulse
        011 => Steady Waveform
        100 => Some other mode you write
        ...
        111 => 7th mode you write
    You'll need one more port of you want to contorl more than 7 modes on the arduino 5. Install pi-gpio (https://github.com/rakeshpai/pi-gpio)
    npm install pi-gpio
