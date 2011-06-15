#include <stdio.h>

int a_x_b(int a, int b);

int main(int argc, char *argv[])
{
	printf("%d\n",a_x_b(5, 4));
	return 0;
}


int a_x_b(int a, int b)
{
	int r = 0;
	
	for (; b > 0; b >>= 1, a+=a )
		if ( b & 1) r += a;

	return r;
}

