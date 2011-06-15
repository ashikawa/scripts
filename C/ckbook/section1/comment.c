#include <stdio.h>

#define MAXLINE	100

#define STATE_IN	1
#define STATE_OUT	0

int getline(char line[], int maxline);


/**
 * 演習1-23
 * Cソースからコメントを削除する
 */
int main(int argc, char *argv[])
{
	int len;						//現在行の長さ
	int state;	
	int i,j;
	
	char line[MAXLINE];		//現在の入力行
	char out[MAXLINE];		//出力行
	
	state = STATE_IN;
	
	while( (len = getline(line, MAXLINE)) > 0 ){
		
		j = 0;	
		for( i = 0; i < len + 1; i++ ){
			
			if(state == STATE_IN){
				if(line[i] == '/' && line[i+1] == '*'){
					state = STATE_OUT;
					break;
				}
				
				if( line[i] == '/' && line[i+1] == '/'){
					out[j] = '\n';
					out[j+1] = '\0';
					break;
				}
				
			}else{
				if(line[i] == '*' && line[i+1] == '/'){
					state = STATE_IN;
					i +=  2;
				}
			}
			
			out[j++] = line[i];
		}
		
		if(state == STATE_IN){
			printf("%s", out);
		}
	}
	
	return 0;
}

int getline(char s[], int lim)
{
	int c, i;
	
	for( i = 0; (i < lim - 1) && ( (c = getchar() ) != EOF ) && ( c != '\n') ; i++ ){
		s[i] = c;
	}
	if( c == '\n' ){
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

