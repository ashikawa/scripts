<?php
/**
 * FourSquare 検索APIのサンプル
 * Userless Access : ユーザー認証不要の物
 * 
 * @see https://developer.foursquare.com/overview/auth
 * 	=> Userless access
 * @see https://developer.foursquare.com/docs/venues/search
 */

$client_id		= "SHJXHH0V41KIZL0WDAK4PESCEE05QXXSTYGOCVLEMIO1GIA0";
$client_secret	= "LZJBR3GMFOHVPLZ2YBMINZROJCVDR0XRFQ0UQAZFXVPAWN3Z";

// https://api.foursquare.com/v2/venues/categories

$domain	= "https://api.foursquare.com";


$api	= "/v2/venues/categories";

// ll か near のどちらかが必須
$params	= array(
	// "ll"			=> "35.658517,139.701334",	// GPS座標 これは渋谷駅
	// // "near"			=> "Shibuya",	// 日本語を使うとエラーになる、精度がいまいち
	// "query"			=> "激辛 ラーメン",
	// // "limit"			=> 5,	// default 30(?)
	"client_id"		=> $client_id,
	"client_secret"	=> $client_secret,
);


$url  = $domain . $api . "?" . http_build_query($params);

$opt = array(
	'http'=>array(
		'method'=>"GET",
		'header'=>"Accept-language: ja"
	)
);

$context = stream_context_create($opt);

var_dump(json_decode(file_get_contents($url/*, false, $context*/)));
