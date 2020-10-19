#include <iostream>
using namespace std;
#include "Number.h"
int main()
{
	Number n(5);
	cout << n.getNumber() << endl; //  

	Number m(7);
	Number res = m.plus(n);

	res = m.plus('a');
	cout << res.getNumber() << endl;


	
}