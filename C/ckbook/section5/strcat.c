#include <stdio.h>

#define MAX_LENGTH	255
void strcatp(char *, char * );

/**
 * 5-3 strcat pointer ver
 * 
 */
int main(int argc, char *argv[])
{
	char in[MAX_LENGTH]	= "testhoge";
	char add[MAX_LENGTH]	= "mogemoge";
	
	strcatp(in, add);
	
	printf("%s\n", in);
	
	return 0;
}


/**
 * in に十分な領域が割り当てられているとする
 */
void strcatp(char *in, char *add)
{
	while( *++in )
		;
	
	while( *in++ = *add++)
		;
}
