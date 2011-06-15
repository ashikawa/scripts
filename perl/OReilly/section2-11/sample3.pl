#use strict;

{package Animal;
	sub speak {
		my $class = shift;
		print "a $class goes ", $class->sound, "!\n";
	}
}

{package Cow;
	@ISA = qw(Animal);
	sub sound {"mooo"}
}

Cow->speak();
