#include <stdio.h>
#include <stdio.h>

#define EXIT_SUCCESS 0


/**
 *List 8-1, 8-2
 */
int main(int argc, char *argv[])
{
	float f1 = 0.1f
		, f2 = 0.100000001f;
	
	printf("%20.18f\n%20.18f\n", f1, f2);
	
	double d1 = 0.1
		,	d2 = 0.100000001;	
	
	printf("%20.18lf\n%20.18lf\n", d1, d2);
	
	return EXIT_SUCCESS;
}
