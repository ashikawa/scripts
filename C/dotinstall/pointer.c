#include <stdio.h>

/*
	Lesson16
	Lesson17
	Lesson18
	Lesson19
	Lesson20
	Lesson21
	Lesson22
	ポインタ : アドレスを格納するための変数
		メモリの節約
	& : アドレス演算子
	* : 間接演算子
*/

// 値渡し
void f(long a) {
	a += 100;
	printf("%ld\n", a);
}

// 参照渡し
void f2(long *pa) {
	*pa += 100;
	printf("%ld\n", *pa);
}

void swap(int *pa, int *pb) {
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

int main(void) {

	long a = 1000;
	// f(a);
	f2(&a);

	printf("%ld\n", a);


	int sa = 5;
	int sb = 10;
	swap(&sa, &sb);

	printf("a:%d b:%d\n", sa, sb);
	return 0;
}
