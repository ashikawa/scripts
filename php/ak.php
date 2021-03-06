<?php 
/**
 * ApacheKiller の対策がされているか確認するコード
 * アドバイザリが適応されているか確認する物であって、Apache本体のパッチを確認する物ではない。
 * 
 * @see http://mail-archives.apache.org/mod_mbox/httpd-announce/201108.mbox/%3C20110826103531.998348F82@minotaur.apache.org%3E
 */

define("REQUEST_URL", "http://budori.ashikawa.vm/js/jquery.js");

function test_apache( $host ){
	
	$bytes	= '0-10000,1-10001,2-10002,3-10003,4-10004,5-10005,6-10006';
	
	$def	= stream_context_get_default( 
		array(
			'http' => array(
				'method'	=> "HEAD",
				'protocol_version'	=> "1.1",
				'header'	=> "Range:bytes={$bytes}\r\n" .
					"Request-Range:bytes={$bytes}\r\n" .
					"Accept-Encoding: gzip\r\n" .
					"Connection: close\r\n" ,
			)
		)
	);
	$headers = implode( "\n", get_headers( $host ) );
	
	echo $headers, PHP_EOL;
	return preg_match('/Partial/', $headers) ? true : false;
} 

if ( test_apache( REQUEST_URL ) ) {
	echo '脆弱かも！';
} else {
	echo '大丈夫！';
}
echo PHP_EOL;