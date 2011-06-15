#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void itoa(int n, char s[]);
void reverse(char s[]);
void change(char v[], int i, int j);

/**
 * 3.6 itoa
 */
int main(int argc, char *argv[])
{
	char in[MAX_LENGTH];
	int  n = -1000;
	
	itoa( n, in );
	
	printf("%s\n", in);
	return 0;
}


void itoa(int n, char s[])
{
	int i = 0;
	int sign;
	
	if( (sign = n) < 0){
		n *= -1;
	}
	
	do{
		s[i++] = n % 10 + '0';
	} while ( (n /= 10) > 0 );
	
	if( sign < 0){
		s[i++] = '-';
	}
	
	s[i]	 = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int i;
	int len = strlen(s);
	
	for( i = 0; i < len / 2; i++ ){
		change( s, i, len - i - 1);
	}
}

void change(char v[], int i, int j)
{
	int temp  = v[i];
	v[i] = v[j];
	v[j] = temp;
}

