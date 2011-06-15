#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void reverse(char s[]);
void change(char v[], int i, int j);

/**
 * 1-19 reverse
 */
int main(int argc, char *argv[])
{
	
	char in[] = "abcdef";
	
	reverse(in);
		
	printf("%s\n", in);
	return 0;
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

