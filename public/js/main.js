$(document).ready(function() {

  var socket = io.connect();

  /* Socket Events */

  $('#bassHit').on('click touchstart', function() {
    socket.emit('show', { show: 'a' });
    return false;
  });

  $('#inverseBassHit').on('click touchstart', function() {
    socket.emit('show', { show: 'b' });
    return false;
  });

  $('#bassBuildUp').on('click touchstart', function() {
    socket.emit('show', { show: 'c' });
    return false;
  });

  $('#breather').on('click touchstart', function() {
    socket.emit('show', { show: 'd' });
    return false;
  });

  $('#candle').on('click touchstart', function() {
    socket.emit('show', { show: 'e' });
    return false;
  });

  $('#led1').on('click touchstart', function() {
    socket.emit('show', { show: '1' });
    return false;
  });

  $('#led2').on('click touchstart', function() {
    socket.emit('show', { show: '2' });
    return false;
  });

  $('#led3').on('click touchstart', function() {
    socket.emit('show', { show: '3' });
    return false;
  });

  $('#led4').on('click touchstart', function() {
    socket.emit('show', { show: '4' });
    return false;
  });

  $('#led5').on('click touchstart', function() {
    socket.emit('show', { show: '5' });
    return false;
  });

  $('#ledTop').on('click touchstart', function() {
    socket.emit('show', { show: '6' });
    return false;
  });

  $('#ledLeft').on('click touchstart', function() {
    socket.emit('show', { show: '7' });
    return false;
  });

  $('#ledRight').on('click touchstart', function() {
    socket.emit('show', { show: '8' });
    return false;
  });

  $('#ledAll').on('click touchstart', function() {
    socket.emit('show', { show: '9' });
    return false;
  });

  /* Toggle Button State */

  // Programs - Toggled
  $('.programs span').on('click touchstart', function() {
    $('.programs span').each(function() {
      $(this).removeClass('active');
    });

    $(this).addClass('active');
  });

  // Fade Out Light Hits
  $('.lights span').on('click touchstart', function() {
    $('.programs span').each(function() {
      $(this).removeClass('active');
    });

    $(this).css('background-color','#7ee95f').fadeTo(500, 0.5, function () {
      $(this).css("background-color", "#efefef");
      $(this).fadeTo(20, 1);
    });
  });

});