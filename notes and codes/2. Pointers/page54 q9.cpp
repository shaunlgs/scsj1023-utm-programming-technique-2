// page54 q9
#include <iostream>
using namespace std;

void myfunc(int *x)
{
     *x = 12;
}
void yourfunc(int *y)
{
     for(int i=0; i<4; i++)
     {
             *(y+i) *= 2;
     }     
}

int main()
{
    int v=10;
    int w[] = {1,2,3,4};
    myfunc(&v);
    cout << v << endl;
    yourfunc(w);
    for(int i=0; i<4; i++)
            cout << w[i] << endl;
    system("pause");
    return 0;
}
