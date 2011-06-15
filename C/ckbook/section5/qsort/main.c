#include <stdio.h>
#include "line.h"
#include "sort.h"

#define MAXLINES	5000

/**
 * 5.6 sort file
 */
int main(int argc, char *argv[])
{
	int	nlines;
	char	*lineptr[MAXLINES];
	
	if( (nlines = readlines(lineptr, MAXLINES)) >= 0 ){
		qsort(lineptr, 0, nlines - 1);
		writelines( lineptr, nlines );
		return 0;
	}else{
		printf("error: input too big to sort\n");
		return 1;
	}
}

