#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char* name = "shaun";
    char* temp;

    strncpy(temp, name+2, 2); // copy "au"

    temp[2] = '\0'; // add a null terminator

    cout << temp << endl;

    return 0;
}
