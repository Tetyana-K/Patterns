#include <iostream>
using namespace std;
#include "Employee.h"
///////////////////////
size_t Employee::countEmployees;// = 0; обовязкова ініціалізція статичного поля за межами класу
///////////////////

void Employee::setName(const char * name)
{
	if (name == nullptr || strlen(name) == 0)//   emp.setName("Oleg")   40 bytes    
		return;
	if (this->name != nullptr)
	{
		delete[] this->name;
	}
	size_t size = strlen(name) + 1; // Ivan\0
	this->name = new char[size];
	strcpy_s(this->name, size, name);
	
}

 void Employee::print() const
{
	 cout << "ID :\t" << id << "\tName :\t" << getName() << "\t" << getNamePosition() << "\t" << yearBirth << endl;
}

 Employee::Employee(const char * name, size_t yearBirth) : yearBirth(yearBirth)
 {
	
	 setName(name);
	 id = ++countEmployees; // 
 }

 int Employee::cmpSalary(const Employee & emp1, const Employee & emp2)
 {
	 return  (int)emp1.getId() - (int) emp2.getId(); // size_t    -    ??????
 }

 void Employee::setPosition(Position position)
 {
	 if (position >= Position::NONE && position <= Position::MANAGER)
	 {
		 this->position = position;
	 }
	 
 }
 const char * Employee::getNamePosition() const
 {
	 const char * namesPos[] = { "NONE", "DEVELOPER", "TESTER", "ECONOMIST", "MANAGER" };
	 return namesPos[position]; // 0		1			2			3         4
	/* switch (position)
	 {
	 case Employee::NONE:
		 return "None";
	 case Employee::DEVELOPER:
		 return "Developer";
	 case Employee::TESTER:
		 return "Tester";
	 case Employee::ECONOMIST:
		 return "Economist";
	 case Employee::MANAGER:
		 return "Manager";
	 default:
		 return "None";
	 }*/
 }


