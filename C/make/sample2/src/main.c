#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"
#include "sort.h"
#include "cmp.h"

#define MAXLINES	5000

int	sort(int numeric);
void	*getcmp();

/**
 * 各種フラグ
 * n	数字のみ
 */
int numeric = 0;
int reverse = 0;

/**
 * 5.11 sort file
 * 関数ポインタ
 */
int main(int argc, char *argv[])
{
	int c;
	char *arg;
	
	while( --argc > 0){
		
		if( (arg = *++argv)[0]  == '-' ){
			while(c = *++arg){
				switch(c){
					case 'n':
						numeric = 1;
						break;
					case 'r':
						reverse = 1;
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
		return sort(numeric);
	}
}

int sort(int numeric)
{
	int	nlines;
	char	*lineptr[MAXLINES];
	
	if( (nlines = readlines(lineptr, MAXLINES)) >= 0 ){
		myqsort(lineptr, 0, nlines - 1,  getcmp() );
		writelines( lineptr, nlines );
		return 0;
	}else{
		printf("error: input too big to sort\n");
		return 1;
	}
}


void *getcmp()
{
	if( numeric ){
		if( reverse ){
			return (int (*)(void *, void *))( numcmpr );
		}else{
			return (int (*)(void *, void *))( numcmp );
		}
	}else{
		if( reverse ){
			return (int (*)(void *, void *))(strcmpr);
		}else{
			return (int (*)(void *, void *))(strcmp);
		}
	}
}

