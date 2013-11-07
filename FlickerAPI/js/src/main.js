/*browser: true*/
/*global $, jQuery, console*/
$(function () {
    'use strict';

    $.ajax({
        url: 'http://www.flickr.com/services/rest/',
        type: 'GET',
        dataType: 'jsonp',
        jsonp : "jsoncallback",
        data: {
            api_key  : '61fb41162f78c6e63e29a74e3680f0b8',
            method   : 'flickr.photos.search',
            tags     : 'penguin',
            per_page : 20,
            sort     : 'date-posted-desc',
            format   : 'json'
        },
        complete: function (xhr, textStatus) {
            //called when complete
        },
        success: function (data, textStatus, xhr) {

            var photos  = {},
                $container = $('#image_list_container'),
                $listTmpl  = $('#image_list_tmpl');

            //called when successful
            console.log(data, textStatus, xhr);

            if (data.stat !== 'ok') {
                console.log(data);
                return;
            }

            photos = data.photos;
            $listTmpl.tmpl(photos.photo).appendTo($container);
        },
        error: function (xhr, textStatus, errorThrown) {
            //called when there is an error
        }
    });
});
