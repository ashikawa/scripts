#include <stdio.h>

void squeeze(int s, char sl[]);

#define MAX_LENGTH 100

/**
 * 2-4 squeeze
 */
int main(int argc, char *argv[])
{
	int	i = 0;
	char	in[MAX_LENGTH];
	char	c;
	
	while( ( c = getchar() ) != EOF ){
		
		in[i] = c;
		
		if( c == '\n' ){
			
			in[i+1] = '\0';
			squeeze('e', in);
			printf("%s", in );
			i = 0;
			
		}else{
			i++;
		}
	}
	
	return 0;
}

void squeeze( int s, char sl[] )
{
	int	i,j;					//ループカウンタ
	
	for( i = j = 0; sl[i] != '\0'; i++ )
		if( sl[i] != s) sl[j++] = sl[i];
	
	sl[j] = '\0';
}

