#include <stdio.h>


/**
 * 1-1-1
 */
int main(int argc, char *argv[])
{

	printf("%d\n",factorial(5));
	return 0;
}

int factorial(int n)
{
	return (n > 0) ? n * factorial(n - 1) : 1;
}
