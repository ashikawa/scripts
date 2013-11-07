$(function(){
	
	if (window.File){
		console.log("File Support");
	}else{
		console.log("File Error");
	}
	if(window.FileReader) {
		console.log("FileReader Support");
	}else{
		console.log("FileReader Error");
	}
	if(document.createElement('canvas').getContext) {
		console.log("Canvas Support");
	}else{
		console.log("Canvas Error");
	}
});

$(function(){
	
	var canvas	= document.getElementById("myCanvas"),
		context	= canvas.getContext("2d"),
		CF		= new CanvasFilter("myCanvas");
	
	$("#uploadFile").change( function(e) {
		
		if( window.FileReader ){
			alert("このブラウザは FileReader に対応していません");
			return ;
		}
		
		// 各オブジェクトの初期化
		var file	= this.files[0],
			image	= new Image(),
			reader	= new FileReader();
		
		// 画像以外は許可しない
		if (!file.type.match(/^image\/(png|jpeg|gif)$/)) return;
		
		reader.onload = function(e) {
			image.onload = function(e) {
				CF.drawImage(this, 0, 0);
			};
			
			image.src = e.target.result;
		};
		
		reader.readAsDataURL( file );
	});
	
	$("#loadImage").click(function(e){
		
		var url		= $("#imageUrl").val(),
			image	= new Image();
		
		image.onload = function(e){
			// load end event
			CF.drawImage(this, 0, 0);
		};
		
		// loading event
		image.src	= url;
	});
	
	
	function toGrayscale(R, G, B) {
		
		var gray = Math.floor( (R + G + B) / 3 );
		
		return {R:gray, G:gray, B:gray, A:255};
	}
	
	$("#filterImage").click( function(e){
		
		// // グレースケール
		// function grayScale(x, y){
		// 	var pixel = this.getPixel(x, y), // ピクセル値を取得する
		// 		R = pixel.R,
		// 		G = pixel.G,
		// 		B = pixel.B;
			
		// 	return toGrayscale(R, G, B);
		// }
		
		// // カラー反転
		// function reverse(x, y){
		// 	var pixel = this.getPixel(x, y), // ピクセル値を取得する
		// 		R = Math.abs(255 - pixel.R),
		// 		G = Math.abs(255 - pixel.G),
		// 		B = Math.abs(255 - pixel.B);
			
		// 	return {R:R, B:B, G:G, A:255};
		// }

		// CF.filter( grayScale );
		
		// CF.flash();
		$("#myCanvas").css({
			"-webkit-filter": "grayscale()"
		});
	});
	
	$("#saveFile").bind("click", function(e){
		
		var img = new Image(),
			type = 'image/png'; //保存できるタイプは、'image/png'と'image/jpeg'の2種類
		
		//imgオブジェクトのsrcに格納。
		img.src = canvas.toDataURL(type);
		
		//念のため、onloadで読み込み完了を待つ。
		img.onload = function(){
			//例：現在のウィンドウに出力。
			location.href = img.src;
		};
	});
	
	$("#saveServer").bind("click", function(e){
		
		var type	= 'image/png', //保存できるタイプは、'image/png'と'image/jpeg'の2種類
			base64	= canvas.toDataURL(type);
		
		$.ajax({
			type: "POST",
			url: "./canvas/save.php",
			data: {
				data : base64
			},
			success: function(msg, status, xhr){
				console.log("success");
			}
   });
	});
});