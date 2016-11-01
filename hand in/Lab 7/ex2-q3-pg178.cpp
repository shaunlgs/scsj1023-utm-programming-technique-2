// This program contains four classes, LawnMower, Blade, Engine, and Wheel. This is an aggregation.
// Each LawnMower has Blade, Engine, and Wheel.
// A lawnmower is created containing blade, engine, and wheel.
// The information of the lawnmower is printed on screen.
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// This is class Blade. It has blade number string, and blade length.
class Blade
{
    private:
        string bladeNum;
        int bladeLength;
    public:
        Blade();
        Blade(string, int);
        string getBladeNum() const
        {
            return bladeNum;
        }
        int getBladeLength() const
        {
            return bladeLength;
        }
};

// This is class Engine. It has engine number string, and engine manufacturer string.
class Engine
{
    private:
        string engineNum;
        string manufacturer;
    public:
        Engine();
        Engine(string, string);
        string getEngineNum() const
        {
            return engineNum;
        }
        string getManufacturer() const
        {
            return manufacturer;
        }
};

// This is class Wheel. It has wheel number string, and wheel diameter length.
class Wheel
{
    private:
        string wheelNum;
        int wheelDiam;
    public:
        Wheel();
        Wheel(string, int);
        string getWheelNum() const
        {
            return wheelNum;
        }
        int getWheelDiameter() const
        {
            return wheelDiam;
        }
};

// This is class LawnMower.
class LawnMower
{
    private:
        // initialize model number
        string modelNumber = "ABD1234";
        // variables to store Blade, Engine, and Wheel objects
        Blade mowerBlade;
        Engine mowerEngine;
        Wheel mowerWheel;
    public:
        // constructor
        LawnMower(Blade, Engine, Wheel);
        // print information
        void print();
};

Blade::Blade(string num, int length)
{
    bladeNum = num;
    bladeLength = length;
}

Blade::Blade()
{

}

Engine::Engine(string num, string manufacturerName)
{
    engineNum = num;
    manufacturer = manufacturerName;
}

Engine::Engine()
{

}

Wheel::Wheel(string num, int diameter)
{
    wheelNum = num;
    wheelDiam = diameter;
}

Wheel::Wheel()
{

}

// This is the constructor of class LawnMower.
// The constructor accepts the Blade, Engine, and Wheel objects.
// mowerBlade, mowerEngine, mowerWheel are set.
LawnMower::LawnMower(Blade obj1, Engine obj2, Wheel obj3)
{
    mowerBlade = obj1;
    mowerEngine = obj2;
    mowerWheel = obj3;
}

void LawnMower::print()
{
    // print model number of lawnmower
    cout << "Lawn Mower Specification:" << endl;
    cout << "Model:\t" << modelNumber << endl;
    cout << endl;

    // print the information of the blade of this lawnmower
    cout << "Parts Specification" << endl;
    cout << "A) Blade" << endl;
    cout << setw(26) << left << "Blade Serial Number:" << mowerBlade.getBladeNum() << endl;
    cout << setw(26) << left << "Blade Length:" << mowerBlade.getBladeLength() << endl;
    cout << endl;

    // print the information of the engine of this lawnmower
    cout << "B) Engine" << endl;
    cout << setw(26) << left << "Engine Number:" << mowerEngine.getEngineNum() << endl;
    cout << setw(26) << left << "Engine Manufacturer:" << mowerEngine.getManufacturer() << endl;
    cout << endl;

    // print the information of the wheel of this lawnmower
    cout << "C) Wheel" << endl;
    cout << setw(26) << left << "Wheel Serial Number:" << mowerWheel.getWheelNum() << endl;
    cout << setw(26) << left << "Wheel Diameter:" << mowerWheel.getWheelDiameter() << endl;
}

int main()
{
    // initialize Blade, Engine, and Wheel object
    Blade bladeObj("1234", 10);
    Engine engineObj("X456", "Bosch");
    Wheel wheelObj("S3445", 45);

    // create a LawnMower object by passing the Blade, Engine, and Wheel object created
    LawnMower lawnMowerObj(bladeObj, engineObj, wheelObj);

    // print the information of the lawnmower
    lawnMowerObj.print();

    return 0;
}

/* Output
Lawn Mower Specification:
Model:  ABD1234

Parts Specification
A) Blade
Blade Serial Number:      1234
Blade Length:             10

B) Engine
Engine Number:            X456
Engine Manufacturer:      Bosch

C) Wheel
Wheel Serial Number:      S3445
Wheel Diameter:           45

*/
