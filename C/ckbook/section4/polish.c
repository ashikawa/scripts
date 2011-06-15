#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_STACK	255
#define NUMBER		'0'
#define BUFSIZE	100


double	pop();
int		push(double x);
int		getop(char s[]);
int		getch();
void		ungetch(int c);

double	stack[MAX_STACK];
int		sp	= 0;
char		buf[BUFSIZE];
int		bufp = 0;


/**
 * 4.3 逆ポーランド電卓
 * 4-3
 */
int main(int argc, char *argv[])
{
	int		type;
	double	op2;
	char		s[BUFSIZE];

	while( (type = getop(s)) != EOF ){

		switch(type){
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push( pop() * pop() );
				break;
			case '-':
				op2 = pop();
				push( pop() - op2 );
				break;
			case '/':
				op2 = pop();
				if( op2 != 0.0 ){
					push( pop() / op2 );
				}else{
					printf("error: division by zero\n");
				}
				break;
//何故かfmodが見つからない
//			case '%':
//				op2 = pop();
//				push( fmod(pop(), op2) );
//				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	
	return 0;
}


double pop()
{
	if( sp > 0 ){
		return stack[--sp];
	}else{
		printf("error: stack is empty\n");
		return 0.0;
	}
}

int push(double x)
{
	if( sp < MAX_STACK){
		stack[sp++] = x;
		return sp;
	}else{
		printf("error: stack full");
		return -1;
	}
}

int getop(char s[])
{
	int i = 0;
	int c;
	
	while( (s[0] = c = getch()) == ' ' || c == '\t' )
		;
	
	s[1] = '\0';
	
	if( !isdigit(c) && c != '.' ){
		return c;
	}
	
	if( isdigit( s[++i] = c = getch() ) ){
		while( isdigit(s[++i] = c = getch() ) )
			;
	}
	
	if( c == '.'){
		while( isdigit( s[++i] = c = getch() ) )
			;
	}
	
	s[i] = '\0';
	
	if( c != EOF ){
		ungetch(c);
	}
	
	return NUMBER;
}

int getch()
{
	return ( bufp > 0 ) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE){
		printf("ungetch: too many characters\n");
	}else{
		buf[bufp++] = c;
	}
}

