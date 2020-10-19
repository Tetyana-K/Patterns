#pragma once
// 12 numerator/ 30  denominator
// 3 / 5       3 / 0(1)      -3/10 
//copy
// operator = 
// 1. Error: add new Operation   $$  ===   
// 2. Impossible to overload : sizeof(),  typeid(),  ::     .    ?:  
// 3. Two Ways
//		a) global overload (friend) 
//      b) nonstatic method  of class  this(left argument) op  right
//	4. 1 or 2 argument of my class

class Frac
{
public:
	void setNum(int num);
	void setDenom(int denom);
	explicit Frac(int num = 0, int denom = 1); // 3 in one
	void print() const;
	Frac add(const Frac  & other) const; //   this + other
	static Frac sub(const Frac & left, const Frac & right);//  NO has this

	Frac operator + (const Frac & right) const; // *this(left) + right          fr1(this) + fr2(right)
	Frac operator - (const Frac & right) const; // this(left)  right  

	bool operator ==(const Frac & right) const; // this = left
	bool operator !=(const Frac & right) const; // this = left
	Frac& operator ++ (); // this  unary, PREFIX
	Frac operator ++ (int fictive); // this  unary, POSTFIX has fictive
	Frac& operator +=(const Frac & right) ; // this!!!

private:
	int num = 0, // чисельник
		denom = 1; //знаменник

};

