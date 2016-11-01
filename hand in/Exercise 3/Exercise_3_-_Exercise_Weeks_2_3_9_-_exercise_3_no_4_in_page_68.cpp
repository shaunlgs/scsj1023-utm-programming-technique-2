// Exercise 3 - Exercise Weeks 2/3_9 - exercise 3 no. 4 in page 68
// This program calculates the total flooring cost of a house which has several rooms.

#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;

// Definition of readRoomsSize.
// The function accepts the number of rooms as parameter.
// The function returns a pointer that points to the array of rooms' sizes.
double* readRoomsSize(int numOfRooms)
{
    cout << "Enter the width and length of each room:" << endl;

    double width, length, area;
    // dynamically allocate memory for array to store area size of each rooms later
    double* areaArray;
    areaArray = new double[numOfRooms];

    // for every room
    for(int i=0; i<numOfRooms; i++)
    {
        cout << "Room #" << i+1 << " => ";
        // get width and length of room from user
        cin >> width;
        cin >> length;
        // calculate the area size of room
        area = width * length;
        // store area size of room in a dynamic array
        areaArray[i] = area;
    }
    return areaArray;
}

// Extract the width (in inches), length(in inches), and price(in cents) of a linoleum from the linoleum code.
// Return an array containing width, length, price as its elements.
int* extractLinoInfo(char* code)
{
    int width, length, price;
    int* infoArray;
    infoArray = new int[3];

    // extract width
    width = (code[1]-'0')*10+(code[2]-'0');

    // extract length
    length = (code[3]-'0')*10+(code[4]-'0');

    // extract price
    price = (code[5]-'0')*1000+(code[6]-'0')*100+(code[7]-'0')*10+(code[8]-'0');

    infoArray[0] = width;
    infoArray[1] = length;
    infoArray[2] = price;

    return infoArray;
}

// convert inches to feet
double inchesToFeet(int inch)
{
    double feet;
    feet = inch / 12.0;

    return feet;
}

// convert cents to Ringgit
double centsToRinggit(int cents)
{
    double ringgit;
    ringgit = cents / 100.0;

    return ringgit;
}

// area in sqft, linoWidth and linoLength in feet
// Calculate number of Linoleum needed
int numOfLinoleumNeeded(double area, double linoWidth, double linoLength)
{
    int numNeeded;
    numNeeded = (int) ceil(area / (linoWidth * linoLength));

    return numNeeded;
}

int main()
{
    char* linoCode;
    linoCode = new char[9];
    int numOfRooms;
    int* linoCodeInfo;
    linoCodeInfo = new int[3];
    int linoWidth, linoLength, linoPrice, numOfLinoPerRoom, totalNumOfLino = 0;
    double pricePerRoom, totalPrice = 0.00;

    // get linoleum code from user
    cout << "What is the code of linoleum to use?: ";
    cin >> linoCode;

    // get number of rooms to floor from user
    cout << "How many rooms to floor?: ";
    cin >> numOfRooms;

    cout << endl;

    double* sizeArray;
    sizeArray = new double[numOfRooms];

    // get width and length of each room, calculate area of each room, get the pointer to array of rooms' sizes
    sizeArray = readRoomsSize(numOfRooms);

    // extract width, length, and price of individual linoleum from linoleum code
    linoCodeInfo = extractLinoInfo(linoCode);
    linoWidth = linoCodeInfo[0];
    linoLength = linoCodeInfo[1];
    linoPrice = linoCodeInfo[2];

    // Print information to file
    ofstream outData;
    outData.open("output.txt");

    outData << "Linoleum Size: ";
    outData << setprecision(2) << fixed << inchesToFeet(linoWidth) << " Feet x " << setprecision(2) << fixed << inchesToFeet(linoLength) << " Feet" << endl;

    outData << "Linoleum Price: ";
    outData << "RM " << setprecision(2) << fixed << centsToRinggit(linoPrice) << " per piece"<< endl;

    outData << endl;

    outData << setw(20) << left << "Room No." << setw(20) << left << "Size(sqft)" << setw(30) << left << "Number of Linoleum (pieces)" << setw(20) << left << "Cost" << endl;
    // for each room
    for(int i=0; i<numOfRooms; i++)
    {
        // print room number
        outData << setw(20) << left << i+1;
        // print room size in sqft
        outData << setw(20) << left << setprecision(2) << fixed << sizeArray[i];
        // print number of Linoleum needed for each room
        numOfLinoPerRoom = numOfLinoleumNeeded(sizeArray[i], inchesToFeet(linoWidth), inchesToFeet(linoLength));
        totalNumOfLino += numOfLinoPerRoom;
        outData << setw(30) << left << numOfLinoPerRoom;
        // print cost of flooring each room
        pricePerRoom = numOfLinoPerRoom * centsToRinggit(linoPrice);
        totalPrice += pricePerRoom;
        outData << setw(20) << left << setprecision(2) << fixed << pricePerRoom;
        outData << endl;
    }

    outData << endl;

    outData << "Total Linoleum Required: " << totalNumOfLino << " Pieces" << endl;
    outData << "Total Cost: RM " << setprecision(2) << fixed << totalPrice << endl;

    // tell user that information had finished printed to file
    cout << "The flooring cost has been written into the output file" << endl;

    return 0;
}
