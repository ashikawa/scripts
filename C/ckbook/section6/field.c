#include <stdio.h>

typedef unsigned short int bool;

#define true	1
#define false	0

/**
 * 6.7 typedef
 * 6.9 bit field
 */
int main(int argc, char *argv[])
{
	struct {
		signed int isHoge : 1;
	} flags;
	
// ビットフィールドは構造体でしか宣言できない。
	
	flags.isHoge = true;
	
	if(flags.isHoge){
		printf("true\n");
	}else{
		printf("false\n");
	}

// sizeof はビットフィールドには使えない。	
//	printf("%d\n", sizeof(flags.isHoge));
	return 0;
}

