/*jslint node:true, nomen:true*/
(function () {
    'use strict';

    var sys       = require('sys'),
        fs        = require('fs'),
        scraper   = require('scraper'),
        inputText = "";

    process.stdin.resume();
    process.stdin.setEncoding('utf8');

    process.stdin.on('data', function (chunk) {
        inputText += chunk;
    });

    // EOF
    process.stdin.on('end', function () {
        var urls = inputText.trim().split('\n');

        scraper(urls, function (err, $) {
            if (err) { throw err; }

            var $img = $('.product-image img');

            if ($img.length === 0) {
                console.log("[not found]");
            }

            $img.each(function (i, element) {
                console.log($(element).attr('src').trim());
            });
        }, {
            'reqPerSec': 0.2 // 5 sec
        });
    });
}());
