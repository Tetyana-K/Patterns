#pragma once
#include <iostream>
using namespace std;
class Room
{
	size_t width;
	size_t length;
	char * name = nullptr;
public:
	Room(size_t w = 5, size_t l = 5): Room("Noname", w, l)// :width(w), length{l}
	{
	}
	Room(const char * name, size_t width, size_t lengtht) :width(width), length(lengtht)
	{
		setName(name);

	}
	void print()const
	{
		cout << "Width : " << width << "\tHeight : " << length << endl;
	}
	void setName(const  char * name)
	{
		if (name == nullptr || strlen(name) == 0 )// 
			return;
		
		if (this->name != nullptr) //   "child\0"
		{
			delete[] this->name; // !!!!!
		}
		size_t size = strlen(name) + 1; //
		this->name = new char[size];
		strcpy_s(this->name, size, name);
		
	}
	~Room()
	{
		if (name != nullptr)
		{
			delete[]name;
			name = nullptr;
		}
	}
	// copy ctor!
	// operator = 
};

class House
{
	Room room;
	Room kitchen;
public:
	House() = default;
	House(size_t wRoom, size_t lRoom, size_t wKitchen, size_t lKitchen)
		: room(wRoom, lRoom), kitchen(wKitchen, lKitchen) // use ctor Room with  2 params
	{
		//room.length = wRoom;
	}
	House(const Room &  room, const Room & kitchen)
		: room(room), kitchen { kitchen }
	{}
	
	void print() const
	{
		cout << "__House____\n";
		cout << "_____Room___\n";
		room.print();
		cout << "_____Kitchen___\n";

		kitchen.print();
		
		
		
	}
};

