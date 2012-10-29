#include <stdio.h>

/*
	Lesson5
*/
int main(void) {

	int	score = 55;

	if (score >= 60) {
		printf("OK!\n");
	} else if(score >= 50) {
		printf("so so...\n");
	} else {
		printf("NG!\n");
	}

	return 0;
}
