use strict;
use File::Find;


sub createfind_callbacks_that_sum_the_size 
{
	my $total_size = 0;
	
	return(
		sub { $total_size += -s if -f },
		sub { return $total_size }
	);
}


my %subs;

foreach my $dir ( qw(bin lib man) ){
	my ($callback, $getter) = createfind_callbacks_that_sum_the_size( );
	
	$subs{$dir}{CALLBACK}	= $callback;
	$subs{$dir}{GETTER}		= $getter;
}

for (keys %subs) {
	find($subs{$_}{CALLBACK}, $_);
}

for (sort keys %subs) {
	
	my $sum = $subs{$_}{GETTER}->( );
	print "$_ has $sum bytes\n";
}


