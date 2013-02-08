/*global process, console*/
(function () {
    'use strict';

    process.stdin.resume();
    process.stdin.setEncoding('utf8');
    // 標準入力がくると発生するイベント
    var stdIn = "";
    process.stdin.on('data', function (chunk) {
        stdIn += chunk;
    });

    function output(data) {
        data.forEach(function (e, i) {
            var line = "";

            if (e.startTime && e.usedHeapSize) {
                line = [e.startTime, e.usedHeapSize].join('\t') + '\n';
                process.stdout.write(line);
            }

            if (e.children) {
                output(e.children);
            }
        });

    }

    process.stdin.on('end', function () {

        var data = JSON.parse(stdIn);

        process.stdout.write('time, Heap\n');
        output(data);
    });

}());