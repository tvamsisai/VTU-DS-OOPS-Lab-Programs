/*	
/*	
/*	Design, develop, and execute a program in C++ based on the 
/*	following requirements: 
/*	 An EMPLOYEE class is to contain the following data members and 
/*	member functions: 
/*	 Data members: Employee_Number (an integer), Employee_Name (a 
/*	string of characters), Basic_Salary (an integer) , All_Allowances 
/*	(an integer), IT (an integer), Net_Salary (an integer). 
/*	 Member functions: to read the data of an employee, to calculate 
/*	Net_Salary and to print the values of all the data members. 
/*	 (All_Allowances = 123% of Basic; Income Tax (IT) = 30% of the 
/*	gross salary (= basic_Salary _ All_Allowance); Net_Salary = 
/*	Basic_Salary + All_Allowances – IT) 
/*	
*/


#include <iostream>
using namespace std;

class Employee {
	int number, basic_salary, all_allowances, it, net_salary;
	char name[20];
	
	public:
	Employee() {
		cout << endl << " Enter the employee number: ";
		cin >> number;
		cout << " Enter the employee name: ";
		cin >> name;
		cout << " Enter the Basic Salary: ";
		cin >> basic_salary;
	}
	
	void calculate() {
		all_allowances = 1.23 * basic_salary;
		int gross_salary = basic_salary + all_allowances;
		it = 0.3 * gross_salary;
		net_salary = basic_salary + all_allowances - it;
	}
	
	void display() {
		cout << endl << " Number: " << number;
		cout << endl << " Name: " << name;
		cout << endl << " Basic Salary: " << basic_salary;
		cout << endl << " All Allowances: " << all_allowances;
		cout << endl << " Income Tax: " << it;
		cout << endl << " Net Salary: " << net_salary << endl;
	}
};

int main() {
	Employee emp;
	emp.calculate();
	emp.display();
	return 0;
}
