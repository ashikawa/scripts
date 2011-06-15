#include <stdio.h>

#define MAXLINE 100

int getline(char line[], int maxline);
int copy(char to[], char from[]);

/**
 * 1.9 longest line
 * functions sample
 * char array sample
 */
int main(int argc, char *argv[])
{
	int len;						//現在行の長さ
	int max;						//今まで出てきた最大長
	
	char line[MAXLINE];		//現在の入力行
	char longest[MAXLINE];	//格納されている最長行
	
	
	max = 0;
	
	while( (len = getline(line, MAXLINE)) > 0 ){
		if( len > max ){
			max = len;
			copy(longest, line);
		}
	}
	
	if( max > 0 ){
		printf("%s", longest);
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

int copy (char to[], char from[])
{
	int i;
	i = 0;
	
	while( (to[i] = from[i]) != '\0' ) i++;
	
	return i;
}

