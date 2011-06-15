#include <stdio.h>

#define MAX_LENGTH 1000

void expand(char in[], char out[]);

/**
 * 3-3 expand
 */
int main(int argc, char *argv[])
{
	char in[MAX_LENGTH] = "a-n-zhoge0-4";
	char out[MAX_LENGTH];
	
	expand(in,out);
	
	printf("%s\n", out);
	
	return 0;
}

/**
 * 一応完成。
 * もっとシンプルに書き直し
 */
void expand(char in[], char out[])
{
	int i, j, c, n;
	j = 0;
	
	for( i = 0; ( c = in[i] ) != '\0'; i++ ){
		if( c == '-' ){
			for( n = in[i-1] + 1; n < in[i+1]; n++ ){
				out[j++] = n;
			}
		}else{
			out[j++] = c;
		}
	}
	out[j] = '\0';
}

