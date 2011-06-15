use strict;

sub max{
	my($max) = shift @_;
	
	foreach (@_){
		$max = ($max > $_ ? $max : $_);
	}
	$max;
}

print &max(1, 200, 5, 30, 55), "\n";
