print "input strings exit ctrl+D\n";

@lines = <STDIN>;

print "-" x 10, "\n";

print reverse @lines;

exit;

# 以下不正解
foreach (reverse @lines)
{
	print $_;
}
