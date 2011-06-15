use strict;

my $text = "Fred dropped a 5 ton granite block on Mr, Slate";
my @words = ($text =~ m/([a-z]+)/ig);

print "Result: @words\n";
