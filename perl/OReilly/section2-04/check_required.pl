use strict;


sub check_required_items
{
	my $who		= shift;
	my $items	= shift;
	
	my @required = qw( preserver sunscreen water_bottle jacket);
	
	for my $item (@required){
		unless ( grep $item eq $_, @{$items} ){
			print "$who is missing $item. \n";
		}
	}
}


my @skipper		= qw( blue_shirt hat jacket preserver sunscreen );
my @professor	= qw( sunsreen water_bottle slide_rule batteries radio );

check_required_items('skipper', \@skipper);
check_required_items('professor', \@professor);


