use strict;
use 5.010;

my $name = "Freder";
print "I found Fred in the name!\n" if $name =~ /Fred/;


say "I found Fred in the name!" if $name ~~ /Fred/;



my $flag = 0;

my %names = (
	"barney"	=> 195,
	"fred"		=> 205,
	"dino"		=> 30,
	"fredder"	=> 0,
);

foreach my $key (keys %names)
{
	next unless $key =~ /fred/;
	$flag = $key;
	last;
}
print "I found a key matching 'fred'. It was $flag\n" if $flag;



say "I found a key matching 'fred'" if %names ~~ /fred/;
