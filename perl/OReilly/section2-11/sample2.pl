use strict;

sub Cow::speak {
	print "a Cow goes mooo!\n";
}

sub Horse::speak {
	print "a Cow goes neigh!\n";	
}

sub Sheep::speak {
	print "a Cow goes baaah!\n";	
}

my @pasture = qw( Cow Cow Horse Sheep Sheep );

foreach my $beast (@pasture) {
	$beast->speak;
}
