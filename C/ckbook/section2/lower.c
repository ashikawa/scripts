#include <stdio.h>

#define MAX_LENGTH	100

int lower(int c);

/**
 * 2-10 lower
 * 三項演算子
 */
int main(int argc, char *argv[])
{
	char in[MAX_LENGTH] = "Test HogeMoge";
	int i = 0;
	
	while ( in[i] != '\0' ){
		printf("%c", lower(in[i]) );
		i++;
	}
	
	printf("\n");
	return 0;
}

int lower(int c)
{
	return ( 'A' <= c && c <= 'Z' ) ? c + 'a' - 'A' : c;
}
