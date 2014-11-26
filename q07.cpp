/*	
/*	
/*	Design, develop, and execute a program in C++ to create a class 
/*	called STACK using an array of integers and to implement the 
/*	following operations by overloading the operators + and - : 
/*	i. s1=s1 + element; where s1 is an object of the class STACK 
/*	and element is an integer to be pushed on to top of the 
/*	stack. 
/*	ii. s1=s1- ; where s1 is an object of the class STACK and – 
/*	operator pops off the top element. 
/*	Handle the STACK Empty and STACK Full conditions. Also 
/*	display the contents of the stack after each operation, by overloading 
/*	the operator <<. 
/*	
*/


#include <iostream>
using namespace std;

class Stack {
	int ele[100], top;
	
	public:
	Stack() {
		top = -1;
	}
	
	friend ostream &operator << (ostream &out, Stack s) {
		for(int i = 0; i <= s.top; i++)
			out << " " << s.ele[i];
		out << endl;
		return out;
	}
	
	void operator + (int item) {
		if(top != 99)
			ele[++top] = item;
	}
	
	int operator - () {
		if(top != -1)
			return ele[top--];
		return -999;
	}
};

int main() {
	Stack s;
	cout << " \n Enter \n";
	cout << " i to Insert\n";
	cout << " d to Delete\n";
	cout << " s to Show\n";
	do {
		int item;
		char choice;
		cout << ">> ";
		cin >> choice;
		switch(choice) {
			case 'i':
				cout << " Enter value to insert: ";
				cin >> item;
				s + item;
				break;
			case 'd':
				cout << " Deleted: " << -s << endl;
				break;
			case 's':
				cout << s;
				break;
			default:
				return 0;
		}
	} while(1);
}
