#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOOP		1000000
#define ARRAY_LENGTH	80
#define RAND_UPPER	100
#define RAND_LOWER	0

int getrand(int min, int max);
int average(int x, int y);

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

/**
 * 3-1 二分探索
 * binsearch の高速化
 * 
 * 結果: 何故か binsearch2 が低速化
 * 配列を極端に大きくすれば、誤差がちょっと縮まる
 */
int main(int argc, char *argv[])
{
	
	int in[] = {
			0,1,2,3,4,5,6,7,9,11,12,13,14,15,17,18,19,20,21,22,
			24,26,27,28,29,31,32,33,35,36,37,39,40,41,42,44,45,48,50,51,
			52,53,54,55,56,57,58,59,60,63,66,67,69,70,71,72,73,74,75,76,
			77,78,79,80,81,82,83,84,85,86,87,88,89,91,92,94,95,97,99,100,
		};
	
	clock_t start,end;
	int i;
	
	
	start = clock();
	for( i = 0; i <= MAX_LOOP; i++){
		binsearch(getrand(RAND_LOWER,RAND_UPPER), in, ARRAY_LENGTH);
	}
	end = clock();
	printf("%f sec\n",(double)(end-start) / CLOCKS_PER_SEC);
		
	
	start = clock();
	for( i = 0; i <= MAX_LOOP; i++){
		binsearch2(getrand(RAND_LOWER,RAND_UPPER), in, ARRAY_LENGTH);
	}
	end = clock();
	printf("%f sec\n",(double)(end-start) / CLOCKS_PER_SEC);
	
	return 0;
}

/**
 * min ～ max の乱数の取得
 * シードの生成はコストが高いため、今回は実行しない
 */
int getrand(int min, int max)
{
//	srand((unsigned int)time(NULL));
	return min + (int)( rand() * ( max - min + 1.0 ) / ( 1.0 + RAND_MAX ) );
}

/**
 * ニ値の平均(切捨て)
 */
int average(int x, int y)
{
	return ( x + y ) / 2;
}

/**
 * テキストの物と同じ
 * ループ内の if - else は、ヒットする確立が高いものから
 * 書いた方が、トータルのコストが低くなる。
 * (続くテストが実行されない可能性が高くなるため)
 */
int binsearch(int x, int v[], int n)
{
	int low	= 0;
	int high	= n - 1;
	int mid;	
	
	while( low <= high ){
		mid = average(low, high);
		
		if( x < v[mid]){
			high = mid - 1;
		}else if( x > v[mid]){
			low = mid + 1;
		}else{
			return mid;
		}
	}
	
	return -1;
}

/**
 * 一見処理は少なくなっているが、
 * return が無いので、 while の比較が必要以上に動いている
 */
int binsearch2(int x, int v[], int n)
{
	int low	= 0;
	int high	= n - 1;
	int mid;	
	
	while( low <= high ){
		mid = average(low, high);
		
		if( x < v[mid] ){
			high = mid - 1;
		}else{ 
			low = mid + 1;
		}
	}
	
	if( v[mid] == x ){
		return mid;
	}else if( v[mid-1] == x ){
		return mid - 1;
	}
	
	return -1;
}

