#include <stdio.h>

/**
 * 1.5.1 - 2
 */
int main()
{
	int c;
	
	while( (c = getchar()) != EOF ){
		 putchar(c);
	}
	
	printf("exit\n");
	return 0;
}
