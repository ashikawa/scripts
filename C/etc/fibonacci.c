#include <stdio.h>

int o;

int main(int argc, char *argv[])
{
	int in = 10;
	
	o = 0;
	printf("%d\n", fibnacci(in));
	printf("%d\n", o);
	
	o = 0;
	printf("%d\n", fibnacci2( 1, 0, in));
	printf("%d\n", o);
	
	return 0;
}


/**
 * 計算回数が級数的に増えるがわかりやすい
 */
int fibnacci(int n)
{
	o++;
	
	if(n == 0){
		return 0;
	}else if(n == 1){
		return 1;
	}else{
		return fibnacci(n - 1) + fibnacci(n -2);
	}
}

/**
 * 計算回数が線形
 */
int fibnacci2(int a, int b, int n)
{
	o++;
	
	if( n == 0){
		return b;
	}else{
		return fibnacci2( a + b, a, --n );
	}
}


