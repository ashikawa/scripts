#include <stdio.h>

int htoi(char hex[]);

#define MAX_LENGTH 100

/**
 * 2-3 16進数 char を int に変換
 */
int main(int argc, char *argv[])
{
	int i = 0;
	char in[MAX_LENGTH];
	char c;
	
	while( ( c = getchar() ) != EOF ){
		
		if( c == '\n' ){
			in[i] = '\0';
			printf("%d\n", htoi(in) );
			i = 0;
		}else{
			in[i] = c;
			i++;
		}
	}
	
	return 0;
}

int htoi(char hex[])
{
	int i;				//ループカウンタ
	int num;				//入力文字を数字に変換したもの
	long ret	= 0;		//戻り値
	
	for( i = 0; hex[i] != '\0'; i++ ){
		
		if( '0' <= hex[i]  && hex[i] <= '9' ){
			
			num = hex[i] - '0';
			
		}else if( 'a' <= hex[i]  && hex[i] <= 'f'){
			
			num = hex[i] - 'a' + 10;
			
		}else if( 'A' <= hex[i]  && hex[i] <= 'F'){
			
			num = hex[i] - 'A' + 10;
			
		}

		ret = num + ( i * 16 ); 
	}

	return ret;	
}

