/*jslint node:true*/
/*global phantom, assert, document, $*/

(function () {
    'use strict';

    var page   = require('webpage').create(),
        assert = require('assert'),
        system = require('system'),
        address;

    if (system.args.length !== 2) {
        console.log('Usage: phantomjs assert.js <some URL>');
        phantom.exit();

        return;
    }

    address = system.args[1];

    // iPhone Setting
    // page.settings.userAgent = 'Mozilla/5.0 (iPhone; CPU iPhone OS 6_0 like Mac OS X) AppleWebKit/536.26 (KHTML, like Gecko) Version/6.0 Mobile/10A5376e Safari/8536.25';

    page.open(address, function (status) {

        if (status !== 'success') {
            console.log('FAIL to load the address');
        }

        // page.render(out);
        var title = page.evaluate(function () {
            return document.title;
        });

        // @see http://nodejs.org/api/assert.html
        assert.equal('hoge', title, 'hogehoge');

        phantom.exit();
    });
}());