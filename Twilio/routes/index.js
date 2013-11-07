/*jslint node: true, plusplus: true, unparam:true*/
'use strict';

exports.index = function (req, res) {

    var mysql  = require('mysql'),
        twilio = require('twilio'),
        connection,
        query,
        sid    = 'AC275bd94d32b09cb8f32f59ff786c3895',
        secret = '813bb27d75cd45f975a09fc331eb2d34',
        capability = new twilio.Capability(sid, secret);

    //Create a capability token for a client named "jenny"
    capability.allowClientOutgoing('APf60ebf7ff844c1d1608fbd007301c8ae');
    capability.allowClientIncoming('jenny');


    connection = mysql.createConnection({
        host: '54.238.158.4',
        database: 'twilio',
        user: 'twilio',
        password: '$EqKofAuz7A7J'
    });

    query = 'SELECT * FROM `records` ORDER BY id DESC;';

    connection.query(query, [], function (err, results) {

        if (err) {
            console.log(err);
            throw err;
        }

        res.render('index', {
            token: capability.generate(),
            results: results
        });
    });
};
