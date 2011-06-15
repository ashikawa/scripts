#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "getch.h"

#define MAXWORD 100

struct tnode{
	char	*word;
	int	count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);

struct tnode *talloc(void);

/**
 * 6.5 自己参照構造体+再起処理
 */
int main(int argc, char *argv[])
{
	struct tnode *root = NULL;
	char word[MAXWORD];
	
	while( getword(word, MAXWORD) != EOF){
		if( isalpha(word[0]) ){
			root = addtree(root, word);
		}
	}
	
	treeprint(root);
	
	return 0;
}

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	
	if( p == NULL ){
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
		
	}else if( (cond = strcmp(w,p->word)) == 0 ){
		p->count++;
	}else if( cond < 0){
		p->left = addtree(p->left ,w);
	}else{
		p->right = addtree(p->right, w);
	}
	
	return p;
}

void treeprint(struct tnode *p)
{
	if( p != NULL ){
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint( p->right );
	}
}

struct tnode *talloc()
{
	return (struct tnode *)malloc(sizeof(struct tnode));
}

