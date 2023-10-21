//Tigran Manukyan
//Lab 03
#include <iostream>
#include <string>
using namespace std;

void carExample();

class Car
{
private:
	string* model;
	int *nbrOfDoors;
	double* mpg;
public:
	Car(string mod = "Escape", int nbr = 4, double mp = 32)
	{
		cout << "Normal constructor." << endl;
		model = new string;
		nbrOfDoors = new int;
		mpg = new double;
		*model = mod;
		nbrOfDoors = nbr;
		*mpg = mp;
	}
	Car(const Car& obj)
	{
		cout << "Copy constructor." << endl;
		model = new string;
		nbrOfDoors = new int;
		mpg = new double;
		*model = *obj.model;
		*nbrOfDoors = *obj.nbrOfDoors;
		*mpg = *obj.mpg;
	}
	~Car()
	{
		cout << "Deleting pointers for " << *model << endl;
		delete model;
		delete nbrOfDoors;
		delete mpg;

	}
	void setModel(string mod)
	{
		*model = mod;
	}
	void setNbrOfDoors(int nbr)
	{
		*nbrOfDoors = nbr;
	}
	void setMpg(double mp)
	{
		*mpg = mp;
	}
	string getModel() const
	{
		return *model;
	}
	int getNbrOfDoors() const
	{
		return *nbrOfDoors;
	}
	double getMpg() const
	{
		return *mpg;
	}
};

int main()
{
	carExample();
	cout << "End of main function." << endl;
	system("pause");
	return 0;
}

void carExample()
{
	string model;
	int nbrOfDoors;
	double mpg;
	Car car1, car2("Escort", 5, 36), car3 = car1, *pCar = &car1;

	cout << endl << "car 1 with defualts: " << endl;
	cout << car1.getModel() << " has " << car1.getNbrOfDoors() << " doors and gets " <<
		car1.getMpg() << " miles per gallon" << endl;

	cout << endl << "Enter new car1 info" << endl;
	cout << "Model: ";
	cin >> model;
	cout << "Number of doors: ";
	cin >> nbrOfDoors;
	cout << "MPG: ";
	cin >> mpg;

	pCar->setModel(model);
	pCar->setNbrOfDoors(nbrOfDoors);
	pCar->setMpg(mpg);

	cout << endl << "car 1 with with new details (using pointer): " << endl;
	cout << car1.getModel() << " has " << car1.getNbrOfDoors() << " doors and gets " <<
		car1.getMpg() << " miles per gallon" << endl;

	cout << endl << "car 2 (using pointer): " << endl;
	pCar = &car2;
	cout << pCar->getModel() << " has " << pCar->getNbrOfDoors() << " doors and gets " <<
		pCar->getMpg() << " miles per gallon" << endl;

	cout << endl << "car 3 (using pointer): " << endl;
	pCar = &car3;
	cout << pCar->getModel() << " has " << pCar->getNbrOfDoors() << " doors and gets " <<
		pCar->getMpg() << " miles per gallon" << endl;

	cout << endl << "End of carExample function" << endl;
}

//Output
/*
Normal constructor.
Normal constructor.
Copy constructor.

car 1 with defualts:
Escape has 4 doors and gets 32 miles per gallon

Enter new car1 info
Model: Mustang
Number of doors: 2
MPG: 25

car 1 with with new details (using pointer):
Mustang has 2 doors and gets 25 miles per gallon

car 2 (using pointer):
Escort has 5 doors and gets 36 miles per gallon

car 3 (using pointer):
Escape has 4 doors and gets 32 miles per gallon

End of carExample function
Deleting pointers for Escape
Deleting pointers for Escort
Deleting pointers for Mustang
End of main function.
Press any key to continue . . .
*/