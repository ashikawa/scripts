#include <stdio.h>


/**
 * 1-1-2
 */
int main(int argc, char *argv[])
{

	printf("%d\n",fibonacci(10));
	return 0;
}

int fibonacci(int n)
{
	return (n > 2) ? fibonacci(n - 2) + fibonacci(n - 1) : 1;
}
