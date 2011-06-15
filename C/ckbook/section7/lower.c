#include <stdio.h>
#include <ctype.h>

/**
 * 7.2 lower
 */
int main(int argc, char *argv[])
{
	int c;
	while ( (c = getchar()) !=EOF )
		putchar(tolower(c));
	
	return 0;
}

