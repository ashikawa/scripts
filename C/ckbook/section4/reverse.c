#include <stdio.h>
#include <string.h>

#define MAX_LENGTH	1000

#define swap(t,x,y)	{int temp = t[x]; t[x] = t[y]; t[y] = temp;}

void reverse(char s[]); 

/**
 * 4-14 swap macro
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
		swap( s, i, len - i - 1);
	}
}

