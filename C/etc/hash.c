#include <stdio.h>
#include <math.h>

double fact(double);
double fact2(double,double);

/**
 * must compile optioin '-lm' 
 */
int main(int argc, char *argv[])
{
	double	num,per;
	int		n = 23;
	
//	num = pow(2,128);
	
//	per = 1 - (fact(365) / ( pow(365,n)*fact(365-n) ));
	
	per = 1 - ( fact2(365, n) / pow(365, n) ) ;
	
	printf("%lf\n",per);
	
	return 0;
}

double fact(double n)
{
    return (n>1) ? n*fact(n-1) : 1;
}

double fact2(double n, double to)
{
	return (n>to+1) ? n*fact2(n-1,to) : 1;
}

