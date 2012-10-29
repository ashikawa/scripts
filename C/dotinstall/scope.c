#include <stdio.h>

/*
	Lesson12
	Lesson13
*/
// int a = 0;	// グローバル変数

void f(void) {
	static int a = 0;	// 静的変数
	// int a = 0;	// ローカル変数	自動変数
	a++;
	printf("%d\n", a);
}

int main(void) {
	f();
	f();
	f();
	// printf("%d\n", a);
	return 0;
}
