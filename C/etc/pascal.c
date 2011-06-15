#include <stdio.h>
#define MAX_N 10

void pascal();
void pascal2();

int main(int argc, char *argv[])
{
	//pascal();
	
	int depth = 10;
	pascal2(1, 1, depth);
	
	return 0;
}

void pascal2(int l, int r, int depth)
{
	if( !depth-- ) return ;
}

void pascal()
{
	int i, j;
	int tpas[MAX_N + 1][MAX_N + 1];

	for (i = 1; i <=MAX_N; i++) {
		for (j = 1; j <= MAX_N; j++) {
			if (j == 1){
				tpas[i][j] = 1;
			}else if (j == i) {
				tpas[i][j] = 1;
				break;
			}else{
				tpas[i][j] = tpas[i - 1][j - 1] + tpas[i - 1][j];
			}
		}
	}
	
	for (i = 1; i <= MAX_N; i++) {
		
		printf("%d:\t",i);
		
		for (j = 1; j <= MAX_N; j++) {
			if (i == j) {
				printf("%3d", tpas[i][j]);
				break;
			}else{
				printf("%3d ", tpas[i][j]);
			}
		}
		printf("\n");
	}
}

