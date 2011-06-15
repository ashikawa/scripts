#include <stdio.h>

#define N 3

int b[N];

void truth_table(int k);
void truth2();
char toString();

/**
 * 1-2-1
 */
int main(int argc, char *argv[])
{
//	truth_table(0);
	truth2();
	return 0;
}

void truth_table(int k)
{
	int i;
	
	if(k < N){
		b[k] = 0;
		truth_table(k + 1);
		b[k] = 1;
		truth_table(k + 1);
	}else{
		for(i = 0; i < N; i++){
			printf("%c ", toString(b[i]));
		}
		printf("... %c\n",
					toString( b[0] || (b[1] && (!b[2])))) ;
	}
}

void truth2()
{
	unsigned int bits;
	
	for(bits = 0; bits <= 0007; bits++){
		
		printf("%c %c %c\n",
				toString(bits & 0001), toString(bits & 0002), toString(bits & 0004) );
	}
}

char toString(unsigned int i)
{
	return i ? 'T' : 'F';
}

