#include <stdio.h>
#include <string.h>
#include "line.h"
#include "alloc.h"

int readlines(char *lineptr[], int maxlines)
{
	int	len , nlines;
	char	*p, line[MAXLEN];
	nlines = 0;
	
	while( (len = getline(line, MAXLEN)) > 0 ){

		if( nlines >= maxlines || (p = alloc(len)) == NULL ){
			return -1;
		}else{
			line[len-1] = '\0';
			strcpy(p,line);
			lineptr[nlines++] = p;
		}
	}
	
	return nlines;
}

int writelines(char *lineptr[], int nlines)
{
	while(nlines-- > 0){
		printf("%s\n", *lineptr++);
	}
}

int getline( char *s, int lim )
{
	int	c;
	char	*p = s;
	
	while( lim-- && ((c = getchar() ) != EOF)  && (c != '\n') ){
		*p++ = c;
	}
	
	if( c == '\n' ){
		*p++ = c;
	}
	
	*p = '\0';
	return p - s;
}

