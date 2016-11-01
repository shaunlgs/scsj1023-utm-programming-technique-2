#include <iostream>
using namespace std;

class Superclass3
{
    public:
        void showValue(int a)
        {
            cout << a << endl;
        }
};

class Subclass3 : public Superclass3
{
    public:
        // overriding/ redefine base function
        void showValue(int a)
        {
            cout << "The subclass: \t" << a << endl;
        }

        // overloading
        void showValue(double a)
        {
            cout << a << endl;
        }
};

int main()
{
    Subclass3 obj;
    obj.showValue(8);
    obj.showValue(8.97);
    return 0;
}
