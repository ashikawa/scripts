#include <stdio.h>
#include <math.h>

#define sigma(x) ((x)+1)*(x)/2

double fact(int n);

int main(int argc, char *argv[])
{
	printf("%d\n",sigma(10));
	
	printf("%f\n",fact(0));
	
	return 0;
}

double fact(int n)
{
    return (n>1) ? n*fact(n-1) : 1;
}

