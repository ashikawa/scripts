/**
 * エッジ検出
 * http://d.hatena.ne.jp/Kojo_Sugita/20100504/1272986989
 */
function edgeDetector( canvasTag ) {
	
	var canvas		= document.getElementById( canvasTag )
		, _canvasW	= canvas.width
		, _canvasH	= canvas.height
		, grayImage	= []
        , x, y, pixelData;
	
	for( y = 0; y < _canvasH; y++){
		
		grayImage[y] = [];
		
		for( x = 0; x < _canvasW; x++){
			
			var pixelData = getPixel(canvas, x, y) // ピクセル値を取得する
				, R = pixelData.R
				, G = pixelData.G
				, B = pixelData.B;
			
			// グレースケール化
			grayImage[y][x] = toGrayscale(R, G, B);
		}
	}

	/* Sobelフィルタ */
	var filter = [
			[1, 0, -1],
			[1, 0, -1],
			[1, 0, -1]
		];
	
	/* 空間フィルタリング */
	var resultImage = spatialFiltering(grayImage, _canvasH, _canvasW, filter, 3)
		, I;
	
	/* セット */
	for (y = 0; y < _canvasH; y++) {
		for (x = 0; x < _canvasW; x++) {
			I = resultImage[y][x];
			setPixel(canvas, x, y, I, I, I, 255);
		}
	}
}

/**
 * 空間フィルタリング
 */
function spatialFiltering(grayImage, height, width, filter, size_f) {

	var init	= Math.floor(size_f / 2)
		, from	= - init
		, to	= init
		, i, j, k, n, m
		, sum;
		
	var resultImage = [];
	
	for (k = 0; k < height; k++) {
		resultImage[k] = [];
		for (l = 0; l < width; l++) {
			resultImage[k][l] = 0;
		}
	}
	
	for ( i = init; i < height - init; i++ ) {
		for ( j = init; j < width - init; j++ ) {
			
			sum = 0.0;
			/* フィルタリング */
			for ( n = from; n <= to; n++) {
				for ( m = from; m <= to; m++) {
					sum += grayImage[i + n][j + m] * 
						filter[n + init][m + init];
				}
			}	
			resultImage[i][j] = Math.floor(Math.abs(sum));
		}
	}
	return resultImage;
}

/**
 * RBGをグレースケールにして返する
 */
function toGrayscale(R, G, B) {
	
	R = Math.floor(R * 0.299);
	G = Math.floor(G * 0.587);
	B = Math.floor(B * 0.114);
	
	return R + G + B;
}



// SetPixel
function setPixel(canvas, x, y, R, G, B, A){
	
	var context = canvas.getContext("2d")
		, pixelImage = context.createImageData(1, 1);
	
	pixelImage.data[0] = R;
	pixelImage.data[1] = G;
	pixelImage.data[2] = B;
	pixelImage.data[3] = A;
	
	context.putImageData(pixelImage, x, y);
}
