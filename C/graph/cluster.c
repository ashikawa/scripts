#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILER 1

#define MAX_WIRE 5
#define NODE_NUM 8

typedef struct node{
	int name;
	int wire_pointer;
	struct node *wires[MAX_WIRE];
} graphNode;


void makeWire(graphNode *node1, graphNode *node2){
//	printf("wired : %d - %d\n", node1->name, node2->name);
	
	// todo 重複をスキップする処理とか
	
	node1->wires[ node1->wire_pointer++ ] = node2;
	node2->wires[ node2->wire_pointer++ ] = node1;
}

int main(int argc, char *argv[])
{
	int i;
	graphNode nodes[NODE_NUM];
	
	// init nodes
	for( i=0; i < NODE_NUM; i++){
		nodes[i].name	= i+1;
		nodes[i].wire_pointer	= 0;
	}
	
	// make wires
	makeWire( &nodes[0], &nodes[1] );
	makeWire( &nodes[0], &nodes[2] );
	makeWire( &nodes[0], &nodes[3] );
	makeWire( &nodes[0], &nodes[4] );
	
	makeWire( &nodes[1], &nodes[4] );
	makeWire( &nodes[1], &nodes[6] );
	makeWire( &nodes[1], &nodes[7] );
	
	makeWire( &nodes[2], &nodes[4] );
	
	makeWire( &nodes[4], &nodes[7] );
	
	makeWire( &nodes[5], &nodes[7] );
	
	
	int target = 0;
	for( i=0; i < nodes[target].wire_pointer; i++ ){
		printf("node : %d\n", nodes[target].wires[i]->name);
	}
	printf("wires : %d\n", nodes[target].wire_pointer);
	
	return EXIT_SUCCESS;
}
