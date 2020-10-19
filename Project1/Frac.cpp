#include <iostream>
using namespace std;
#include "Frac.h"

void Frac::setNum(int num)
{
	this->num = num;
}

void Frac::setDenom(int denom)
{
	if (denom != 0)
	{
		this->denom = denom;
		if (denom < 0)
		{
			this->denom = -denom;
			this->num = -this->num;
		}
	}
}

Frac::Frac(int num, int denom)
{
	setNum(num);
	setDenom(denom); // -5
}

void Frac::print() const
{
	cout << num << " / " << denom << endl;
}

Frac Frac::add(const Frac & other) const
{
	int denomRes;
	int numRes;
	if (this->denom == other.denom)
	{
		denomRes = denom;
		numRes = this->num + other.num;
	}
	else
	{
		denomRes = this->denom * other.denom;
		numRes = this->num * other.denom + denom * other.num;
	}
	
	return Frac(numRes, denomRes);
}

Frac Frac::sub(const Frac & left, const Frac & other)
{
	int denomRes;
	int numRes;
	if (left.denom == other.denom)
	{
		denomRes = left.denom;
		numRes = left.num - other.num;
	}
	else
	{
		denomRes = left.denom * other.denom;
		numRes = left.num * other.denom - left.denom * other.num;
	}

	return Frac(numRes, denomRes);
}

Frac Frac::operator+(const Frac & right) const
{
	return this->add(right);
}

Frac Frac::operator-(const Frac & right) const
{
	return sub(*this, right);
}

bool Frac::operator==(const Frac & right) const
{
	return this->num * right.denom == this->denom * right.num;  // 2/4   <  101/200    2* 200 < 4 * 101
}

bool Frac::operator!=(const Frac & right) const // this
{
	return !(*this == right);
	//return this->num * right.denom != this->denom * right.num;
}

Frac & Frac::operator++()
{
	//this->num += denom; //if simple code
	//add((Frac)1);
	*this = *this + (Frac)1;// 2/3  + 1/1
	return *this;
}

Frac Frac::operator++(int fictive)
{
	Frac old (*this); // ctor copy
	/*old.num = this->num;
	old.denom = this->denom;
	*/
	++*this;


	return old;
}

Frac & Frac::operator+=(const Frac & right)
{
	*this = *this + right;
	return *this;
}
