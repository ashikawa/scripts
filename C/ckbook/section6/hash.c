#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101


unsigned hash(char *);
struct nlist *lookup(char *);

void printhash();
void printnode( struct nlist *np );


static struct nlist *hashtab[HASHSIZE];

struct nlist *install(char *, char *);

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};



/**
 * 6.6 テーブル参照
 * 
 */
int main(int argc, char *argv[])
{
	int i;
	for( i = 0; i < HASHSIZE; i++ ){
		hashtab[i] = NULL;
	}

	install("HOGE","001");
	install("MOGE","002");
	
	printhash();	
	
	return 0;
}

void printhash()
{
	int i;
	for( i = 0; i < HASHSIZE; i++ ){
		
		if( hashtab[i] != NULL ){
			printf("%d\t", i);
			printnode(hashtab[i]);
			printf("\n");
		}
	}
}

void printnode( struct nlist *np )
{
	if(np != NULL){
		printf("%s:%s,", np->name, np->defn);
		printnode(np->next);
	}
}

unsigned hash(char *s)
{
	unsigned hashval;
	
	for(hashval = 0; *s != '\0'; s++){
		hashval = *s + 31 * hashval;
	}
	
	return hashval % HASHSIZE;
}

struct nlist *lookup( char *s )
{
	struct nlist *np;
	
	for( np = hashtab[hash(s)]; np != NULL; np = np->next ){
		if( strcmp(s, np->name) == 0 ){
			return np;
		}
	}
	
	return NULL;
}

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;
	
	if( (np = lookup(name)) == NULL ){
		np = (struct nlist *)malloc(sizeof(*np));
		
		if( np == NULL || (np->name = strdup(name)) == NULL  ){
			return NULL;
		}
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}else{
		free((void *)np->defn);
	}
	
	if( (np->defn = strdup(defn)) == NULL ){
		return NULL;
	}
	
	return np;
}

