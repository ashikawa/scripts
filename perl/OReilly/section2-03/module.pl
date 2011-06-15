use strict;
use File::Basename qw( basename );

my $some_path = "/Users/shigeru.ashikawa/workspace/yamaneko/etc/perl";

print basename($some_path) , "\n";
print File::Basename->dirname($some_path) , "\n";
