use strict;

my @numerically =
	sort { $b <=> $a } 1, 2, 4, 8, 16, 32;
	
print "@numerically\n";



my @numerically2 =
	reverse sort 1, 2, 4, 8, 16, 32;
	
print "@numerically2\n";


my @numerically3 =
	sort {
		if ($a < $b) { -1 }
		elsif ($a > $b) { 1 }
		else { 0 };
	} 1, 2, 4, 8, 16, 32;
	
print "@numerically3\n";
