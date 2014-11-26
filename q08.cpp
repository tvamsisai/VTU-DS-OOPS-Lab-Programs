/*	
/*	
/*	Design, develop, and execute a program in C++ to create a class 
/*	called LIST (linked list) with member functions to insert an element 
/*	at the front of the list as well as to delete an element from the front 
/*	of the list. Demonstrate all the functions after creating a list object. 
/*	
*/

#include <iostream>
using namespace std;

class Node {
	public:
	int val;
	Node *next;
	
	Node() {
		next = NULL;
	}
};

class List {
	Node *start;
	
	public:
	List() {
		start = NULL;
	}
	
	void insert(int item) {
		Node *n = new Node();
		n->val = item;
		if(start == NULL)
			start = n;
		else {
			n->next = start;
			start = n;
		}
	}
	
	void insertBefore(int item, int before) {
		Node *n = new Node(), *s = start, *prev = NULL;
		n->val = item;
		while(s != NULL) {
			if(s->val == before) {
				if(s == start)
					start = n;
				n->next = s;
				if(prev != NULL)
					prev->next = n;
				break;
			}
			prev = s;
			s = s->next;
		}
	}
	
	int remove() {
		if(start == NULL)
			return -999;
		int out = start->val;
		Node *temp = start;
		start = temp->next;
		delete temp;
		return out;
	}
	
	void display() {
		Node *s = start;
		while(s != NULL) {
			cout << " " << s->val;
			s = s->next;
		}
		cout << endl;
	}
};

int main() {
	List l;
	cout << " \n Enter \n";
	cout << " i to Insert\n";
	cout << " b to Insert Before\n";
	cout << " d to Delete\n";
	cout << " s to Show\n";
	do {
		int item, before;
		char choice;
		cout << ">> ";
		cin >> choice;
		switch(choice) {
			case 'i':
				cout << " Enter value to insert: ";
				cin >> item;
				l.insert(item);
				break;
			case 'b':
				cout << " Enter value to insert: ";
				cin >> item;
				cout << " Enter to insert before: ";
				cin >> before;
				l.insertBefore(item, before);
				break;
			case 'd':
				cout << " Deleted: " << l.remove() << endl;
				break;
			case 's':
				l.display();
				break;
			default:
				return 0;
		}
	} while(1);
}
