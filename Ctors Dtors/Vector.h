#pragma once
class Vector // int 
{
	size_t size = 0;
	int  * arr = nullptr;

public:

	Vector() = default;
	Vector(size_t size);
	/*explicit*/ Vector(size_t size, int value);
	Vector(const  Vector & other);//  v2 [1][10]    v1 [1][10]
	void operator = (const Vector & other);// method of class, this  v1 = v2 (this=&v1)    
	void assign(const Vector & other);
	void fill(int value);
	
	void print() const;
	
	size_t getSize() const  // inline method
	{
		return size;
	}
	
	void push_back(int element);
	int & operator [] (size_t index);

	~Vector();
};

