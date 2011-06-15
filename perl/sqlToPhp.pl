#!/usr/bin/perl

#
#	SQLをphp用に整形する
#

while(<>){
	
	s/^[\f\t ]*(.*)[\f\t ]*$/$1/g;
	
	unless( m/^$/ ){
		s/^(.*)$/\.\t"$1 "/g;
	}
	
	print;
}

