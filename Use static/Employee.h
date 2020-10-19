#pragma once

class Employee
{
public: 
	enum Position {NONE , DEVELOPER, TESTER, ECONOMIST , MANAGER };
	
	void setName(const char * name); // метод екземпл€ра,   this= адреса обЇкту
	const char * getName() const;
	unsigned getId() const;
	void print() const;
	
	Employee(const char * name = "Noname", size_t yearBirth = 0); // 3 in 1   with 1 param + default  
	static size_t getCountEmployees()  // Ќ≈ приходить this, бачить тыльки  стат пол€ та конст 
	{
		return countEmployees;
	}
	static int cmpSalary(const Employee & emp1, const Employee & emp2);
	void setPosition(Position position);
	Position getPosition() const;
	const char * getNamePosition() const;
private:
	static const  size_t MaxLimitSalary = 120000;
	static size_t countEmployees; // !!!!!
	unsigned id = 0; // пол€ екземпл€ру
	char * name = nullptr;
	Position  position = Position::NONE;
	unsigned salary = 0;
	
	const size_t yearBirth = 0 ;
};

inline const char * Employee::getName() const
{
	return name;
}

inline unsigned Employee::getId() const
{
	return id;
}
inline Employee::Position Employee::getPosition() const
{
	return position;
}


