#include <iostream>
#include <algorithm>

using  namespace std;
#include "Employee.h"

bool neg(int x)
{
	return x < 0;
}
int main()
{
	cout << "Count of workers : " << Employee::getCountEmployees() << endl;
	Employee emp1("Vasil", 2000); // id = 1
	emp1.setPosition( Employee::Position::MANAGER);
	emp1.setPosition(Employee::Position(1));
	emp1.print();
	
	cout << "\nCount : " << emp1.getCountEmployees() << endl;
	
	Employee emp2("Ann", 1999); // id = 2

	emp2.print();

	cout << "Cmp (emp1, emp1) : " << Employee::cmpSalary(emp1, emp1) << endl;
	cout << "Cmp (emp1, emp2) : " << Employee::cmpSalary(emp1, emp2) << endl;
	cout << "Cmp (emp2, emp1) : " << Employee::cmpSalary(emp2, emp1) << endl;
	
	//Employee c = emp2; // copy ctor
//	c = emp1; 
	// dtor
	// copy ctor
	// = 



}