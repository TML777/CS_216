//Tigran Manukyan
//Lab 12

#include "lab12.h"
//#include "lab12.h"
using namespace std;


class Cat : public Animal, public Speak
{
private:
	string breed;
public:
	string getBreed()
	{
		return breed;
	}
	string getSound()
	{
		return sound;
	}

	void setBreed(string breed)
	{
		this->breed = breed;
	}
	void setSound(string sound)
	{
		this->sound = sound;
	}

	void displayInfo()
	{
		cout << getName() << " is a " << getAge() << " year old " << breed << " and says " << sound << endl;
	}

	Cat(string name, int age, string breed, string sound = "Meow") : Animal(name, age)
	{
		cout << "Constructor: Cat" << endl;
		this->breed = breed;
		this->sound = sound;
	}
};

int main()
{
	Cat aCat("Fluffy", 2, "Siamese");
	aCat.displayInfo();

	return 0;
}

//Output
/*
Constructor: Animal
Constructor: Cat
Fluffy is a 2 year old Siamese and says Meow

C:\Users\18182\source\repos\CS216_Midterm2\Debug\CS216_Midterm2.exe (process 7988) exited with code 0.
Press any key to close this window . . .
*/