#include <iostream>
#include <vector>
using namespace std;

class Time
{
    private:
        int hour;
        int minute;
    public:
        Time(){};
        Time(int hour, int minute)
        {
         this->hour = hour;
         this->minute = minute;
        }
        int getHour();
        int getMinute();
};

class Passenger
{
    private:
        string name;
        int age;
    public:
        Passenger(string name, int age)
        {
            this->name = name;
            this->age = age;
        }
        virtual void printDetails()
        {
            cout << "Name: " << this->name << "\t";
            cout << "Age: " << this->age << "\t";
        }
};

class Kids : public Passenger
{
    private:
        string parentName;
    public:
        Kids(string name, int age, string parentName) : Passenger(name, age)
        {
            this->parentName = parentName;
        }
        virtual void printDetails()
        {
            Passenger::printDetails();
            cout << "Parent Name: " << this->parentName << "\t";
            cout << endl;
        }
};

class Adult : public Passenger
{
    private:
        string job;
    public:
        Adult(string name, int age, string job) : Passenger(name, age)
        {
            this->job = job;
        }
        virtual void printDetails()
        {
            Passenger::printDetails();
            cout << "Job: " << this->job << "\t";
            cout << endl;
        }
};

class Flight
{
    private:
        string id;
        string destination;
        Time depart;
        Time arrival;
        vector<Passenger*> passengerList;
    public:
        Flight(string id, string destination, Time depart, Time arrival)
        {
            this->id = id;
            this->destination = destination;
            this->depart = depart;
            this->arrival = arrival;
        }
        void addPassenger(Passenger*);
        void printInfo();
};

void Flight::addPassenger(Passenger* passengerPtr)
{
    this->passengerList.push_back(passengerPtr);
}

void Flight::printInfo()
{
    cout << "Flight No: " << this->id << endl;
    cout << "Destination: " << this->destination << endl;
    cout << "Departure: " << this->depart.getHour() << ":";
    if(this->depart.getMinute()==0)
    {
        cout << "00" << endl;
    }
    else
    {
        cout << this->depart.getMinute() << endl;
    }
    cout << "Arrival: " << this->arrival.getHour() << ":";
    if(this->arrival.getMinute()==0)
    {
        cout << "00" << endl;
    }
    else
    {
        cout << this->arrival.getMinute() << endl;
    }
    cout << endl;

    cout << "Number of Passengers: " << this->passengerList.size() << endl;
    cout << endl;

    cout << "Passengers Details:" << endl;
    for(int i=0; i<passengerList.size(); i++)
    {
        passengerList[i]->printDetails();
    }
}

int Time::getHour()
{
    return this->hour;
}

int Time::getMinute()
{
    return this->minute;
}

int main()
{
    Time depart(8, 10), arrival(9, 0);

    Flight flight1("NAS7921", "Johore Bahru", depart, arrival);

    Adult adult1("Ali", 34, "Lecturer"), adult2("Goh", 25, "Student");
    Kids kid1("Azmi", 3, "Ali");

    // methods use polymorphism, pass in pointers
    Passenger* ptr1 = &adult1;
    Passenger* ptr2 = &adult2;
    Passenger* ptr3 = &kid1;


    flight1.addPassenger(ptr1);
    flight1.addPassenger(ptr2);
    flight1.addPassenger(ptr3);

    flight1.printInfo();
}
