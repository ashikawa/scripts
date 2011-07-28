/**
 *List 6-4
 */
#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILER 1

typedef struct _tag_tree_node {
	int value;
	struct _tag_tree_node *left;
	struct _tag_tree_node *right;
} tree_node;

tree_node *tree_root = NULL;

tree_node* create_new_node(int num)
{
	tree_node *tree_new;
	
	tree_new = (tree_node*) malloc(sizeof(tree_node));
	
	if(tree_new == NULL){
		exit(EXIT_FAILER);
	}
	tree_new->left	= NULL;
	tree_new->right	= NULL;
	tree_new->value	= num;
	
	return tree_new;
}

void insert_tree(int num, tree_node *node)
{
	if(node == NULL){
		tree_root = create_new_node(num);
		return;
	}
	
	if(node->value > num){
		if(node->left != NULL){
			insert_tree(num, node->left);
		}else{
			node->left = create_new_node(num);
		}
	}else{
		if(node->right != NULL){
			insert_tree(num, node->right);
		}else{
			node->right = create_new_node(num);
		}
	}
	
	return;
}

void print_tree(int depth, tree_node* node)
{
	int i;
	
	if(node == NULL){
		return;
	}
	
	print_tree(depth + 1, node->left);
	
	for( i=0; i < depth; i++ ){
		printf(" ");
	}
	printf("%d\n", node->value);
	print_tree(depth + 1, node->right);
}

void free_tree(tree_node* node)
{
	if(node == NULL){
		return;
	}
	
	free_tree(node->left);
	free_tree(node->right);
	
	free(node);
}

int delete_tree(int val)
{
	tree_node *node, *parent_node;
	tree_node *left_biggest;
	int direction = 0;
	
	node		= tree_root;
	parent_node	= NULL;
	
	while(node != NULL && node->value != val){
		
		if(node->value > val){
			parent_node = node;
			node = node->left;
			direction = -1;
		}else{
			parent_node = node;
			node = node->right;
			direction = 1;
		}
	}
	
	if(node->left == NULL || node->right == NULL){
		if(node->left == NULL ){
			if(direction == -1){
				parent_node->left = node->right;
			}
			if(direction == 1){
				parent_node->right = node->right;
			}
			if(direction == 0){
				tree_root = node->right;
			}
		}else{
			if(direction == -1){
				parent_node->left = node->left;
			}
			if(direction == 1){
				parent_node->right = node->left;
			}
			if(direction == 0){
				tree_root = node->left;
			}
		}
		free(node);
		
	}else{
		
		left_biggest = node->left;
		parent_node = node;
		direction = -1;
		
		while(left_biggest->right != NULL){
			parent_node = left_biggest;
			left_biggest = left_biggest->right;
			direction = 1;
		}
		
		node->value = left_biggest->value;
		if(direction == -1){
			parent_node->left = left_biggest->left;
		}else{
			parent_node->right = left_biggest->left;
		}
		
		free(left_biggest);
	}
	
	return 1;
}

tree_node* find_value(tree_node* node, int val)
{
	if(node->value > val){
		if( node->left == NULL ){
			return NULL;
		}
		return find_value(node->left, val);
	}
	
	if(node->value < val){
		if( node->right == NULL ){
			return NULL;
		}
		return find_value(node->right, val);
	}
	
	return node;
}

int main(int argc, char *argv[])
{
	int i, action, input;
	
	srand( (unsigned int)time( NULL ) );
	
	for( i=0; i<10; i++ ){
		insert_tree(rand() % 99 + 1, tree_root);
	}
	
	for(;;){
		print_tree(0, tree_root);
		
		printf("1: add\t2: search\t3: delete\t: other exit\n");
		scanf("%d", &action);
		
		switch(action){
		case 1:
			printf("input number: ");
			scanf("%d", &input);
			if( input < 10 || input > 100 ){
				continue;
			}
			
			insert_tree(input, tree_root);
			break;
		case 2:
			printf("input number: ");
			scanf("%d", &input);
			if( input < 10 || input > 100 ){
				continue;
			}
			if( find_value(tree_root, input) != NULL ){
				printf("found! \n");
			}else{
				printf("not found! \n");
			}
			break;
		case 3:
			printf("input number: ");
			scanf("%d", &input);
			
			if( delete_tree(input) == 1){
				printf("deleted\n");
			}else{
				printf("not found\n");
			}
			break;
		default:
			free_tree(tree_root);	
			return EXIT_SUCCESS;
		}		
	}
	
}
