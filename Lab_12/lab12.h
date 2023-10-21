//Tigran Manukyan
//Lab 12

#ifndef LAB12_H
#define LAB12_h
#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
	string name;
	int age;
public:
	string getName() const
	{
		return name;
	}
	int getAge() const
	{
		return age;
	}

	void setName(string name)
	{
		this->name = name;
	}
	void setAge(int age)
	{
		this->age = age;
	}

	Animal(string name, int age)
	{
		cout << "Constructor: Animal" << endl;
		this->name = name;
		this->age = age;
	}

};

class Speak
{
protected:
	string sound;
public:
	virtual string getSound() = 0;
};

#endif