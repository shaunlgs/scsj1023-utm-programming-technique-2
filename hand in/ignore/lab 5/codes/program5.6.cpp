#include <iostream>
using namespace std;

class Date
{
  private:
       int day;
       int month;
       int year;
  public:
        //(i)Default constructor prototype
        Date();

        //(ii)Constructor with 3 parameters prototype
        Date(int, int, int);

        int getDay ()
        { return day;}
        int getMonth ()
        { return month;}
        int getYear ()
        { return year;}
 };

//(i) Default constructor definition
Date::Date()
{
    day = 1;
    month = 1;
    year = 90; // default to 1990
}

//(ii) Constructor with 3 parameters definition
Date::Date(int inputDay, int inputMonth, int inputYear)
{
    day = inputDay;
    month = inputMonth;
    year = inputYear;
}


int main()
{
    //(iii) Creation of Date object called birthDate
    Date birthDate(13, 8, 92);

    /* (iv) Creation of Date object pointer called
    datePtr */
    Date* datePtr;

    // points to birthDate object
    datePtr = &birthDate;

    // prints out birth day, month, and year
    cout << "My birth day is: " << datePtr->getDay() << endl;
    cout << "My birth month is: " << datePtr->getMonth() << endl;
    cout << "My birth year is: " << datePtr->getYear() << endl;

    return 0;
}
