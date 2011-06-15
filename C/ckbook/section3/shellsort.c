#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH	10

int getrand(int min, int max);
void shellsort(int v[], int n);
void change(int v[], int i, int j);
void dump(int in[], int n);

/**
 * 3.5 shellsort
 */
int main(int argc, char *argv[])
{
	int in[ARRAY_LENGTH];
	int i;
	
	srand((unsigned int)time(NULL));	
	for(i = 0; i < ARRAY_LENGTH; i++ ){
		in[i] = getrand(0,99);
	}
	
	shellsort(in, ARRAY_LENGTH);
	
	dump(in, ARRAY_LENGTH);
	
	return 0;
}

int getrand(int min, int max)
{
	return min + (int)( rand() * ( max - min + 1.0 ) / ( 1.0 + RAND_MAX ) );
}


/**
 * Shell Sort
 */
void shellsort(int v[], int n)
{
	int gap, i, j;
	
	for( gap = n/2; gap > 0; gap /= 2){
		for( i = gap; i < n; i++ ){
			for( j = i-gap; j >= 0 && v[j] > v[j+gap]; j-=gap ){
				change(v, j, j+gap);
				dump(v, n);	
			}
		}
	}
}

/**
 * 配列の要素を入れ替える
 */
void change(int v[], int i, int j)
{
	int temp  = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/**
 * 配列の出力
 */
void dump(int in[], int n)
{
	int i;
	
	for(i = 0; i < n; i++ ){
		printf("%d, ", in[i]);
	}
	printf("\n");
}

