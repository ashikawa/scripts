/*
 orient.js
 @copyright s.ashikawa
*/
$(function(){var c,d=$("#map_canvas");(function(){var a=d.get(0),b={zoom:17,center:new google.maps.LatLng(36,137),mapTypeId:google.maps.MapTypeId.ROADMAP};c=new google.maps.Map(a,b)})();(function(){navigator.geolocation.watchPosition(function(a){c.setCenter(new google.maps.LatLng(a.coords.latitude,a.coords.longitude))},function(a){console.log("error:",a)})})();(function(){var a=$("#logger");window.addEventListener("deviceorientation",function(b){var c=b.webkitCompassHeading,e=-c;a.html("head:"+c+
"<br />alpha: "+b.alpha+"<br />beta: "+b.beta+"<br />gamma: "+b.gamma);d.css({"-webkit-transform":"rotate("+e+"deg)"})},!0);window.triggerOrientation=function(a){viceOrientHandler({webkitCompassHeading:a})}})()});
