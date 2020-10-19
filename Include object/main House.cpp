#include "Room.h"
int main()
{
	House house(7, 5, 4, 3);
	house.print();
	cout << endl;
	/////////////////////////////////////////
	Room room{ 5,5 };
	Room kitchen{ 4, 4 };
	//House house2(room, kitchen);
	//house2.print();
	return 0;

}