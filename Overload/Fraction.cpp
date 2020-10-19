#include "Lib.h"
#include "Fraction.h"

void Fraction::setDenom(int denom)
{
	if (denom == 0)
	{
		cerr << "Error denominator\n";
	}
	else
	{
		_denom = denom; // 
		if (_denom < 0) {
			_denom = -_denom;
			_num = -_num;
		}
	}
}

void Fraction::setNum(int num)
{
	this->_num = num;
}

Fraction::Fraction(int num, int denom)
{
	setNum(num);
	setDenom(denom); 
}

void Fraction::print() const
{
	cout << _num << " / " << _denom << endl;
}

Fraction Fraction::add(const Fraction & right) const
{
	int denom, num;
	if (this->_denom == right._denom)
	{
		denom = _denom;
		num = this->_num + right._num;
	}
	else
	{
		denom = _denom * right._denom;
		num = _num * right._denom + _denom * right._num;
	}
	return Fraction(num, denom);
}

Fraction Fraction::sub(const Fraction & left, const Fraction & right) 
{
	int denom, num;
	if (left._denom == right._denom)
	{
		denom = left._denom;
		num = left._num - right._num;
	}
	else
	{
		denom = left._denom * right._denom;
		num = left._num * right._denom - left._denom * right._num;
	}
	return Fraction(num, denom);
}

Fraction Fraction::operator + (const Fraction & right) const
{
	return add(right);// this->add(right)
}

Fraction Fraction::operator-(const Fraction & right) const
{
	return Fraction::sub(*this, right);
}

bool Fraction::operator==(const Fraction & right) const
{ 
	// 2/3     21/30   2 * 30 < 3 * 21
	return this->_num * right._denom ==  this->_denom * right._num;
}

bool Fraction::operator!=(const Fraction & right) const
{
	return !( *this == right  );
}

Fraction & Fraction::operator++()
{
	//this->_num += _denom;
	
	*this = *this + (Fraction)1; 
	//*this = *this + 1; // 

	return *this;
}

Fraction Fraction::operator++(int fictiveParam)
{
	Fraction old(*this); //copy ctor default : shallow copy num [1] denom [2]      old [1][2]
	//this->_num += _denom;
	 // виклик префіксний ++
	++ *this; 
	return old;
}

Fraction & Fraction::operator+=(const Fraction & right)
{ 
	*this = *this + right;
	return *this;
}

int Fraction::operator[](int index) const
{
	if (index < 0 || index >= 2)
	{
		cerr << "Bad index\n"; // cerr ----> file
		
		return INT_MIN;
	}
	if (index == 0)
		return _num;
	return _denom;
}
