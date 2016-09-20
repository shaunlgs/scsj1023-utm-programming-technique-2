#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
    string ic;
    int current_year = 2016;

    cin >> ic;

    int year = atoi(ic.substr(0,2).c_str());
    int month = atoi(ic.substr(2,2).c_str());
    int date = atoi(ic.substr(4,2).c_str());
    int state = atoi(ic.substr(6,2).c_str());
    int gender = atoi(ic.substr(8,4).c_str());

    string genderStr;
    string stateStr;

    if(year >= 0 and year <= 16)
    {
            year += 2000;
    }
    else
    {
        year += 1900;
    }

    if(gender % 2 == 0)
    {
              genderStr = "Female";
    }
    else
    {
        genderStr = "Male";
    }

    switch (state)
    {
        case 1:
        case 21:
        case 22:
        case 23:
        case 24:
            stateStr = "Johor";
            break;
        case 2:
        case 25:
        case 26:
        case 27:
            stateStr = "Kedah";
            break;
        case 3:
        case 28:
        case 29:
            stateStr = "Kelantan";
            break;
        case 4:
        case 30:
            stateStr = "Melaka";
            break;
        case 5:
        case 31:
        case 59:
            stateStr = "Negeri Sembilan";
            break;
        case 6:
        case 32:
        case 33:
            stateStr = "Pahang";
            break;
        case 7:
        case 34:
        case 35:
            stateStr = "Penang";
            break;
        case 8:
        case 36:
        case 37:
        case 38:
        case 39:
            stateStr = "Perak";
            break;
        case 9:
        case 40:
            stateStr = "Perlis";
            break;
        case 10:
        case 41:
        case 42:
        case 43:
        case 44:
            stateStr = "Selangor";
            break;
        case 11:
        case 45:
        case 46:
            stateStr = "Terengganu";
            break;
        case 12:
        case 47:
        case 48:
        case 49:
            stateStr = "Sabah";
            break;
        case 13:
        case 50:
        case 51:
        case 52:
        case 53:
            stateStr = "Sarawak";
            break;
        case 14:
        case 54:
        case 55:
        case 56:
        case 57:
            stateStr = "Wilayah Persekutuan Kuala Lumpur";
            break;
        case 15:
        case 58:
            stateStr = "Wilayah Persekutuan Labuan";
            break;
        case 16:
            stateStr = "Wilayah Persekutuan Putrajaya";
            break;
        case 82:
        default:
            stateStr = "Others";
            break;
    }

    cout << "Year: " << year << endl;
    cout << "DOB: " << date << "-" << month << "-" << year << endl;
    cout << "Age: " << current_year - year << endl;
    cout << "Gender: " << genderStr << endl;
    cout << "State: " << stateStr << endl;

    return 0;

}
