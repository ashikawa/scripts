/*jslint node:true, unparam:true*/
/*global phantom, before, after, describe, expect, it, document, $*/

(function () {
    'use strict';

    var page   = require('webpage').create(),
        system = require('system'),
        address;

    if (system.args.length !== 2) {
        console.log('Usage: assert.js <some URL>');
        phantom.exit();

        return;
    }

    address = system.args[1];

    page.open(address, function (status) {
        var title = page.evaluate(function () {
            return document.title;
        });

        console.log('Page title is : ' + title);

        phantom.exit();
    });
}());