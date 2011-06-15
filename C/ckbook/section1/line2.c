#include <stdio.h>

#define MAXLINE 100

int getline();
int copy();

int max;						//今まで出てきた最大長
	
char line[MAXLINE];		//現在の入力行
char longest[MAXLINE];	//格納されている最長行

/**
 * 1.10 gloval vars
 * グローバル変数のサンプルであり、
 * プログラムの質としては前回のプログラム(line.c)より劣る
 * p41
 */	
int main(int argc, char *argv[])
{
	
	int len;						//現在行の長さ
	
	extern int max;
	extern char longest[];
	
	max = 0;
	
	while( (len = getline()) > 0 ){
		if( len > max ){
			max = len;
			copy();
		}
	}
	
	if( max > 0 ){
		printf("%s", longest);
	}
	
	return 0;
}

int getline()
{
	int c, i;
	extern char line[];
	
	for( i = 0; (i < MAXLINE - 1) && ( (c = getchar() ) != EOF ) && ( c != '\n') ; i++ ){
		line[i] = c;
	}
	if( c == '\n' ){
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}

int copy ()
{
	int i;
	
	extern char line[], longest[];
	
	i = 0;
	
	while( (longest[i] = line[i]) != '\0' ) i++;
	
	return i;
}

