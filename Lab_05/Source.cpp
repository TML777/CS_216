//Tigran Manukyan
//Lab 05
#include <iostream>
#include <string>
using namespace std;

void carExample();

class Car
{
private:
	string* model;
	int* nbrOfDoors;
	double* mpg;
	static int nbrOfCars;

public:
	Car(string mod = "Escape", int nbr = 4, double mp = 32)
	{
		cout << "Normal constructor." << endl;
		model = new string;
		nbrOfDoors = new int;
		mpg = new double;
		*model = mod;
		*nbrOfDoors = nbr;
		*mpg = mp;
		nbrOfCars++;
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
		nbrOfCars++;
	}
	~Car()
	{
		cout << "Deleting pointers for " << *model << endl;
		delete model;
		delete nbrOfDoors;
		delete mpg;
		nbrOfCars--;
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
	static void displayNbrOfCars()
	{
		cout << "Number of cars: " << nbrOfCars << endl;
	}
	friend void displayInformation(const Car *obj)
	{
		cout << *obj->model << " has " << *obj->nbrOfDoors << " doors and gets " <<
			*obj->mpg << " miles per gallon." << endl;
	}
};

int Car::nbrOfCars = 0;


int main()
{
	carExample();
	cout << "End of main function." << endl;
	Car::displayNbrOfCars();
	system("pause");
	return 0;
}

void carExample()
{
	string model;
	int nbrOfDoors;
	double mpg;
	Car::displayNbrOfCars();
	Car car1;
	Car::displayNbrOfCars(); 
	Car car2("Escort", 5, 36);
	Car::displayNbrOfCars(); 
	Car car3 = car1;
	Car::displayNbrOfCars();
	Car *pCar = &car1;

	cout << endl << "car 1 with defualts: " << endl;
	displayInformation(&car1);

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
	displayInformation(&car1);

	cout << endl << "car 2 (using pointer): " << endl;
	pCar = &car2;
	displayInformation(pCar);

	cout << endl << "car 3 (using pointer): " << endl;
	pCar = &car3;
	displayInformation(pCar);

	cout << endl << "End of carExample function" << endl;
}

//Output
/*
Number of cars: 0
Normal constructor.
Number of cars: 1
Normal constructor.
Number of cars: 2
Copy constructor.
Number of cars: 3

car 1 with defualts:
Escape has 4 doors and gets 32 miles per gallon.

Enter new car1 info
Model: Mustang
Number of doors: 2
MPG: 28

car 1 with with new details (using pointer):
Mustang has 2 doors and gets 28 miles per gallon.

car 2 (using pointer):
Escort has 5 doors and gets 36 miles per gallon.

car 3 (using pointer):
Escape has 4 doors and gets 32 miles per gallon.

End of carExample function
Deleting pointers for Escape
Deleting pointers for Escort
Deleting pointers for Mustang
End of main function.
Number of cars: 0
Press any key to continue . . .
*/