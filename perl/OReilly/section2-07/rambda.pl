use strict;

my $ginger = sub {
	my $person = shift;
	print "Ginger:(in a sultry woice) Well hello, $person!\n";
};

$ginger->('Skipper');
