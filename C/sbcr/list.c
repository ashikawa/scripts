#include <stdio.h>
#include <stdio.h>

#define EXIT_SUCCESS 0

typedef struct tagListNode{
	struct tagListNode *prev;
	struct tagListNode *next;
	int data;
} ListNode;

/**
 *List 3-4
 */
int main(int argc, char *argv[])
{
	int buf, sum;
	
	ListNode *firstnode = NULL
		, *lastnode = NULL
		, *newnode, *thisnode, *removenode;
	
	
	// input node
	do {

		printf("input numbers : ");
		scanf("%d", &buf);

		if(buf){
			newnode = (ListNode*) malloc(sizeof(ListNode));
			newnode->data = buf;
			newnode->next = NULL;

			if(lastnode != NULL){
				lastnode->next = newnode;
				newnode->prev = lastnode;
				lastnode = newnode;
			} else{
				firstnode = lastnode = newnode;
				newnode->prev = NULL;
			}
		}

	} while(buf != 0);
	
	
	
	/* output */
	sum = 0;
	for(thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next){
		printf("%d\t", thisnode->data);
		sum += thisnode->data;
	}
	printf("sum : %d\n", sum);
	
	
	/* free */
	for(thisnode = firstnode; thisnode != NULL; ){
		removenode = thisnode;
		thisnode = thisnode->next;
		free(removenode);
	}

	return EXIT_SUCCESS;
}
