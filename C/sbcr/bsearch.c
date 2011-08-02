/**
 *List 8-8
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILER 1

double call_func(double x)
{
	return pow(x, 5)
			- 10.0 * pow(x, 4)
			+ 25.0 * pow(x, 3)
			+ 40.0 * pow(x, 2)
			+ 200.0 * pow(x, 1)
			- 500.0;
}

double bin_search(void)
{
	double left = 1.0
		, mid
		, right = 3.0
		, epsilon = 0.00001;
	
	while( fabs(right - left) > epsilon
				&& fabs(call_func(left)) > epsilon ){
		
		/**
		 * debug section
		 */
		printf("%lf\t%lf\n",left, right);
		
		
		
		
		mid = (left + right) / 2.0;
		
		if( call_func(left) * call_func(mid) >= 0.0 ){
			left = mid;
		}else{
			right = mid;
		}
	}
	
	return left;
}

int main(int argc, char *argv[])
{
	double d = bin_search();
	
	printf("ans: %lf  func(x) = %lf\n",d ,call_func(d) );
	
	return EXIT_SUCCESS;
}
