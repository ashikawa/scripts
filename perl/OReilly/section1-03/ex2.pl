
@students = qw{
	fred
	betty
	barney
	wilma
	pebbles
	bamm-bamm
};

chomp(@lines = <STDIN>);

foreach (@lines)
{
	print $students[$_] , "\n";
}
