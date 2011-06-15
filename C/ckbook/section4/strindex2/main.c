#include <stdio.h>
#include "myheader.h"

#define MAXLINE 1000

int strindex(char source[], char searchfor[]);


/**
 * 4.1 ソースの分割
 */
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;
	
	char pattern[] = "test";
	
	while( getline(line, MAXLINE) > 0 ){
		if(strindex( line, pattern) >= 0 ){
			printf("%s\n", line);
			found++;
		}
	}
	
	return found;
}

int strindex(char s[], char t[])
{
	int i, j, k;
	for( i = 0; s[i] != '\0'; i++){
		for( j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		
		if( k > 0 && t[k] == '\0' ){
			return i;
		}
	}
	
	return -1;
}

