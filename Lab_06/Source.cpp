//Tigran Manukyan
//Lab 06
#include <iostream>
#include <string>
using namespace std;

class Pet
{
private:
	int age;
protected:
	string name;
public:
	int getAge() const
	{
		return age;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	Pet(string name, int age)
	{
		cout << "Pet constructor" << endl;
		this->name = name;
		this->age = age;
	}
};

class Cat : public Pet
{
private:
	string catSays;
public:
	void displayCatInfo() const
	{
		cout << name << " is " << getAge() << " years old and says " << catSays << endl;
	}
	Cat(string name, int age) : Pet(name, age)
	{
		cout << "Cat constructor" << endl;
		catSays = "Meow";
	}
};

class Dog : public Pet
{
private:
	string dogSays;
public:
	void displayCatInfo() const
	{
		cout << name << " is " << getAge() << " years old and says " << dogSays << endl;
	}
	Dog(string name, int age) : Pet(name, age)
	{
		cout << "Dog constructor" << endl;
		dogSays = "Woof!";
	}
};

int main()
{
	Cat cat1("Mittens", 2), cat2("Whiskers", 3);
	Dog dog1("Fido", 6), dog2("Duke", 4);

	cat1.displayCatInfo();
	cat2.displayCatInfo();
	dog1.displayCatInfo();
	dog2.displayCatInfo();

	system("pause");
	return 0;
}

//Output
/*
Pet constructor
Cat constructor
Pet constructor
Cat constructor
Pet constructor
Dog constructor
Pet constructor
Dog constructor
Mittens is 2 years old and says Meow
Whiskers is 3 years old and says Meow
Fido is 6 years old and says Woof!
Duke is 4 years old and says Woof!
Press any key to continue . . .
*/