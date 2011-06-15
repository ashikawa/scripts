#include <stdio.h>


/**
 * コマンドライン引数の確認
 */
int main(int argc, char *argv[])
{
	while( --argc ){
		printf("%s\n", *++argv);
	}
	
	return 0;
}

