
chomp(@lines = <STDIN>);

print "-" x 10 , "\n";

foreach (sort @lines)
{
	print $_ , "\n";
}
