#include <iostream>
using  namespace std;
#include "Vector.h"
#define LINE cout <<"________________________\n";

//Vector g(2);

Vector demoCopy(Vector  v) // copy ctor
{
	cout << "DemoCopy works\n";
	v.print();
	
	Vector tmp(2, 2);
	return tmp;
}

int main()
{
	/*g.print();
	LINE
	*/
	Vector v(3, -1);// [-1][-1][][][]
	v.push_back(100);
	v.push_back(200);
	v.print();
	v[0] = 11;
	v[1] = 22;
	v[5] = -99999;
	v.print();
	cout << "Test recycle : " << v[100] << endl;
	LINE
		return 0;
	Vector copy = demoCopy(v);
	copy.print();
	LINE
	//Vector clone =  v ; // ctor copy
	v = copy; // operator assign = copy
	
	return 0;

	cout << "Size : " << v.getSize() << endl;
	LINE
	{
	Vector *pv = new Vector(3, 333);
	pv->print();
	
	delete pv;
	}
	
	LINE
	//Vector test = 7; //без explicit : працює як конструтор перетворення 7(size_t) ---> Vector
	Vector test{ 7 };
	test.print();

	LINE

	Vector test2  {4, 5}; // к-р з 2 параметрами, works in all  ways(explicit or not)
	//Vector test2 = { 4, 5 }; // explicit does not work
	test2.print();
	LINE
	Vector arr[3]{ Vector{1}, Vector{3, 3} }; // 
	//arr[2].print();
	//arr[0].print();
	//for (auto e : arr) // ????
	//{
	//	e.print();
	//	
	//}
	LINE
	//Vector v[3];//3 objects but default
	//Vector  arr_2[2] = { {2,2}, {5, 5} }; // NOT explicit ctor with 2 params
	//arr_2[1].print();
	LINE
}
