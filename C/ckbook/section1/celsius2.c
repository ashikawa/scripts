#include <stdio.h>


#define	LOWER	0
#define	UPPER	300
#define	STEP	20

/**
 * 1.4 celsius
 * define sample
 */
int main()
{
	float fahr, celsius;
	
	for(fahr = LOWER; fahr <= UPPER; fahr += STEP){
		
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f\t%6.1f\n", fahr, celsius);
	}
	
	return 0;
}
