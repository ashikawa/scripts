/*jslint node: true, plusplus: true, unparam:true*/
'use strict';

exports.get = function (req, res) {
    res.contentType('text/xml');

    var mysql = require('mysql'),
        connection,
        query;

    connection = mysql.createConnection({
        host: '54.238.158.4',
        database: 'twilio',
        user: 'twilio',
        password: '$EqKofAuz7A7J'
    });

    query = 'INSERT INTO `records` (recording) VALUES (?);';

    connection.query(query, [req.query.RecordingUrl], function (err, results) {

        if (err) {
            console.log(err);
            throw err;
        }
        res.render('record-callback-xml', {});
    });
};
