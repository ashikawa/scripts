○ベンチマーク測定。
http://fine.ap.teacup.com/hepo/8.html

/usr/bin/ab -n 1000 -c 5 [request uri]

[request uri]に対して、同時リクエスト数５回を、合計1000リクエスト投げる（=同時５回を200回）


○アクセス解析
/usr/bin/apachetop -f [logfile]

アクセスログのリアルタイム解析。
[logfile]に対してアクセス権が必要。

