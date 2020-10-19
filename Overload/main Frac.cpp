#include "Lib.h"
#include "Fraction.h"
// Overload error : sizeof(), typeid(), .    ?:  :: 
// Impossible  : change priority, асоціативність(напрям виконання)
// Impossible : create NEW operation  operator 
// 1. by nonstatic Methods(this)            MyClass operator nameOp(MyClass right) // this = left   right     
// 2. global 

int main()
{
	Fraction fr1(1, 2); // 1 / 2
	fr1.print();
	Fraction fr2(-1, -3); 
	fr2.print();

	Fraction fr3(-5, 0);
	fr3.print();
	
	cout << "fr1.add (fr2): ";
	fr1.add(fr2).print();

	cout << "sub (fr1, fr2): "; // 1 / 6
	Fraction::sub(fr1, fr2).print();
	
	Fraction sum = fr1 + fr2;
	sum.print();
	
	(fr1 - fr2).print();
	
	Fraction fr4(30, 60); // 30/60    1/2
	cout << "fr1 == fr4 (expected true) : " << boolalpha << (fr1 == fr4) << endl;
	cout << "fr1 != fr4 (expected false) : " << boolalpha << (fr1 != fr4) << endl;

	//int value = 100;

	//cout << ++value << endl; // 101
	//cout << value++ << endl; // old = 100   value = 101
	cout << "\n++fr1 : ";
	(++fr1).print();

	cout << "\nfr1++ : ";
	(fr1++).print(); // expected  3/2(old)
	cout << "\nfr1 : ";
	fr1.print(); // 5/2

	cout << "fr2 += Fraction(3, 4): ";
	(fr2 += Fraction(3, 4)).print();

	// convert Fraction ----> other type (int , double, char * )  
	//	       other   -----> Fraction,   ctor with 1 param as convertor !!!!

	cout << "\n(int)fr2: " <<(int)fr2 << endl;
	cout << "\n(double)fr2: " << (double)fr2 << endl;
	cout << fr2 << endl;

	cout << "\nTest operator []:\n";
	for (int i = -1; i < 3; ++i)
	{
		cout << "fr2[" << i << "] = " << fr2[i] << endl;
	}
	cout << fr2["num"] << endl; // 13 = num
	cout << fr2["denom"] << endl; // 12 = denum
	cout << fr2["some"] << endl; // INT_MIN   cerr
}
