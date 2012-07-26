var express = require("express"),
    io = require('socket.io'),
    SerialPort = require("serialport").SerialPort,
    sp = new SerialPort("/dev/tty.usbmodem621", {
      baudrate: 9600
    });

var app = express.createServer(),
    socket = io.listen(app);

socket.set('log level', 1);
socket.set('transports', [
  'websocket'
]);

app.configure(function() {
  app.use(express.errorHandler({ dumpExceptions: true, showStack: true }));
  app.set('views', __dirname + '/views');
  app.use(express.static(__dirname + '/public'));
  app.set('view options', { layout: false });
  app.set('view engine', 'jade');
  app.use(express.bodyParser());
  app.use(express.methodOverride());
});


app.get('/', function(req, res) {
  res.render('index');
});

// Socket Events
socket.sockets.on('connection', function (socket) {
  socket.on('show', function(data) {
    sp.write(data.show);
  });
});

app.listen(4000);