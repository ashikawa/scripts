use strict;

my @odd_numbers = grep { $_ % 2 } 1.. 1000;

$" = "\n";
print "@odd_numbers";

