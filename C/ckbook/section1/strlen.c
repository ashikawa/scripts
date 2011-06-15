#include <stdio.h>

/**
 * 1.5.2 char count
 */
int main()
{
	double nc;
	
	for(nc = 0; getchar() != EOF; ++nc);
	
	printf("%.0f\n", nc);
	
	return 0;
}
