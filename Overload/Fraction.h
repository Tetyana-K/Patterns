#pragma once
// чисельник(num)    знаменник(!=0) denom    
class Fraction
{
public:
	void setDenom(int denom);
	void setNum(int num);
	explicit Fraction(int  num = 0, int denom = 1);
	void print() const;
	Fraction add(const Fraction & right) const; // this(left)   right      
	static Fraction sub(const Fraction &  left, const Fraction & right); // NO  this
	
	Fraction operator +( const Fraction & right) const; // this = left   
	Fraction operator -(const Fraction & right) const;

	bool operator == (const Fraction & right) const;// this = left
	bool operator != (const Fraction & right) const;
	Fraction & operator ++(); // this
	Fraction operator ++(int fictiveParam);  //int fictiveParam for POSTFIX form
	Fraction& operator  += (const Fraction&  right );// this                   (fr1+=fr2).print()
	explicit operator int() // this     10/3 --> int(3)
	{
		return _num / _denom;
	}
	 operator double()
	{
		return (double)_num / _denom;
	}
	int operator [](int index) const; // 0 1  
	int operator [] (const char* index)const;

private:
	int _num = 0, _denom = 1;


};

