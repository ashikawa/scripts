/**
 * @preserve orient.js
 * @copyright s.ashikawa
 */
/*global $,jQuery,google*/
$(function () {
	// global vars 
	var googleMap,
		$mapCanvas = $("#map_canvas");

	/**
	 * @see https://developers.google.com/maps/documentation/javascript/reference?hl=ja
	 */
	(function () {

		var dom		= $mapCanvas.get(0),
			defPos	= new google.maps.LatLng(36, 137),
			options = {
				zoom : 17,
				center : defPos,
				mapTypeId : google.maps.MapTypeId.ROADMAP
			};

		googleMap = new google.maps.Map(dom, options);
	}());

	(function () {

		function updateHandler(position) {

			var acc = position.coords.accuracy,
				lat = position.coords.latitude,
				lng = position.coords.longitude;
				
			googleMap.setCenter(new google.maps.LatLng(lat, lng));
		}

		function handleError(error) {

			console.log("error:", error);

			// error.code
			//1＝Geolocation APIの利用が許可されない, 2＝デバイスの位置が判定できない, 3＝タイムアウト
		}

		var wid = navigator.geolocation.watchPosition(updateHandler, handleError);

	}());



	(function () {

		var $logger		= $("#logger");

		function deviceOrientHandler(event) {

		    var w = event.webkitCompassHeading,
		    	r = -w;

			$logger.html("head:" + w + "<br />"
						+ "alpha: " + event.alpha + "<br />"
						+ "beta: " + event.beta + "<br />"
						+ "gamma: " + event.gamma) ;
			
			$mapCanvas.css({"-webkit-transform" : "rotate(" + r + "deg)"});
		}

		window.addEventListener('deviceorientation', deviceOrientHandler, true);
		
		// for debug
		window.triggerOrientation = function(webkitCompassHeading){
			var dummy = {
				webkitCompassHeading: webkitCompassHeading
			};

			viceOrientHandler(dummy);
		}
	}());

});
