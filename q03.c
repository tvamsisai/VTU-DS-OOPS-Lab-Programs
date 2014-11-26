/*	
/*	
/*	Design, develop, and execute a program in C to evaluate a valid 
/*	postfix expression using stack. Assume that the postfix expression is 
/*	read as a single line consisting of non-negative single digit operands 
/*	and binary arithmetic operators. The arithmetic operators are + 
/*	(add), - (subtract), * (multiply) and / (divide).
/*
*/


#include <stdio.h>
#define MS 30

void main() {
	int stack[MS], i = 0, top = -1;
	char postfix[MS];

	printf("\n\n Enter postfix: ");
	do {
		scanf("%c", &postfix[i++]);		
	}while(postfix[i-1] != '\n');
	int len = i;

	stack[++top] = '(';
	for(i = 0; i < len; i++) {
		if(postfix[i] >= '0' && postfix[i] <= '9')
			stack[++top] = postfix[i] - '0';
		else if(postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '+' || postfix[i] == '-') {
			int op2 = stack[top--];
			int op1 = stack[top--];
			switch(postfix[i]) {
				case '*': stack[++top] = op1 * op2; break;
				case '/': stack[++top] = op1 / op2; break;
				case '+': stack[++top] = op1 + op2; break;
				case '-': stack[++top] = op1 - op2; break;
			}
		}	
	}

	printf("\n Value: %d\n\n", stack[top--]);
}
