use strict;

chdir "/etc" or die "cannot chdir to /etc $!";
my @all_files = glob "*";

print "@all_files\n";
