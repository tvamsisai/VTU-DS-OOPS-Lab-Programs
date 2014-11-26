/*	
/*	
/*	Design, develop, and execute a program in C++ to create a class 
/*	called BIN_TREE that represents a Binary Tree, with member 
/*	functions to perform inorder, preorder and postorder traversals. 
/*	Create a BIN_TREE object and demonstrate the traversals. 
/*	
*/


#include <iostream>
using namespace std;

class Node {
	public:
	int val;
	Node *right, *left;
	Node() {
		right = NULL;
		left = NULL;
	}
};

class BTree {
	Node *root;
	
	public:
	BTree() {
		root = NULL;
	}
	void inorder() {
		this->inorder(root);
	}
	void inorder(Node *n) {
		if(n != NULL) {
			this->inorder(n->left);
			cout << " " << n->val;
			this->inorder(n->right);
		}
	}

	void preorder() {
		this->preorder(root);
	}
	void preorder(Node *n) {
		if(n != NULL) {
			cout << " " << n->val;
			this->preorder(n->left);
			this->preorder(n->right);
		}
	}

	void postorder() {
		this->postorder(root);
	}
	void postorder(Node *n) {
		if(n != NULL) {
			this->preorder(n->left);
			this->preorder(n->right);
			cout << " " << n->val;
		}
	}

	void insert(int key) {
		Node *n = new Node();
		n->val = key;

		Node *r = root, *prev = NULL;
		if(r == NULL)
			root = n;
		else {
			while(r != NULL) {
				prev = r;
				if(n->val > r->val)
					r = r->right;
				else if(n->val <= r->val)
					r = r->left;
			}
			if(n->val > prev->val)
				prev->right = n;
			else
				prev->left = n;
		}
	}
};

int main() {
	BTree b;
	int item;
	
	cout << "\n Enter";
	cout << "\n i to Insert";
	cout << "\n p for Preorder";
	cout << "\n n for Inorder";
	cout << "\n o for Postorder";
	
	do {	
		char choice;
		cout << endl << " >> ";
		cin >> choice;
		switch(choice) {
			case 'i':
				cout << " Enter node to insert: ";
				cin >> item;
				b.insert(item);
				break;
			case 'n':
				cout << endl << " Inorder: ";
				b.inorder();
				break;
			case 'p':
				cout << endl << " Preorder: ";
				b.preorder();
				break;
			case 'o':
				cout << endl << " Postorder: ";
				b.postorder();
				break;
			default:
				cout << endl << endl;
				return 0;
		}
	} while(1);
}
