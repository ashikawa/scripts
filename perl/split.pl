#!/usr/bin/perl

#
# テキストファイル(ログとか)を
# 指定したトークンで分割保存するスクリプト
#

$flag			= 0;
$fileName	= "";
$stack		= "";

while(<>){
	if( m/start token/)
	{
		$fileName	=  $& . ".txt";
		$fileName	=~ s/\///g;
		$fileName	=~ s/ /-/g;
		
		$stack		= "";
	}

	$stack	= $stack . $_;
	
	if( m/end token/)
	{
		open (OUT, "> $fileName");
		print OUT $stack;
		close(OUT);
	}
}

