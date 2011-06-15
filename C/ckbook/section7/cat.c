#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *from, FILE *to);

/**
 * 7.5 cat
 * 7.6 エラー処理
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *prog = argv[0];
	
	if( argc == 1 ){
		filecopy(stdin, stdout);
	}else{
		
		while( --argc > 0 ){
			if( (fp = fopen(*++argv, "r")) != NULL ){
				filecopy(fp, stdout);
				fclose(fp);
			}else{
				fprintf(stderr, "%s: can't open %s\n", prog, *argv);
				exit(1);
			}
		}
	}
	
	if( ferror(stdout) ){
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}
	
	exit(0);
}

void filecopy(FILE *ifp, FILE *ofp)
{
	int c;
	
	while( (c = getc(ifp)) != EOF ){
		putc(c,ofp);
	}
}

