/*jslint node:true*/
/*global phantom, before, after, describe, expect, it, document, $*/

(function () {
    'use strict';

    var page   = require('webpage').create(),
        system = require('system'),
        address,
        out;

    if (system.args.length !== 3) {
        console.log('Usage: phantomjs capture.js <some URL> <FILE>');
        phantom.exit();

        return;
    }

    address = system.args[1];
    out     = system.args[2];

    // iPhone Setting
    // page.settings.userAgent = 'Mozilla/5.0 (iPhone; CPU iPhone OS 6_0 like Mac OS X) AppleWebKit/536.26 (KHTML, like Gecko) Version/6.0 Mobile/10A5376e Safari/8536.25';

    page.open(address, function (status) {
        if (status !== 'success') {
            console.log('FAIL to load the address');
        }

        page.render(out);

        phantom.exit();
    });
}());