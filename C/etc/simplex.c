/**
 * 日系フソフトウェア 2010 8 付録
 * シンプレックス法
 */

#include <stdio.h>

#define ROW_NUM 3
#define COLUMN_NUM 5

char* title = "m\t\tn\t\ta\t\tb\t\tright";

double table[ROW_NUM][COLUMN_NUM] = {
	{6, 3, 1, 0, 360},
	{2, 4, 0, 1, 240},
	{-600, -400, 0, 0, 0}
};


void showTable()
{
	int r, c;

	printf("%s\n", title);
	for(r = 0; r < ROW_NUM; r++){
		for(c = 0; c < COLUMN_NUM; c++){
			printf("%lf\t", table[r][c]);
		}
		printf("\n");
	}
	printf("\n");
	getchar();
}

int main(int argc, char *argv[])
{
	int selRow, selColumn;
	int r, c;
	double min;
	double pivot;
	double mul;
	
	showTable();
	
	while(-1){
		min = table[ROW_NUM - 1][0];
		selColumn = 0;

		for( c=1; c < COLUMN_NUM; c++ ){
			if(min > table[ROW_NUM -1][c]){
				min = table[ROW_NUM - 1][c];
				selColumn = c;
			}
		}
		
		if( min >=0 ) break;
		
		min = table[0][COLUMN_NUM - 1] / table[0][selColumn];
		
		selRow = 0;
		
		for(r = 1; r < ROW_NUM -1; r++){
			if(min > table[r][COLUMN_NUM -1] / table[r][selColumn]){
				min = table[r][COLUMN_NUM - 1] / table[r][selColumn];
				selRow = r;
			}
		}
		
		
		pivot = table[selRow][selColumn];
		for(c = 0; c < COLUMN_NUM; c++){
			table[selRow][c] /= pivot;
		}
		
		for(r = 0; r < ROW_NUM; r++){
			if(r == selRow) continue;

			mul = table[r][selColumn];
			for( c = 0; c < COLUMN_NUM; c++ ){
				table[r][c] -= table[selRow][c] * mul;
			}
		}
		showTable();
	}
	
	printf("max = %lf\n", table[ROW_NUM - 1][COLUMN_NUM -1]);
	return 0;
}

