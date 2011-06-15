#include <stdio.h>
#include <stdlib.h>


// 128 -> 10000000
#define TOP_BIT_MASK 128

// 扱えるバイト数(unsigned long に合わせておく) 
#define MAX_BYTE		32

void VBEncode(unsigned int input, unsigned char bytestream[]);
void printStream(unsigned char stream[]);
void printByte(unsigned char c);

/**
 * @memo long int をシフトしながら7ビットずつ区切ればよくない？
 */
int main(int argc, char *argv[])
{
	unsigned char bytestream[MAX_BYTE];
	unsigned int in;
	
	char *line = NULL;
	size_t len = 0;
	
	while (getline(&line, &len, stdin) != -1) {
		printf("%s", line);
		sscanf(line, "%d", &in);
		
		printf("%d\n",in);
		
//		VBEncode(in, bytestream);
//		printStream(bytestream);
	}

	if (line) free(line);
	
	return 0;
}

void VBEncode(unsigned int input, unsigned char bytestream[])
{
	unsigned char	mask = TOP_BIT_MASK;
//	unsigned char	bytestream[MAX_BYTE];
	int	i;
	
	//initializing byte stream
	for(i = 0; i < MAX_BYTE; bytestream[i++] = '\0');
	
	i = 0;
	while( input > TOP_BIT_MASK ){

		if( bytestream[0] < TOP_BIT_MASK ){
			bytestream[0]++;
			input %= TOP_BIT_MASK;
			i++;
		}else{
			/**
			 * @todo 繰上げ計算 とりあえずエラーにしておく
			 */
			fprintf(stderr,"error over flow\n");
			exit(2);
		}
	}
	bytestream[i] = input | mask;
	bytestream[i+1] = '\0';
}

void printStream(unsigned char stream[])
{
	int i = 0;
	while(stream[i]){
		printByte(stream[i]);
		i++;
	}
	printf("\n");
}

void printByte(unsigned char c)
{
	printf("%o\t", c);
}

