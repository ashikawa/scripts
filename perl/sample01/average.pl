

open(GRADES,"grades.txt") or die "Can't open grades: $!\n";

while ($line = <GRADES>){
	($student,$grades) = split(" ", $line);
	$grades{$student} .= $grades . " ";
}

foreach $student (sort keys %grades){
	$scores	= 0;
	$total	= 0;
	@grades	= split(" ", $grades{$student});
	
	foreach $grades (@grades){
		$total += $grades;
		$scores++;
	}
	
	$average = $total / $scores;
	print "$student: $grades{$student}\tAverage: $average\n";
}


print 1 / 3 * 10, "\n";
print 10 / 3, "\n";

if ((1 / 3 * 10) == (10 / 3)){
	print "true";
}else{
	print "false";
}
