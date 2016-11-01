#include <iostream>
using namespace std;

class Transport
{
    public:
        Transport();
        Transport(const Transport&);
};

Transport::Transport()
{
    cout << "Transport default constructor is called" << endl;
}

Transport::Transport(const Transport& trans)
{
    cout << "Transport copy constructor is called" << endl;
}

class Car : public Transport
{
    public:
        Car()
        {
            cout << "Car default constructor is called" << endl;
        }
        Car(const Car& car)
        {
            cout << "Car copy constructor is called" << endl;
        }
};

class Motor : public Transport
{
    public:
        Motor()
        {
            cout << "Motor default constructor is called" << endl;
        }
        Motor(const Motor& motor)
        {
            cout << "Motor copy constructor is called" << endl;
        }
};

int main()
{
    Car car1;
    Motor motor1;
    Transport trans = car1;
    return 0;
}
