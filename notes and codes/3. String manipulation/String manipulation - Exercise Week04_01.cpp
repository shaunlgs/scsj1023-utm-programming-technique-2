// progress untuk check character

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char ch;
    cout<<"Enter any character: ";
    cin.get(ch);
    
    if(isdigit(ch))
                   cout << "digit" << endl;
    else if (isalpha(ch))
         cout << "letter" << endl;
    else
        cout << "special character" << endl;
    
    system("pause");
    return 0;
}
