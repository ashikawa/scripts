

if( "http://gogole.com" =~ m{http://([\w]+)} )
{
	print "match $1\n";
}else{
	print "un match\n";
}
