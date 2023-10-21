//Tigran Manukyan
//Lab 08
#include <iostream>
#include <string>	
using namespace std;

class Vehicle
{
private:
	int MPG;
public:
	int getMPG() const
	{
		return MPG;
	}
	void setMPG(int MPG)
	{
		this->MPG = MPG;
	}
	Vehicle(int MPG)
	{
		this->MPG = MPG;
		cout << "Constructor: Vehicle" << endl;
	}
};

class Horn
{
private:
	string sound;
public:
	string getSound() const
	{
		return sound;
	}
	void setSound(string sound)
	{
		this->sound = sound;
	}
};

class Car : public Vehicle, public Horn
{
protected:
	string model;
public:
	void display()
	{
		cout << model << " is not a truck! It gets " << getMPG() << " mpg, and says " << getSound() << endl;
	}
	Car(string model, int MPG, string hornSound) : Vehicle(MPG)
	{
		this->model = model;
		setSound(hornSound);
		cout << "Constructor: Car" << endl;
	}
};

class SUV : public Car
{
public:
	void display()
	{
		cout << model << " is an SUV and gets " << getMPG() << " mpg, and says " << getSound() << endl;
	}
	SUV(string model, int MPG, string hornSound) : Car(model, MPG, hornSound)
	{
		cout << "Constructor: SUV" << endl;
	}
};

class Compact : public Car
{
public:
	Compact(string model, int MPG, string hornSound) : Car(model, MPG, hornSound)
	{
		cout << "Constructor: Compact" << endl;
	}
};

int main()
{
	SUV vehicle1("Jeep", 28, "Honk honk.");
	cout << endl;
	SUV vehicle2("Humvee", 14, "Ahooga!");
	cout << endl;
	Compact vehicle3("Civic", 36, "Beep beep.");
	cout << endl;
	Compact vehicle4("Road Runner", 34, "Meep meep!");
	cout << endl;

	vehicle1.display();
	vehicle2.display();
	vehicle3.display();
	vehicle4.display();

	return 0;
}

//Output
/*
Constructor: Vehicle
Constructor: Car
Constructor: SUV

Constructor: Vehicle
Constructor: Car
Constructor: SUV

Constructor: Vehicle
Constructor: Car
Constructor: Compact

Constructor: Vehicle
Constructor: Car
Constructor: Compact

Jeep is an SUV and gets 28 mpg, and says Honk honk.
Humvee is an SUV and gets 14 mpg, and says Ahooga!
Civic is not a truck! It gets 36 mpg, and says Beep beep.
Road Runner is not a truck! It gets 34 mpg, and says Meep meep!
*/