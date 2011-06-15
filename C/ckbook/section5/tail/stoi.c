#include "stoi.h"


int stoi(char *hex)
{
   int	num;		//入力文字を数字に変換したもの
   long	ret = 0;	//戻り値
	int	c;
	int	i = 0;	//ループカウンタ
	
	while( (c = *(hex++) ) != '\0' ){
		
		if( '0' <= c && c <='9' ){
			num = c - '0';
		}else{
			printf("error: wrong char %s", hex);
			exit(1);
		}
		ret = num + ( i++ * 10);
	}
	
	return ret;
}

