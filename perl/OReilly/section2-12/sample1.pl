#use strict;

{package Animal;
	sub new {
		my $class	= shift;
		my $name	= shift;
		bless \$name, $class;
	}
	sub name {
		my $either = shift;
		ref $either
			? $either
			: "an unnamed $either";
	}
	sub speak {
		my $either = shift;
		print $either->name,  " goes ", $either->sound, "\n";
	}
	sub eat {
		my $either	= shift;
		my $food	= shift;
		print $either->name, " eats $food.\n";
	}
}

{package Horse;
	@ISA = qw( Animal );
	sub sound { 'neigh' };
}
{package Sheep;
	@ISA = qw( Animal );
	sub sound { 'blassh' };
}

my $tv_horse = Horse->new('Mr. Ed');
$tv_horse->eat('hay');

Sheep->eat('grass');

