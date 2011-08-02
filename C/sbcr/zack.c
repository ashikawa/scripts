/**
 *List 11-1
 */
#include <stdio.h>
#include <stdio.h>

#define EXIT_SUCCESS 0

#define N 5
#define NAP_SIZE 16

int size[N]		= {2, 3, 5, 6, 9};
int value[N]	= {2, 4, 7, 10, 14};


int main(int argc, char *argv[])
{
	int nap_value[NAP_SIZE + 1] = {0};
	int i, j, new_value;
	
	
	
	for( i = 1; i < NAP_SIZE + 1; i++ ){
		printf("%d\t", i);
	}
	printf("\n");
	
	
	
	for( i=0; i < N + 1; i++ ){
		
		for( j = size[i]; j <  NAP_SIZE + 1; j++ ){
			new_value = nap_value[j - size[i]] + value[i];
			
			if( new_value > nap_value[j] ){
				nap_value[j] = new_value;
			}
		}
		
		for( j = 1; j < NAP_SIZE + 1; j++ ){
			printf("%d\t", nap_value[j]);
		}
		printf("\n");
	}
	
	return EXIT_SUCCESS;
}
