#include <stdio.h>

unsigned int f(unsigned int x);

int main()
{
	int x;
	
	for(x=0;x<256;x++){
		printf("%x\t%x\n", x,f(x));
		//printf("%d\t%d\n", x,f(x));
	}
	
	return 0;
}

unsigned int f(unsigned int x) {
    x = x - 1;
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >>16);
    return x + 1;
}
