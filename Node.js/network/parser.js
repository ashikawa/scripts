/*global process, console*/
/**
 * harファイルのパースと tsv出力
 */
(function () {
    'use strict';

    process.stdin.resume();
    process.stdin.setEncoding('utf8');

    var stdIn = "";
    process.stdin.on('data', function (chunk) {
        stdIn += chunk;
    });

    process.stdin.on('end', function () {

        var data = JSON.parse(stdIn).log.entries;

        data.forEach(function (element, i) {

			var req	= element.request,
				res	= element.response;

			process.stdout.write([
				req.url,
				req.method,
				res.status,
				res.statusText,
				res.bodySize,
				res.content.mimeType
			].join('\t') + '\n');
        });
    });
}());