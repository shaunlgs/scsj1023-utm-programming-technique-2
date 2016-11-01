#include <iostream>
using namespace std;

int printMsg(char* str, char letter)
{
    int count = 0;
    int i=0;
    while(*(str+i) != '\0')
    {
        if(*(str+i) == letter)
        {
            count++;
        }
        i++;
    }
    return count;
}

int main()
{
    char* message = "Salam Satu Malaysia";
    cout << "number of " << 'S' << " in " << message;
    cout << ": ";
    cout << printMsg(message, 'S');
    cout << "\n";
    return 0;
}
