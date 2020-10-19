#pragma once
class Number
{
public :
	/*explicit*/ Number(int number = 0);
	int getNumber() const;
	Number  plus(const Number & other); // this    +  other ---> result (Number)

private:
	int number;
};

inline int Number::getNumber() const
{
	return number;
}



