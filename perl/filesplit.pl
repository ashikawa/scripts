#!/usr/bin/perl
#
# テキストファイル正規表現にマッチさせた内容で切り分ける
#
$fileName	= "";

while(<>){
	if( m/^(.*?):(.*?):(.*)$/)
	{
		$fileName	=  $1 . "-" . $2 . ".txt";
		
		open (OUT, ">> $fileName");
		
		print OUT $& . "\n";
		close(OUT);
	}
}

