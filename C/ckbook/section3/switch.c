#include <stdio.h>

#define NDIGIT	10
/**
 * 3.4 switch
 * word count
 */
int main(int argc, char *argv[])
{
	int c, i, nwhite, nother, ndigit[NDIGIT];
	nwhite = nother =0;
	
	for( i = 0; i < NDIGIT; i++ ){
		ndigit[i] = 0;
	}
	
	while( ( c = getchar() ) != EOF ){
		
		switch(c){
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				ndigit[c-'0']++;
				break;
			
			case ' ': case '\n': case '\t':
				nwhite++;
				break;
				
			default:
				nother++;
				break;
		}
	}
	
	for( i = 0; i < NDIGIT; i++ ){
		printf(" %d", ndigit[i]);
	}
	
	printf(", white = %d, other = %d,\n", nwhite, nother );
	
	return 0;
}

