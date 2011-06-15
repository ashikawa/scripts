#include <stdio.h>
#define SIZE 255	

int getint(int *);

/**
 * 5.3 getint pointer
 */
int main(int argc, char *argv[])
{
	int n = 0;
	int in[SIZE];
	
	while( getint(&in[n]) != EOF ){
		printf("%d\t%d\n", n, in[n]);
		n++;
	}
	
	return 0;
}

