#include <stdio.h>


struct point{
	int x;
	int y;
};

/**
 * 6.1 struct
 * 6.2 struct pointer
 */
int main(int argc, char *argv[])
{
	struct point p1	= { 5, 10 };
//	struct point *p2	= { 3, 9 };
	struct point *p2	= &p1;
	
	printf("%d,%d\n", p1.x , p1.y);
	
	p2->x = 3;
	p2->y = 9;
	
	printf("%d,%d\n", p1.x , p1.y);
	printf("%d,%d\n", p2->x , p2->y);
	
	return 0;
}

