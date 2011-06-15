#include <stdio.h>
#include <string.h>

#define swap(x,y)  {int t = x; x = y; y = t;}

void reverse(char *);

/**
 *  5-6 reverse pointer
 */
int main(int argc, char *argv[])
{

   char in[] = "testhogemoge";

   printf("%s\n", in);
   
	reverse(in);

   printf("%s\n", in);

   return 0;
}

/**
 * 入力が偶数の時、奇数の時を確認すること
 */
void reverse(char *s)
{
   char *c = s;
	
	while( *++c );
	
	s--;
	while( s++ < c-- ) swap( *s, *c );
}


