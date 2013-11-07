( function(){

	var global = (function(){return this;})();
	
	// CanvasClass
	function CanvasFilter( canvas ){
		
		this.canvas		= document.getElementById(canvas);
		this.context	= this.canvas.getContext("2d");
		this.buffer		= null;
	}
	CanvasFilter.prototype.drawImage = function(image, x, y){
		this.context.drawImage(image, x, y);
	};
	CanvasFilter.prototype.getWidth = function(){
		
		return this.canvas.width;
	};
	CanvasFilter.prototype.getHeight = function(){
		
		return this.canvas.height;
	};
	CanvasFilter.prototype.getPixel = function(x, y){
		
		var imagePixelData	= this.context.getImageData(x, y, 1, 1).data,
			R = imagePixelData[0],
			G = imagePixelData[1],
			B = imagePixelData[2];
		
		return {R:R, G:G, B:B};
	};
	
	CanvasFilter.prototype.filter = function( filter ){
		
		var x = 0,
			y = 0,
			width	= this.getWidth(),
			height	= this.getHeight(),
			result	= [];

		for (y = 0; y < height; y++) {
			
			result[y] = [];
			
			for (x = 0; x < width; x++) {
				result[y][x] = filter.apply( this, [x,y] );
			}
		}
		this.buffer = result;
	};
	
	CanvasFilter.prototype.flash = function() {

		var x = 0,
			y = 0,
			width	= this.getWidth(),
			height	= this.getHeight(),
			context	= this.context,
			buffer	= this.buffer;
		
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				
				pixel			= context.createImageData(1, 1);
				_b				= buffer[y][x];
				pixel.data[0]	= _b.R;
				pixel.data[1]	= _b.G;
				pixel.data[2]	= _b.B;
				pixel.data[3]	= _b.A;
				
				context.putImageData(pixel, x, y);
			}
		}
	};
	
	window.CanvasFilter = CanvasFilter;
})();
