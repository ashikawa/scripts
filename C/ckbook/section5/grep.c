#include <stdio.h>
#include <string.h>

#define MAXLINE 	1000

long grep(char *pattern, int number, int except);
int getline( char *s, int lim );

/**
 * 5.10 grep
 * main 関数の引数
 */
int main(int argc, char *argv[])
{
	int	c, except = 0, number = 0;
	
	while( --argc > 0 && (*++argv)[0] == '-'){
		while(c = *++argv[0]){
			switch(c){
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option %c\n", c);
					argc = 0;
					break;
			}
		}
	}
	
	if(argc != 1){
		printf("Usage: find -x -n pattern\n");
		return -1;
	}else{
		return grep( *argv, number, except);
	}
}

long grep(char *pattern, int number, int except)
{
	long	lineno = 0;
	char	line[MAXLINE];
	int	found = 0;
	
	while( getline(line, MAXLINE) > 0 ){
		lineno++;
		
		if( (strstr(line, pattern) != NULL ) != except ){
			if( number ){
				 printf("%ld:",lineno);
			}
			printf("%s", line);
			found++;
		}
	}
	return found;
}

int getline( char *s, int lim )
{
   int   c;
   char  *p = s;

   while( lim-- && ((c = getchar() ) != EOF)  && (c != '\n') ){
      *p++ = c;
   }

   if( c == '\n' ){
      *p++ = c;
   }

   *p = '\0';
   return p - s;
}

