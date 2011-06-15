#include <stdio.h>

#define MAX_LENGTH	1000 

int escape( char in[], char out[] );

/**
 * 3-2 escape
 */
int main(int argc, char *argv[])
{
	int c;
	char in[MAX_LENGTH];
	char out[MAX_LENGTH];
	int i = 0;
	
	while( (c = getchar() ) != EOF){
		in[i++] = c;
	}
	
	in[i] = '\0';
	
	escape(in, out);
	
	printf("%s\n", out);
	
	return 0;
}

/**
 *	タブ、改行のエスケープ
 */
int escape( char in[], char out[] )
{
	int i = 0;
	int j = 0;
	int c;
		
	while( ( c = in[i++] ) != '\0' ){
		
		switch ( c ) {
			case '\n':
				out[j++] = '\\'; 
				out[j++] = 'n'; 
				break;
			case '\t':
				out[j++] = '\\'; 
				out[j++] = 't'; 
				break;
			default:
				out[j++] = c;
				break;
		}
	}
	
	out[j] = '\0';
	
	return j;
}
