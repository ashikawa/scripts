use strict;

use Data::Dumper;

$Data::Dumper::Purity = 1;
my @data1 = qw(one won);
my @data2 = qw(two too to);


push @data2, \@data1;
push @data1, \@data2;

print Dumper(\@data1, \@data2);
