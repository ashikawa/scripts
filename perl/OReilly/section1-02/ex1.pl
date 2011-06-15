
use Math::Trig;
use Scalar::Util;

my $r = <STDIN> or 12.5;
Scalar::Util::looks_like_number($r) or die "please input number";

my $ans = $r * 2 * pi;

print $ans, "\n";