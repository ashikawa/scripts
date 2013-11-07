/**
 * DotInstall Canvas の基礎
 *   http://dotinstall.com/lessons/basic_canvas
 */
(function () {

	var canvas	= document.getElementById('mycanvas'),
		ctx		= canvas.getContext('2d');

	// 普通にエラーが出てくれた方がわかりやすいので
	// if (!canvas || !canvas.getContext) {
	//	return false;
	// }

	/**
	 * 基本図形
	 */
	function lesson5() {

		// left, top, width, height
		ctx.strokeStyle	= "#ff0000";
		ctx.fillStyle	= "#ff0000";
		ctx.lineWidth	= 5;
		ctx.lineJoin	= "round"; // "bevel" etc

		ctx.clearRect(15, 15, 40, 40);
		
		ctx.fillStyle	= "rgba(255,0,0,0.5)";
		ctx.strokeRect(10, 10, 50, 50);
		ctx.fillRect(100, 10, 50, 50);
	}

	/**
	 * グラデーション塗り
	 */
	function lesson6() {

		// var g = ctx.createRadialGradient(50,50,20,50,50,60);
		var g = ctx.createLinearGradient(0, 0, 100, 100);

		g.addColorStop(0.0, "red");
		g.addColorStop(0.5, "yellow");
		g.addColorStop(1.0, "blue");

		ctx.fillStyle = g;

		ctx.fillRect(0, 0, 100, 100);
	}

	/**
	 * ドロップシャドウ
	 */
	function lesson7() {

		ctx.shadowColor		= "#ccc";
		ctx.shadowOffsetX	= 5;
		ctx.shadowOffsetY	= 5;
		ctx.shadowBlur		= 5;

		ctx.globalAlpha		= 0.5;

		ctx.fillRect(0, 0, 100, 100);
	}

	/**
	 * 拡大縮小、回転
	 */
	function lesson8() {

		ctx.scale(0.8, 0.8);
		ctx.rotate(30 / 180 * Math.PI);	// radian
		ctx.translate(100, 10);	// move

		ctx.fillRect(0, 0, 100, 100);
	}

	/**
	 * 直線を描く
	 */
	function lesson9() {

		ctx.beginPath();
		ctx.moveTo(20, 20);
		ctx.lineTo(120, 120);
		ctx.lineTo(120, 50);
		ctx.lineTo(120, 220);
		ctx.closePath();

		ctx.fill();
		// ctx.stroke();
	}

	/**
	 * 曲線
	 */
	function lesson10() {

		ctx.beginPath();
		ctx.arc(100, 100, 50, 0, 270 / 180 * Math.PI);
		ctx.lineWidth	= 15;
		ctx.lineCap		= "round";	//"square" "butt"
		ctx.stroke();
	}

	/**
	 * 画像の読み込み、敷き詰め
	 */
	function lesson12() {

		var img = new Image();

		img.src = "./img/2.jpg";

		img.onload = function () {
	        var pattern = ctx.createPattern(img, 'repeat'); // no-repeat, repeat-x, repeat-y
	        ctx.fillStyle = pattern;
	        ctx.fillRect(0, 0, 500, 500);
		};
	}

	/**
	 * 設定の保存、レストア
	 */
	function lesson13() {

		ctx.fillStyle = "yellow";
		ctx.save();

		ctx.fillRect(0, 0, 50, 50);
		
		ctx.fillStyle = "blue";
		ctx.fillRect(100, 0, 50, 50);
		
		ctx.restore();
		ctx.fillRect(200, 0, 50, 50);
	}

	/**
	 * ランダムで水玉
	 */
	function lesson14() {

		var i,
			x,
			y,
			r;

		function getRandomColor() {
			return Math.floor(Math.random() * 255);
		}

		ctx.globalAlpha = 0.5;

		for (i = 0; i < 100; i++) {

			x = Math.floor(Math.random() * 500);
			y = Math.floor(Math.random() * 500);
			r = Math.floor(Math.random() * 100);

			ctx.fillStyle = "rgb("
				+	getRandomColor() + "," 
				+	getRandomColor() + "," 
				+	getRandomColor()
				+ ")";
		
			ctx.beginPath();

			ctx.arc(x, y, r, 0, 2 * Math.PI);

			ctx.stroke();
			ctx.fill();
		}


	}

	function lesson16() {

		var y		= 0;

		ctx.fillStyle = "red";

		(function loop() {
			ctx.clearRect(0, 0, canvas.width, canvas.height);

			if (y > canvas.height) {
				y = -50;
			}
			y++;
			
			ctx.fillRect(0, y, 50, 50);
			setTimeout(loop, 10);
		}());
	}


	window.onload = function () {
		lesson16();
	};

}());