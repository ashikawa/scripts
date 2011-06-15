use strict;

my $date = localtime;
$^I = ".bak";

while(<>){
	s/^Author:.*/Author: Randal L. Schwartz/;
	s/^Phone:.*\n//;
	s/^Date:.*/Date: $date/;
	print;
}
