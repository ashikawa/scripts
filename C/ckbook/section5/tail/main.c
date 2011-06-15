#include <stdio.h>
#include <string.h>
#include "line.h"
#include "stoi.h"

#define MAXLINE 	1000

long tail( int number );

/**
 * 5-13 tail
 */
int main(int argc, char *argv[])
{
	int c, number = 10;
	char *arg;

	while( --argc > 0){
		
		if( (arg = *++argv)[0]  == '-' ){
		
			while(c = *++arg){
				switch(c){
					case 'n':
						number = stoi( *++argv );
						argc--;
						break;
					default:
						printf("find: illegal option %c\n", c);
						argc = 0;
						break;
				}
			}

		}
	}
		
	if(argc != 0){
		printf("Usage: find -n [num] pattern\n");
		return -1;
	}else{
		return tail( number );
	}
}

long tail( int number)
{
	int	lineno;
	int	start;
	char	*line[MAXLINE];
	
	if( (lineno = readlines(line, MAXLINE)) > 0 ){
		
		start = ( lineno > number ) ? lineno - number : 0;
		writelines( (line + start), lineno - start  );
		
	}
	
	return number;
}

