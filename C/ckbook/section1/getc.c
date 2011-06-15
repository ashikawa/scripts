#include <stdio.h>

/**
 * 1.5.1 file print
 */
int main()
{
	int c;
	c = getchar();
	
	while(c != EOF){
		putchar(c);
		c = getchar();
	}
	
	return 0;
}
