#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char input;
    cout<<"Enter any character: ";
    cin.get(input);
    
    if (isalpha(input)){
       cout.put(input);
       cout << endl;
       cout << "It is an alphabet" << endl;
    }
    if (isdigit(input))
       cout << "It is a digit" << endl;
    if (islower(input))
       cout << "The letter entered is lowercase" << endl;
    if (isupper(input))
       cout << "The letter entered is uppercase" << endl;
       
    system("pause");
    return 0;
}
