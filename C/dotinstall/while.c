#include <stdio.h>

/*
	Lesson7
*/
int main(void) {

	int	m = 20;

	while (m < 10){
		printf("m: %d\n", m);
		m++;
	}

	int n = 20;

	do {
		printf("n: %d\n", n);
		n++;
	} while (n < 10);

	return 0;
}
