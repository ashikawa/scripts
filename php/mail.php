#! /usr/bin/php
<?php
	/**
	 * php mail and mb_send_mail sample for Mac
	 * 2010/12/28 ashikawa
	 */

	//echo "hoge!!" . PHP_EOL;
	
	$to			= "a.shigeru@gmail.com";
	$subject	= "test subject";
	$message	= "sample string";

	$ret = mail ( $to , $subject , $message );
	var_export($ret);
	echo PHP_EOL;

	$ret = mb_send_mail ( $to , $subject , $message );
	var_export($ret);
	echo PHP_EOL;
?>
