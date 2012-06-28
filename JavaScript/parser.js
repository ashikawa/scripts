/**
 * harファイルのパースと tsv出力
 */
var global = this,
	stdin;


// stdin
stdin = (function () {
	
	var line	= "",
		stdin	= "";
	
	while (line = global.readline()) {
		stdin += line;
	}
	
	return stdin;
}());


// main
(function (instr) {
	
	var	SEPARATOR	= "\t",
		entries		= JSON.parse(instr).log.entries,
		req,
		res,
		i;
	
	for (i = 0; i < entries.length; i++) {
		
		req	= entries[i].request;
		res	= entries[i].response;
		
		global.print([
			req.url,
			req.method,
			res.status,
			res.statusText,
			res.bodySize,
			res.content.mimeType
		].join(SEPARATOR));
	}	
}(stdin));
