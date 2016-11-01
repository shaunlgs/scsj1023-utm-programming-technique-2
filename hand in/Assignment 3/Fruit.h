// declaration and definition for the class Fruit
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Fruit
{
    public:
        Fruit();
        string getName();
        double getPricePerKg();
        string getCountry();
        void displayInfo();
        void readData();

    private:
        string name;
        double pricePerKg;
        string country;
};

// default constructor takes no argument. It initializes the attributes or variables with appropriate values.
Fruit::Fruit()
{
    name = "Durian";
    pricePerKg = 25.75;
    country = "Malaysia";
}

// this function returns the name of the fruit
string Fruit::getName()
{
    return name;
}

// this function returns the price per KG of the fruit
double Fruit::getPricePerKg()
{
    return pricePerKg;
}

// this function returns the country of origin of the fruit
string Fruit::getCountry()
{
    return country;
}

// display the name, price per KG, and country of origin of fruit
void Fruit::displayInfo()
{
    cout << "Name: " << name << endl;
    cout << "Price per KG: " << setprecision(2) << fixed << pricePerKg << endl;
    cout << "Country of origin: " << country << endl;
    cout << endl;
}

// prompt user and enter data of fruit
void Fruit::readData()
{
    cout << "Please enter the name of the fruit: " ;
    getline(cin, name);
    cout << "Please enter the price per KG (e.g. 12.25) of the fruit: ";
    cin >> pricePerKg;
    cin.ignore();
    cout << "Please enter the country of origin of the fruit: ";
    getline(cin, country);
    cout << endl;
}
