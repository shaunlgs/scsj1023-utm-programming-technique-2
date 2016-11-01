#include <iostream>
#include <string>
using namespace std;

class Address
{
    private:
        string registrar;
        string country;
    public:
        Address();
        void set(string, string);
        string getRegistrar();
        string getCountry();
};

class Ship
{
    private:
        string name;
        int yearMade;
        Address address;
    public:
        Ship();
        void read();
        void print();
};

Address::Address()
{
}

string Address::getRegistrar()
{
    return this->registrar;
}

string Address::getCountry()
{
    return this->country;
}

void Address::set(string a, string b)
{
    this->registrar = a;
    this->country = b;
}

Ship::Ship()
{
}

void Ship::read()
{
    string shipName, registrarOffice, country;
    int yearBuilt;

    cout << "<<< Enter the information of the ship >>>" << endl;
    cout << endl;

    cout << "Ship Name: ";
    getline(cin, shipName, '\n');

    cout << "Year Built: ";
    cin >> yearBuilt;
    cin.ignore();

    cout << "The address the ship was registered:" << endl;

    cout << "Registrar Office: ";
    getline(cin, registrarOffice, '\n');

    cout << "Country: ";
    getline(cin, country, '\n');

    this->name = shipName;
    this->yearMade = yearBuilt;
    this->address.set(registrarOffice, country);
}

void Ship::print()
{
    cout << "Ship Name: " << this->name << endl;
    cout << "Year Built: " << this->yearMade << endl;
    cout << "Registered at:" << endl;
    cout << "  " << this->address.getRegistrar() << ", " << this->address.getCountry() << endl;
    cout << endl;
}



int main()
{
    int sentinel;
    Ship* shipArray = new Ship[10];
    int shipCount = 0;

    do
    {
        cout << "======= MENU =======" << endl;
        cout << "1. Add a ship" << endl;
        cout << "2. Display ships" << endl;
        cout << "3. Exit" << endl;
        cout << endl;
        cout << "Choose an operation => ";
        cin >> sentinel;
        cout << endl;

        // add a ship
        if(sentinel == 1)
        {
            cin.ignore();

            shipArray[shipCount].read();

            cout << endl;
            cout << "Press any key to continue..." << endl;
            cout << endl;

            shipCount += 1;


        }
        // display ships
        else if(sentinel == 2)
        {
            cout << "<<< Inventory of ships >>>" << endl;
            cout << endl;
            cout << "Total ship: " << shipCount << endl;
            cout << endl;
            cout << "==== Ship List ====" << endl;
            cout << endl;

            for(int i=0; i<shipCount; i++)
            {
                shipArray[i].print();
            }

            cout << endl;
            cout << "Press any key to continue..." << endl;
            cout << endl;
        }
    }
    while(sentinel != 3);

    return 0;
}
