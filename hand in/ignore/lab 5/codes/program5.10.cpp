#include <iostream>
using namespace std;

class Bonus
{
    public:
        int pay;
        Bonus (int p){ pay = p; }
        Bonus (){ pay  = 0; }
};

void increment(Bonus p)
{
    p.pay++;
}

int main()
{
    Bonus myBonus;

    for(int i=0;i<10;i++)
        increment(myBonus);
    cout << myBonus.pay;

    return 0;
}
