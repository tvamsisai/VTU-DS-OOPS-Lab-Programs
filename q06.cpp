/*	
/*	
/*	Design, develop, and execute a program in C++ to create a class 
/*	called STRING and implement the following operations. Display 
/*	the results after every operation by overloading the operator <<. 
/*	i. STRING s1 = “VTU” 
/*	ii. STRING s2 = “BELGAUM” 
/*	iii. STIRNG s3 = s1 + s2; (Use copy constructor) 
/*	
*/


#include <string.h>
#include <iostream>
using namespace std;

class String {
	public:
	char str[100];
	String() {}
	String(const char c[]) {
		strcpy(str, c);
	}

	friend ostream &operator << (ostream &out, String s) {
		return out << s.str;
	}
	
	String operator + (String s) {
		String out;
		strcpy(out.str, str);
		strcat(out.str, s.str);
		return out;
	}
};

int main() {
	cout << endl;
	String s1 = "VTU";
	String s2 = "BELGAUM";
	cout << s1 << endl << s2 << endl;
	String s3 = s1 + s2;
	cout << s3 << endl << endl;
}
