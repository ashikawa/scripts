#!/bin/sh

# GoogleCDN からファイルをダウンロード
# 先に root で /ajax ディレクトリを作っておく事
# @see https://developers.google.com/speed/libraries/devguide?hl=ja#jquery

VERSIONS=$@

for v in $VERSIONS
do
	URL="http://ajax.googleapis.com/ajax/libs/jquery/$v/jquery.min.js"
	DIR="/ajax/libs/jquery/$v/"
	mkdir -p $DIR
	curl -o $DIR/jquery.min.js $URL
done
