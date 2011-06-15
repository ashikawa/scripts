
foreach $rock (qw/bedrock slate lava/)
{
	print "One rock is $rock.\n";
}

foreach (qw/bedrock slate lava/)
{
	print "One rock is $_.\n";
# print の引数を省略すると $_ が勝手に入る
#	print;
}


