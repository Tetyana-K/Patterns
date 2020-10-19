
#include <iostream>
#include <string>
using namespace std;
//struct 
//1. user defined type
//2. element, field   :  all types
//3.
// 1 OOP     TYPE :  field + function
struct Point
{
	double x, y;
};
class Player
{
//private: 
//protected: 
	string name = "Noname";
	size_t age = 0;
	size_t  hp = 0;
	enum Limits{MAX_AGE = 120, MAX_HP = 500};
public:
	Player()
	{}
	Player(const string &name)// ctor with params   параметризовний  конструтокр
	{
		setName(name);
	}
	Player(const string &name, const size_t & age, const size_t & hp = 100)
	{
		setName(name);
		setAge(age);
		setHp(hp);
	}
	void print() const //  this ed.print()
	{
		// const Player * const this 
		cout << this->name << "\t" << hp << "\t" << age << endl;
	}
	void setName(const string & name)// newName ----> this->name   setter, accessor/ mutator
	{
		// Player * const this 
		if (!name.empty())//name !=""
		{
			this->name = name;
		}
	}
	void setAge(size_t age)
	{
		if (age <= MAX_AGE) 
		{
			this->age = age;
		}
	}
	void setHp(size_t hp)
	{
		this->hp = hp;
	}
	void enter()
	{
		cout << "Enter name : ";
		cin >> this->name;

		cout << "Enter age : ";
		cin >> age;

		cout << "Enter hp : ";
		cin >> hp;
	}

	int comparePlayerHp( const Player & otherPlayer) const
		// first = this   
	{
		int result = -1;
		if (hp == otherPlayer.hp)
		{
			result = 0;
		}
		else if (hp > otherPlayer.hp)
		{
			result = 1;
		}
		return result;
	}
	size_t getAge() const
	{
		
		return age;
	}
	size_t getHp() const
	{
		return hp;
	}
	const string & getName() const // safe!!!
	{
		return name;
	}
};

void doSomething(const Player & player)
{
	player.print();
	cout << "Age : " <<player.getAge() << endl;
}
// struct
// OOP  incapsulation    private (field, method)  public : method for client(user of struct)
int main()
{
	Player bob("Bob", 23, 300);
	bob.print();

	Player julia("Julia", 22);
	julia.print();

	Player jack("Jack"); 
	jack.print();
	//return 0;
	//const Player constPlayer;
	//cout << constPlayer.getAge() << endl;

//	return 0;
	
	Player arsen;// { "Arsen", 100, 18 };// bytes
	arsen.setName("Arsen");
	arsen.setHp(100);
	arsen.setAge(18);
	arsen.setName("");
	arsen.setAge(121);
	

	//cout << arsen.name << "\t" << arsen.hp << "\t" << arsen.age << endl;
	arsen.print();//  0012ff000 = this
	cout << "Age of Arsen " << arsen.getAge() << endl;
	
	Player john;
	john.enter();
	john.print(); // 0012ffaaa = this

	cout << "Result comparison (arsen, john): " << arsen.comparePlayerHp( john) << endl;
	cout << "Result comparison (john, arsen): " << john.comparePlayerHp(arsen) << endl;

	//arsen.age = 200;//  control
	//arsen.hp = 1000; //
	// Incapsualtion
}
// Room : fields   float width   float  length 
// input()
// print ()
// double square() 
// double perimetr()
// main() ....check



