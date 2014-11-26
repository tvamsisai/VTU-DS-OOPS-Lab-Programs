/*	
/*	
/*	Design, develop, and execute a program in C++ to create a class 
/*	called DATE with methods to accept two valid dates in the form 
/*	dd/mm/yy and to implement the following operations by 
/*	overloading the operators + and -. After every operation the results 
/*	are to be displayed by overloading the operator <<. 
/*	i. no_of_days = d1 – d2; where d1 and d2 are DATE objects, 
/*	d1 >=d2 and no_of_days is an integer. 
/*	ii. d2 = d1 + no_of_days; where d1 is a DATE object and
/*	no_of_days is an integer. 
/*	
*/


#include <iostream>
using namespace std;

class Date {
	int d, m, y;
	public:
		void read();
		int isleap();
		int maxday();
		int operator - (Date);
		Date operator + (int);
		friend ostream &operator << (ostream &, Date);
};

void Date::read() {
	cin>>d>>m>>y;
}

int Date::isleap() {
	if(y%4==0)
		return 1;
	else
		return 0;
}

int Date::maxday() {
	int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if((m==2)&&isleap())
		return 29;
	else
		return month[m-1];
}

int Date::operator - (Date da) {
	int count = 0;
	while(!(da.d == d && da.m == m && da.y == y)) {
		count++;
		da.d++;
		if(da.d > da.maxday()) {
			da.d=1;
			da.m++;
			if(da.m>12) {
				da.m=1;
				da.y++;
			}
		}
	}
	return count;
}

Date Date::operator + (int n) {
	Date *temp = new Date;
	temp->d=d+n;
	temp->m=m;
	temp->y=y;
	while(temp->d > temp->maxday()) {
		temp->d = temp->d - temp->maxday();
		temp->m++;
		if(temp->m>12) {
			temp->m = 1;
			temp->y++;
		}
	}
	return *temp;
}

ostream &operator << (ostream &c, Date da) {
	c << da.d << "/" << da.m << "/" << da.y;
}

int main() {
	Date d1, d2;
	int days;
  
	cout << endl << " Enter the 1st date: ";
	d1.read();
	cout << " Enter the 2nd date: ";
	d2.read();
  
	days = d1 - d2;
	cout << " Difference: " << days << endl;
  
	cout << " Enter the number of days to add to " << d1 << ": ";
	cin >> days;
	d1 = d1 + days;
	cout << " Result: " << d1 << endl << endl;
	return 0;
}
