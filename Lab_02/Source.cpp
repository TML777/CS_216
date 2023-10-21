//Tigran Manukyan
//Lab 02
#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
	string model;
	int nbrOfDoors;
	double mpg;
public:
	Car(string mod = "Escape", int nbr = 4, double mp = 32)
	{
		model = mod;
		nbrOfDoors = nbr;
		mpg = mp;
	}
	void setModel(string mod)
	{
		model = mod;
	}
	void setNbrOfDoors(int nbr)
	{
		nbrOfDoors = nbr;
	}
	void setMpg(double mp)
	{
		mpg = mp;
	}
	string getModel() const
	{
		return model;
	}
	int getNbrOfDoors() const
	{
		return nbrOfDoors;
	}
	double getMpg() const
	{
		return mpg;
	}
};

int main()
{
	Car carObj;
	cout << carObj.getModel() << " has " << carObj.getNbrOfDoors() << " doors and gets " << carObj.getMpg() << " miles per gallon" << endl << endl;

	Car* carObjPointer = &carObj;
	string newModel;
	int newNbrOfDoors;
	double newMpg;

	cout << "Enter new car info" << endl;
	cout << "Model: ";
	cin >> newModel;
	cout << "Number of doors: ";
	cin >> newNbrOfDoors;
	cout << "MPG: ";
	cin >> newMpg;
	cout << endl;

	carObjPointer->setModel(newModel);
	carObjPointer->setNbrOfDoors(newNbrOfDoors);
	carObjPointer->setMpg(newMpg);

	cout << carObjPointer->getModel() << " has " << carObjPointer->getNbrOfDoors() << " doors and gets " << carObjPointer->getMpg() << " miles per gallon" << endl << endl;

	return 0;
}

//Output
/*
Escape has 4 doors and gets 32 miles per gallon

Enter new car info
Model: Edge
Number of doors: 5
MPG: 28

Edge has 5 doors and gets 28 miles per gallon


C:\Users\18182\source\repos\CS216_Lab02\Debug\CS216_Lab02.exe (process 17064) exited with code 0.
Press any key to close this window . . .
*/