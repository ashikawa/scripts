/**
 *List 5-4
 */
#include <stdio.h>
#include <stdio.h>

#define EXIT_SUCCESS 0

int N[]	= {98, 140, 84, 28, 42, 126, 154};

int gcd(int a, int b)
{
	if( a == b ) return a;
	
	int i, m , n, t = 0;
	
	if( a > b ) { m = a; n = b; }else{ m = b; n = a; }
	
	while( n != 0 ){
		t = n;
		n = m % n;
		m = n;
	}
	
	return t;
}

int multi_gcd(int n)
{
	if(n == 1){
		return gcd(N[0], N[1]);
	}
	return gcd(N[n], multi_gcd( n  - 1 ));
}

int main(int argc, char *argv[])
{
	int run = sizeof(N) / sizeof(N[0]);
	printf("ans : %d\n", multi_gcd(run - 1));
	
	return EXIT_SUCCESS;
}
