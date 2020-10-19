#include <iostream>
using  namespace std;
#include "Vector.h"
Vector::Vector(size_t size) : Vector(size, 0) //size = 5     explicit = я¬Ќ≈ 
{
	cout << "Ctor vector(1 param)\n";

}
Vector::Vector(size_t size, int value)
{
	arr = new int[size];
	this->size = size;
	fill(value);
	cout << "Ctor vector(2 param)  for size " << size << " and values " << value << endl;
}

Vector::Vector(const Vector & other)
{
	assign(other);
	cout << "\t\tCopy ctor worked. Size " << size << endl; //
}

void Vector::operator=(const Vector & other) 
{
	if(this !=  &other)  //   Vector * const this
		assign(other);
}

void Vector::assign(const Vector & other) // this <------ other
{
	//this  [][][][][]
	if(arr!=nullptr)
		delete[] arr;
	//this->~Vector();

	size = other.size; // 1
	arr = new int[size];//  [.][.][.][.]
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

void Vector::fill(int value)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}
void Vector::print() const // !!!
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Vector::push_back(int element) //arr 00012ff00[ 10] [ 20 ]   size = 2
{
	int * tmp = new int[++size]; // ++size   tmp 00012000[][][]
	for (size_t i = 0; i < size - 1; i++)
	{
		tmp[i] = arr[i];
	} // tmp : [10][20][.]
	tmp[size - 1] = element; // tmp :  00012000[10][20][element]
	delete[] arr; // 
	arr = tmp;// arr --- 00012000---> [10][20][element]
}
int & Vector::operator[](size_t index)
{
	static int badElement;// global  
	if (arr == nullptr || index >= size)
	{
		cerr << "Null buffer for vector or bad index\n";
		return badElement;
	}
	return arr[index]; // arr -------[1] [22] [33] [444]       
}
Vector::~Vector() // деструктор
{
	cout << "Dtor done for vector size : " << size << endl;
	delete[] arr;
	size = 0;
	arr = nullptr;
}