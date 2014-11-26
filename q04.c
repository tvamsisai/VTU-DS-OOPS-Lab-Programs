/*
/*	
/*	Design, develop, and execute a program in C to simulate the 
/*	working of a queue of integers using an array. Provide the following 
/*	operations: 
/*	a. Insert b. Delete c. Display 
/*	
*/

	
#include <stdio.h>
#define MAX 100

void main() {
	int queue[MAX], front = -1, rear = -1;

	printf(" \n Enter \n");
	printf(" i to Insert\n");
	printf(" d to Delete\n");
	printf(" s to Show\n");
	do {
		int item;
		char choice;
		printf(">> ");
		scanf("%c", &choice);
		switch(choice) {
			case 'i':
				printf(" Enter value to insert: ");
				scanf("%d", &item);
				if(rear != MAX - 1)
					queue[++rear] = item;
				break;
			case 'd':
				if(front != rear)
					printf(" Deleted: %d\n", queue[++front]);
				break;
			case 's':
				for(item = front + 1; item <= rear; item++)
					printf(" %d", queue[item]);
				printf("\n");
				break;
			default:
				return;
		}
		scanf("%c", &choice);
	} while(1);
}
