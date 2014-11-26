/*  
/*  Using circular representation for a polynomial, design, develop, and 
/*  execute a program in C to accept two polynomials, add them, and 
/*  then print the resulting polynomial. 
/*  
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct term {
	int coeff, deg;
	struct term *next;
} term;

term *polyAttach(term *p, int c, int d) {
	term *n = malloc(sizeof(term));
	n->coeff = c;
	n->deg = d;
	n->next = p->next;
	p->next = n;
	return n;
}

void polyRead(term *p) {
	int c, d;
	p->next = p;
	while(1) {
		printf(" Enter term: ");
		scanf(" %d %d", &c, &d);
		p = polyAttach(p, c, d);
		printf(" Again? ");
		scanf("%d", &d);
		if(!d) break;
	}
}

void polyAdd(term *a, term *b, term *sum) {
	term *ta = a, *tb = b;
	a = a->next; b= b->next; sum->next = sum;
	
	while(a != ta && b != tb) {
		if(a->deg == b->deg) {
			sum = polyAttach(sum, (a->coeff + b->coeff), b->deg);
			a = a->next;
			b = b->next;
		}
		else if(a->deg > b->deg) {
			sum = polyAttach(sum, b->coeff, b->deg);
			b = b->next;
		}
		else if(a->deg < b->deg) {
			sum = polyAttach(sum, a->coeff, a->deg);
			a = a->next;
		}
	}
	while(a != ta) {
		sum = polyAttach(sum, a->coeff, a->deg);
		a = a->next;
	}
	while(b != tb) {
		sum = polyAttach(sum, b->coeff, b->deg);
		b = b->next;
	}
}

void polyDisplay(term *p) {
	term *tp = p; p = p->next;
	while(tp != p) {
		printf(" %d x^ %d", p->coeff, p->deg);
		p = p->next;
		if(tp != p)
			printf(" +");
	}
}

void polyFree(term *p) {
	term *tp = p;
	p = p->next;
	while(p != tp) {
		term *next = p->next;
		free(p);
		p = next;
	}
}

void main() {
	term a, b, sum;
	printf(" Enter 1st polynomial in form <coeff deg>: \n");
	polyRead(&a);
	printf("\n Enter 2nd polynomial in form <coeff deg>: \n");
	polyRead(&b);
	
	polyAdd(&a, &b, &sum);
	
	printf("\n");
	polyDisplay(&a);
	printf("  +  ");
	polyDisplay(&b);
	printf("\n = ");
	polyDisplay(&sum);
	printf("\n\n");
	
	polyFree(&a);
	polyFree(&b);
	polyFree(&sum);
}
