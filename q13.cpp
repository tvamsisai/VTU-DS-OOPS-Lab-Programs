/*	
/*	
/*	Design, develop, and execute a program in C++ to create a class 
/*	called OCTAL, which has the characteristics of an octal number. 15
/*	Implement the following operations by writing an appropriate 
/*	constructor and an overloaded operator +. 
/*	i. OCTAL h = x ; where x is an integer 
/*	ii. int y = h + k ; where h is an OCTAL object and k is an 
/*	integer. 
/*	Display the OCTAL result by overloading the operator <<. Also 
/*	display the values of h and y. 
/*	
*/


#include <iostream>
using namespace std;

class Octal {
	int val;

	public:
	Octal(int n) {
		val = 0;
		int p = 1;
		while(n > 0) {
			val = val + (n % 8) * p;
			p *= 10;
			n /= 8;
		}
	}

	int toInt() {
		int n = val, res = 0, p = 1;
		while(n > 0) {
			res += n % 10 * p;
			p *= 8;
			n /= 10;
		}
		return res;
	}

	friend int operator + (Octal o, int n) {
		return o.toInt() + n;
	}

	friend void operator << (ostream&, Octal o) {
		cout << o.val;
	} 
};

int main() {
	int n;
	
	cout << " Enter an integer: ";
	cin >> n;
	Octal o(n);
	cout << " Value is: " << o;

	cout << endl << endl << " Enter another integer: ";
	cin >> n;
	cout << " Sum: " << (o + n);
	cout << endl;
	return 0;
}
