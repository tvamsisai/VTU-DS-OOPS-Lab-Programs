/*
/*	Design, develop, and execute a program in C to convert a given 
/*	valid parenthesized infix arithmetic expression to postfix expression 
/*	and then to print both the expressions. The expression consists of 13
/*	single character operands and the binary operators + (plus), - 
/*	(minus), * (multiply) and / (divide).
/*	
*/


#include <stdio.h>
#include <string.h>

int precedence(char op) {
	switch(op) {
		case '+':
		case '-':	return 1;
		case '*':
		case '/':	return 2;
		case '(':	return 0;
	}
}

void main() {
	int i = 0, j = 0, stack_top = -1;
	char infix[50], postfix[50], stack[50];

	printf("\n\n Enter infix: ");
	fgets(infix, sizeof(infix), stdin);
	infix[strlen(infix)-1] = ')';
	infix[strlen(infix)] = '\0';
	printf(" %s\n\n", infix);

	stack[++stack_top] = '(';
	while(i < strlen(infix)) {
		if(infix[i] >= '0' && infix[i] <= '9')
			postfix[j++] = infix[i];
		else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
			if(precedence(infix[i]) <= precedence(stack[stack_top])) {
				postfix[j++] = stack[stack_top--];
				stack[++stack_top] = infix[i];
			}
			else {
				stack[++stack_top] = infix[i];
			}
		}
		else if(infix[i] == '(')
			stack[++stack_top] = '(';
		else if(infix[i] == ')') {
			while(stack[stack_top] != '(')
				postfix[j++] = stack[stack_top--];
			stack_top--;
		}
		i++;
	}
	while(stack[stack_top] != '(')
		postfix[j++] = stack[stack_top--];
	postfix[j++] = '\0';


	printf("\n\n %s", postfix);
	printf("\n\n\n");
}
