#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key *binsearch(char *, struct key *, int);

struct key{
	char	*word;
	int	count;
};
struct key keytab[] = {
	{"auto", 0},
	{"break", 0},
	{"case", 0},
	{"char", 0},
	{"const", 0},
	{"continue", 0},
	{"default", 0},
	{"unsigned", 0},
	{"void", 0},
	{"volatile", 0},
	{"while", 0},
//	{"", 0},
};

#define NKEYS (sizeof keytab / sizeof keytab[0])

/**
 * 6.3
 * 6.4 binsearch struct pointer
 */
int main(int argc, char *argv[])
{
	
	char word[MAXWORD];
	struct key *p;
	
	while( getword( word, MAXWORD ) != EOF ){
		
		if( isalpha(word[0]) ){
			if( (p = binsearch( word, keytab, NKEYS )) != NULL ){
				p->count++;
			}
		}
	}
	
	for(p = keytab; p < keytab + NKEYS; p++){
		if(p->count > 0){
			printf("%4d %s\n", p->count, p->word);
		}
	}
	
	return 0;
}

struct key *binsearch(char *word, struct key *tab, int n)
{
	int cond;
	struct key *low	= &tab[0];
	struct key *high	= &tab[n];
	struct key *mid;
	
	while(low < high){
//間違い。　ポインタ同士の足し算は禁止されている
//		mid = (high+low) / 2;

//	p + (p - p)
// p + int		「ポインタ同士の引き算」と、「ポインタと整数の足し算」になる
		mid = low + (high-low) / 2;
		
		if( (cond = strcmp(word,mid->word)) < 0 ){
			high = mid;
		}else if( cond > 0 ){
			low = mid + 1;
		}else{
			return mid;
		}
	}
	
	return NULL;
}

