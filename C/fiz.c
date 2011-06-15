#include <stdio.h>

#define MAX_LOOP 100

int main(int argc, char *argv[])
{
	int i = 0;
	int try = 0, fif = 0;
	
	for( i=0; i < MAX_LOOP; i++){
		
		try = ( i%3 == 0 );
		fif = ( i%5 == 0 );
		
		if( try && fif ){
			printf("fizBiz\n");
			continue;
		}
		
		if( try ){
			printf("fiz\n");
			continue;
		}

		if( fif ){
			printf("biz\n");
			continue;
		}
		
		printf("%d\n",i);
	}
	return 0;
}

