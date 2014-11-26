/*	
/*	
/*	Design, develop, and execute a program in C to implement a doubly 
/*	linked list where each node consists of integers. The program should 
/*	support the following operations: 
/*	i. Create a doubly linked list by adding each node at the front. 
/*	ii. Insert a new node to the left of the node whose key value is 
/*	read as an input. 
/*	iii. Delete the node of a given data if it is found, otherwise 
/*	display appropriate message. 
/*	iv. Display the contents of the list. 
/*	(Note: Only either (a,b and d) or (a, c and d) may be asked in the 
/*	examination) 
/*	
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *prev, *next;
} node;

node *insert(node *start, int val) {
	node *n = malloc(sizeof(node));
	n->val = val;
	n->prev = NULL;
	n->next = NULL;
	
	if(start == NULL)
		return n;
		
	n->next = start;
	start->prev = n;
	return n;
}

node *insertBefore(node *start, int val, int before) {
	node *realStart = start;
	while(start != NULL) {
		if(start->val == before) {
			node *n = malloc(sizeof(node));
			n->val = val;
			n->prev = NULL;
			n->next = start;
			if(start->prev != NULL) {
				start->prev->next = n;
				n->prev = start->prev;
				start->prev = n;
				return realStart;
			}
			else
				return n;
		}
		start = start->next;
	}
	return realStart;
}

node *delete(node *start, int val) {
	node *realStart = start, *toDelete = NULL;
	while(start != NULL) {
		if(start->val == val)
			toDelete = start;
		start = start->next;
	}
	if(toDelete == NULL) {
		printf(" Not Found");
		return realStart;
	}
	else {
		if(toDelete->prev == NULL)
			realStart = toDelete->next;
		else
			toDelete->prev->next = toDelete->next;
			
		if(toDelete->next == NULL)
			toDelete->prev->next = NULL;
		else
			toDelete->next->prev = toDelete->prev;
		printf(" Deleted: %d\n", toDelete->val);
		free(toDelete);
	}
	return realStart;
}

void display(node *start) {
	while(start != NULL) {
		printf(" %d", start->val);
		start = start->next;
	}
}

node *freeAll(node *start) {
	while(start != NULL) {
		node *temp = start->next;
		free(start);
		start = temp;
	}
	return start;
}

void main() {
	node *start = NULL;
	int item, before;
	char choice;
	printf("\n Enter");
	printf("\n i to Insert");
	printf("\n b to Insert Before");
	printf("\n d to Delete");
	printf("\n s to Display");
	do {
		printf("\n >> ");
		scanf("%c", &choice);
		switch(choice) {
			case 'i':
				printf(" Enter element to insert: ");
				scanf(" %d", &item);
				start = insert(start, item);
				break;
			case 'b':
				printf(" Enter element to insert: ");
				scanf(" %d", &item);
				printf(" Enter element to insert before: ");
				scanf(" %d", &before);
				start = insertBefore(start, item, before);
				break;
			case 'd':
				printf(" Enter element to delete: ");
				scanf(" %d", &item);
				start = delete(start, item);
				break;
			case 's':
				display(start);
				printf("\n");
				break;
			default:
				start = freeAll(start);
				return;
		}
		scanf("%c", &choice);
	} while(1);
}
