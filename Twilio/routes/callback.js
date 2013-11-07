/*jslint node: true, plusplus: true, unparam:true*/
'use strict';

exports.get = function (req, res) {
    res.contentType('text/xml');

    res.render('callback-xml', {});
};
