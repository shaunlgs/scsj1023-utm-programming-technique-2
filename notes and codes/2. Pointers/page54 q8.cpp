// page 54 q8
#include <iostream>
using namespace std;

int main()
{
    int y[5] = {3,6,9,12,15};
    int *py = &y[0];
    
    py += 2;
    
    if(py == (y+2))
          cout << "True" << endl;
    else
        cout << "False" << endl;
    
    system("pause");
    return 0;
}
