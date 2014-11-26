/*
/*	
/*	Design, develop, and execute a program in C to read a sparse matrix 
/*	of integer values and to search the sparse matrix for an element 
/*	specified by the user. Print the result of the search appropriately. 
/*	Use the triple <row, column, value> to represent an element in the 
/*	sparse matrix. 
/*	
*/


#include <stdio.h>
#define MAX 100

typedef struct SparseRow {
	int row, col, val;
} SparseRow;

void main() {
	SparseRow sparse[MAX];
	int i, j;
	printf(" Enter the <row col>: ");
	scanf(" %d %d", &sparse[0].row, &sparse[0].col);
	sparse[0].val = 0;
	
	printf(" Enter the matrix: \n");
	for(i = 0; i < sparse[0].row; i++) {
		for(j = 0; j < sparse[0].col; j++) {
			int item;
			scanf("%d", &item);
			if(item != 0) {
				sparse[++sparse[0].val].row = i;
				sparse[sparse[0].val].col = j;
				sparse[sparse[0].val].val = item;
			}
		}
	}
	
	printf("\n The matrix is: \n row\tcol\tval\n");
	for(i = 0; i <= sparse[0].val; i++) {
		printf(" %d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].val);
	}
	
	int key;
	printf("\n Enter the key to search for: ");
	scanf(" %d", &key);
	
	for(i = 1; i <= sparse[0].val; i++) {
		if(sparse[i].val == key)
			printf(" %d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].val);
	}
}
