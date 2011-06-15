use strict;


my %score = (
	"barney"	=> 195,
	"fred"		=> 205,
	"dino"		=> 30,
);

my @winners = sort by_score keys %score;


sub by_score
{
	$score{$b} <=> $score{$a};
}

$" = "\n";
print "@winners";

