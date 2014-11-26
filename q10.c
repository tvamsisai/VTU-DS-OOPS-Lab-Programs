/*	
/*	
/*	Design, develop, and execute a program in C to create a max heap 
/*	of integers by accepting one element at a time and by inserting it 
/*	immediately in to the heap. Use the array representation for the 
/*	heap. Display the array at the end of insertion phase. 
/*	
*/


#include <stdio.h>
#define MAX 100

void insertHeap(int heap[], int *curr, int key) {
	heap[++(*curr)] = key;
	if(*curr == 0)
		return;
	
	int parent = (*curr - 1) / 2, child = *curr;
	while(child != 0) {
		if(heap[parent] < heap[child])
			heap[parent] = heap[parent] + heap[child] - (heap[child] = heap[parent]);
		child = parent;
		parent = (child - 1) / 2;
	}
}

void displayHeap(int heap[], int curr) {
	int i = 0;
	for(; i <= curr; i++)
		printf(" %d", heap[i]);
	printf("\n");
}

void main() {
	int heap[MAX], curr = -1, item;
	char choice;
	printf("\n Enter");
	printf("\n i to Insert");
	printf("\n d to Display");
	do {
		printf("\n >> ");
		scanf("%c", &choice);
		switch(choice) {
			case 'i':
				printf(" Enter element to insert: ");
				scanf(" %d", &item);
				insertHeap(heap, &curr, item);
			case 'd':
				printf("\n");
				displayHeap(heap, curr);
				break;
			default:
				return;
		}
		scanf("%c", &choice);
	} while(1);
}
