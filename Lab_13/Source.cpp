//Tigran Manukyan
//Lab 13
#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    int MPG;
public:
    virtual int getPrice() = 0;
    int getMPG() const
    {
        return MPG;
    }
    void setMPG(int MPG)
    {
        this->MPG = MPG;
    }
    bool operator > (const Vehicle& temp)
    {
        return (this->getMPG() > temp.getMPG());
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
private:
    int price;
protected:
    string model;
public:
    int getPrice()
    {
        return price;
    }
    void setPrice(int price)
    {
        this->price = price;
    }
    void display()
    {
        cout << model << " is not a truck that costs " << price << ". It gets " << getMPG() << " mpg, and says " << getSound() << endl;
    }
    Car(string model, int MPG, string hornSound, int price) : Vehicle(MPG)
    {
        if (price <= 0)
            throw("Car cannot be free!");
        this->model = model;
        setSound(hornSound);
        this->price = price;
        cout << "Constructor: Car" << endl;
    }
};

class SUV : public Car
{
public:
    void display()
    {
        cout << model << " is an SUV that costs " << getPrice() << ". It gets " << getMPG() << " mpg, and says " << getSound() << endl;
    }
    SUV(string model, int MPG, string hornSound, int price) : Car(model, MPG, hornSound, price)
    {
        cout << "Constructor: SUV" << endl;
    }
};

class Compact : public Car
{
public:
    Compact(string model, int MPG, string hornSound, int price) : Car(model, MPG, hornSound, price)
    {
        cout << "Constructor: Compact" << endl;
    }
};

int main()
{
    try
    {
        SUV vehicle1("Jeep", 28, "Honk honk.", 35000);
        cout << endl;
        SUV vehicle2("Humvee", 14, "Ahooga!", 42000);
        cout << endl;
        Compact vehicle3("Civic", 36, "Beep beep.", 22000);
        cout << endl;
        Compact vehicle4("Road Runner", 34, "Meep meep!", 21500);
        cout << endl;

        vehicle1.display();
        vehicle2.display();
        vehicle3.display();
        vehicle4.display();
        
        cout << endl << "Check MPG:" << endl;
        if (vehicle3 > vehicle4)
        {
            cout << "Civic gets better MPG" << endl;
        }
        else
        {
            cout << "Road Runner gets better MPG" << endl;
        }
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }

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

Jeep is an SUV that costs 35000. It gets 28 mpg, and says Honk honk.
Humvee is an SUV that costs 42000. It gets 14 mpg, and says Ahooga!
Civic is not a truck that costs 22000. It gets 36 mpg, and says Beep beep.
Road Runner is not a truck that costs 21500. It gets 34 mpg, and says Meep meep!

Check MPG:
Civic gets better MPG

C:\Users\18182\source\repos\CS216_Lab13\Debug\CS216_Lab13.exe (process 14908) exited with code 0.
Press any key to close this window . . .

*/
