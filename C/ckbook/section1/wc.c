#include <stdio.h>

#define IN	1
#define OUT	0


/**
 * 1.5.2 word count
 */
int main(int argc, char *argv[])
{
	int c, nl, nw, nc, state;
	
	state = OUT;
	nl = nw = nc = 0;
	
	while( (c = getchar()) != EOF ){
		nc++;
		
		if(c == '\n') nl++;
		
		if( c == ' ' || c == '\n' || c == '\t' ){
			state = OUT;
		}else if( (state == OUT) ){
			state = IN;
			nw++;
		}
	}
	
	printf("%d lines\n%d words\n%d chars\n", nl, nw, nc);
	
	return 0;
}

