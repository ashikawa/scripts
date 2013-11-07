/**
 * @preserve motion.js
 * @copyright s.ashikawa
 */
/*global $,jQuery*/
$(function () {

	var moments = (function () {

		var STACK_LENGTH = 500,
			stack	= new Array(STACK_LENGTH),
			canvas	= "plotcanvas",
			renderable	= true,
			i;


		// 配列初期化
		for (i = 0; i < STACK_LENGTH; i++) {
			stack[i] = 0;
		}

		return {
			push: function (value) {

				var SAMPLING	= Math.floor(STACK_LENGTH / 2),
					INTERVAL_MS	= 5000,
					BOUNDARY	= 30,
					timerid,
					tmp			= stack[SAMPLING],
					vector		= Math.abs(tmp.x) + Math.abs(tmp.y) + Math.abs(tmp.z);

				stack.shift();
				stack.push(value);				

				if (vector > BOUNDARY && renderable) {

					renderable = false;

					// 5秒間は再描画しない
					timerid = window.setTimeout(function () {
						renderable = true;
					}, INTERVAL_MS);

					this.render();
				}
			},
			render: function () {

				var data = stack.concat(),
					x = [],
					y = [],
					z = [],
					i,
					options,
					tmpx = 0,
					tmpy = 0,
					tmpz = 0,
					DATA_INTERVAL = 50;

				options = {
				   // axes:{xaxis:{renderer:$.jqplot.CategoryAxisRenderer}}
				};

				for (i = 0; i < STACK_LENGTH; i++) {

					tmpx += data[i].x;
					tmpy += data[i].y;
					tmpz += data[i].z;

					if ((i + 1) % DATA_INTERVAL === 0) {
						x.push(tmpx / DATA_INTERVAL);
						y.push(tmpy / DATA_INTERVAL);
						z.push(tmpz / DATA_INTERVAL);

						tmpx = 0;
						tmpy = 0;
						tmpz = 0;
					}
				}

				$.jqplot(canvas, [x, y, z], options).replot();
			}
		};
	}());


	window.moments = moments;

	/**
	 * 加速度センサー
	 * @see http://developer.apple.com/library/safari/#documentation/SafariDOMAdditions/Reference/DeviceMotionEventClassRef/DeviceMotionEvent/DeviceMotionEvent.html
	 * @see http://dev.w3.org/geo/api/spec-source-orientation.html
	 */
	(function () {

		// iPhone/iPad用のハンドリング関数
		// interval ミリ秒
		function handleMotion(event) {

			var orientData	= event.accelerationIncludingGravity,
				x	= orientData.x,
				y	= orientData.y,
				z	= orientData.z;

			// @todo マイナスの値とか、いろいろ
			moments.push({x: x, y: y, z: z});
		}

		window.addEventListener("devicemotion", handleMotion, true);
		
		// 動作確認用、ダミーデータ入力処理
		window.triggerMotion = function () {

			var dummy = {},
				i;

			for (i = 0; i < 1000; i++) {

				dummy.accelerationIncludingGravity = {
					x: Math.random() * 10,
					y: Math.random() * 10,
					z: Math.random() * 10
				};

				handleMotion(dummy);
			}
		};
	}());

});
