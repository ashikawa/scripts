#include <stdio.h>
#include <ctype.h>

#define ctoi(c)	( c - '0' )

int	getch();
void	ungetch(int i);

int getint(int *pn)
{
	
	int c, sign;
	
	while( isspace(c = getch()) )
		;
	
	if( !isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	
	if( c == '+' || c == '-' ){
		c = getch();
	}
	
	for( *pn = 0; isdigit(c); c = getch() ){
		*pn = 10 * *pn + ctoi(c);
	}
	
	*pn *= sign;
	
	if(c != EOF){
		ungetch(c);
	}
	
	return c;
}

