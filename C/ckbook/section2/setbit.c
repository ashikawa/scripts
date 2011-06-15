#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, int y);
unsigned int getbits(unsigned int x, int p, int n);

#define MAX_LENGTH 100

/**
 * 2-6 setbits
 * example getbits
 */
int main(int argc, char *argv[])
{
	unsigned int x	= 0xFFFFFFFF;
	unsigned int y	= 0x00000000;
	
	int p	= 10;
	int n	= 4;
	
	printf( "%x\n", ~0 );				//処理系での unsigined int を調べる
	printf( "%d\n", sizeof(x) );		//処理系での unsigined int を調べる
	// 1 byte = 8 bit
	// sizeof(int x) = 4 ならば ~0 は 0xFFFFFFFF
	
	printf( "%x\n", getbits(x, p, n) );
	printf( "%x\n", setbits(x, p, n, y) );
	
	return 0;
}

unsigned int setbits(unsigned int x, int p, int n, int y)
{
	return ( y & ( ~0 << n ) ) | getbits(x, p, n );
}

unsigned int getbits( unsigned int x, int p, int n )
{
	return ( x >> ( p + 1 - n ) ) & ~( ~0 << n );
}
