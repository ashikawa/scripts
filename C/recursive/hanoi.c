#include <stdio.h>

void hanoi(int n, int a, int b, int c);
/**
 * 1-1-2
 */
int main(int argc, char *argv[])
{
	hanoi(4,'A','B','C');
	return 0;
}

void hanoi(int n, int a, int b, int c)
{
	if(n > 1){
		hanoi(n - 1, a, c, b);
		printf("%c to %c \n",a,c);
		hanoi(n - 1, b, a, c);
	}else{
		printf("%c to %c \n", a, c);
	}
}
