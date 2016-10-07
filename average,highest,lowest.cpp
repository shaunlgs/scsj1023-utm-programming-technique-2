/*He want 30 days of sale
- write into file
- then read from file to get highest lowest and average sale
- atleast 3 function*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void average(float data[])
{
    float total = 0.00;

    for(int i=0; i<30; i++)
    {
        total += data[i];
    }

    cout << "Average sales: ";
    cout << fixed << showpoint << setprecision(2) << total / 30 << endl;

    return;
}

void highest(float data[])
{
    float highest = data[0];

    for(int i=0; i<30; i++)
    {
        if(data[i] > highest)
        {
            highest = data[i];
        }
    }

    cout << "Highest sale: ";
    cout << fixed << showpoint << setprecision(2) << highest << endl;

    return;
}

void lowest(float data[])
{
    float lowest = data[0];

    for(int i=0; i<30; i++)
    {
        if(data[i] < lowest)
        {
            lowest = data[i];
        }
    }
    cout << "Lowest sale: ";
    cout << fixed << showpoint << setprecision(2) << lowest << endl;

    return;
}

int main()
{
    float sales[30];
    fstream inFile;
    fstream outFile;
    float temp;
    float data[30];

    inFile.open("sales.txt", ios::out);


    char autoFill;
    cout << "Autofill? y/n" << ": ";
    cin >> autoFill;

    if (autoFill == 'y')
    {
        float random = 500.00;
        for(int i=0; i<30; i++)
        {
            cout << "Sale #" << i+1 << ": ";
            cout << fixed << showpoint << setprecision(2) << random << endl;
            inFile << fixed << showpoint << setprecision(2) << random;
            inFile << '\n';
            random += 200.00;
        }
    }
    else
    {
        for(int i=0; i<30; i++)
        {
            cout << "Sale #" << i+1 << ": ";
            cin >> sales[i];
            inFile << fixed << showpoint << setprecision(2) << sales[i];
            inFile << '\n';
        }
    }

    inFile.close();

    outFile.open("sales.txt", ios::in);
    for(int i=0; i<30; i++)
    {
        outFile >> data[i];
    }
    outFile.close();

    average(data);
    highest(data);
    lowest(data);

    return 0;
}
