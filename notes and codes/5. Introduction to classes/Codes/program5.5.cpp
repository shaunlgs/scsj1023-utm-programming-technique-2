#include <iostream>
using namespace std;

class Polygon
{
    private:
        int side;
        double length;
    public:
        Polygon()
        {
            cout << "first constructor" << endl;
        }
        Polygon(int a)
        {
            cout << "second constructor" << endl;
        }
        Polygon(int a,int b)
        {
            cout << "third constructor" << endl;
        }
        Polygon(double a,int b)
        {
            cout << "fourth constructor" << endl;
        }
};

int main()
{
    Polygon one;
    Polygon two(3,4);
    Polygon three(5,8.5);
    Polygon four(4);

    return 0;
}
