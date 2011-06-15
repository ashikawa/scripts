#include <stdio.h>

int printBar(int n);

int main(int argc, char *argv[])
{
	int c, i, j, nwhite, nother;
	int ndigit[10];
	
	nwhite = nother = 0;
	
	for( i = 0; i < 10; i++ ){
		ndigit[i] = 0;
	}
	
	while( (c = getchar()) != EOF ){
		if( c >= '0' && c <= '9' ){
			ndigit[c-'0']++;
		}else if( c == ' ' || c == '\n' || c == '\t' ){
			nwhite++;
		}else{
			nother++;
		}
	}
	
	for( i = 0; i < 10; i++ ){
		printf("%2d|", i);
		printBar(ndigit[i]);
		printf("\n");
	}
	
	printf("ws|");
	printBar(nwhite);
	printf("\n");
	
	
	printf(" o|");
	printBar(nother);
	printf("\n");
	
	return 0;
}

int printBar(int n)
{
	while(n--) printf("=");
	return n;
}

