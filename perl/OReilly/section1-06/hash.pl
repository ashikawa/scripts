use strict;

my %myhash = (
	'foo'	=> 10,
	'bar'	=> 30,
	'hoge'	=> 50,
);

while( my($key, $value) = each %myhash )
{
	print "$key\t=> $value\n";
}
