use strict;

sub total
{
	my $total = 0;
	
	foreach(@_){
		$total += $_;
	}
	
	$total;
}

# ext 4-1
#my@fred = qw{ 1 3 5 7 9 };
#my $fred_total = total(@fred);
#
#print "The total of \@fred is $fred_total\n";
#print "Enter some numbers on separate lines: ";
#
#my $user_total = total(<STDIN>);
#print "The total of those number is $user_total.\n";
#
# ext 4-2
#print total(1..1000) , "\n";


sub average
{
	total(@_) / @_;
}

my @fred = qw{ 1 2 3 5 };
print &average(@fred), "\n";

sub above_average
{
	my $avg = average @_;
	my @list;
	
	foreach (@_){
		if($_ > $avg){
			push @list, $_;
		}
	}
	@list;
}

print "@fred \n";
my @above = &above_average(@fred);
print "@above\n";

