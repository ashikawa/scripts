#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 255

int atoi(char s[]);

/**
 * 3.5 atoi
 */
int main(int argc, char *argv[])
{
	char s[] = "-10000";
	
	printf("%d\n",atoi(s));
	
	return 0;
}

int atoi(char s[])
{
	int i, n, sign;
	
	for( i = 0; isspace(s[i]); i++ )
		;
	
	sign = ( s[i] == '-' ) ? -1 : 1;
	
	if( s[i] == '+' || s[i] == '-' ){
		i++;
	}

	for( n = 0; isdigit(s[i]); i++ ){
		n = 10 * n + ( s[i] - '0' );
	}
	
	return sign * n;
}
