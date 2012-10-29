#include <stdio.h>

/*
	Lesson9
	Lesson10
	Lesson11
*/

float	getMax(float a, float b);
void	sayHi(void);


int main(void) {

	float result = getMax(2.3, 5.2);

	printf("result : %f\n", result);
	sayHi();

	return 0;
}

float getMax(float a, float b) {

	// if(a >= b){
	// 	return a;
	// }
	// return b;
	
	return (a >= b) ? a : b;
}

void sayHi(void) {
	printf("hi!\n");
}
