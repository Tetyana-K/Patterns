#include <iostream>
#include <iomanip>

using namespace std;
#include "Frac.h"
// Overload 
int main()
{
	Frac fr1(-1, -2), fr2(1, 3), fr3(30, 60);
	//Frac// sum = fr1 + fr;
	
	fr1.print();
	fr2.print();
	cout << "fr1.add(fr2) : ";
	fr1.add(fr2).print(); // 5/6 


	cout << "fr1.sub(fr1, fr2) : ";
	Frac :: sub(fr1, fr2).print(); // 1/6 

	cout << "fr1 + fr2  = ";
	(fr1 + fr2).print(); // this
	cout << "fr1 - fr2  = ";
	(fr1 - fr2).print(); // this = left
	//cin >> boolalpha;
	//cout << "|" << left << setw(10) << 12.3 << "|" <<  endl;// . . . . . . 12.3
	cout << "\nfr1 == fr3 : "  <<boolalpha << (fr1 == fr3) << endl; // true
	//cout << "fr1 != fr3 : " << boolalpha << (fr1 != fr2) << endl; // false

	cout << "++fr1 : ";
	(++fr1).print();

	cout << "fr1++ : ";
	(fr1++).print(); // old frac 3/2
	fr1.print(); // 5/2

	
}
// (a / b) + (c / d) =   (a * d + b * c)  / (b * d)
// (a / b) - (c / d) =   (a * d - b * c)  / (b * d)
// (a / b) * (c / d) =   (a *  c)  / (b * d)
//  (a / b) / (c / d) =   (a *  d)  / (b * c)
// 1/2   +  1/2 =    2/2 