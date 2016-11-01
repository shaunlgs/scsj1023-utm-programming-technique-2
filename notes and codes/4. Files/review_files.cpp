#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile;
    string filename;
    int number;
    
    cout << "Enter the filename: ";
    cin >> filename;
    
    inputFile.open(filename.c_str());
    
    if(inputFile)
    {
     while(inputFile >> number);
     {
                     cout << number << endl;
     }            
     inputFile.close();
    }
    else
    {
        cout << "Error opening the file.\n";
    }
    system("pause");
    return 0;
}
