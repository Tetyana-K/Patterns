#include "Number.h"

Number::Number(int number)
{
	this->number = number;
}
Number Number::plus(const Number & other)
{
	return Number(this->number + other.number);//tmp {7 + 5}
}
