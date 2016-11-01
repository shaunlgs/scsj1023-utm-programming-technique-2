#include <iostream>
using namespace std;

class FeetInches
{
    private:
        int feet;
        int inches;
    public:
        // act as default constructor and constructor of two int
        FeetInches(int f=0, int i=0)
        {
            feet = f;
            inches = i;
        }
        // i. copy constructor
        // pass by constant reference pointer
        FeetInches(const FeetInches &x)
        {
            feet = x.feet;
            inches = x.inches;
        }
        void setFeet(int f)
        {
            feet = f;
        }
        void setInches(int i)
        {
            inches = i;
        }
        int getFeet() const
        {
            return feet;
        }
        int getInches() const
        {
            return inches;
        }
        // ii.
        FeetInches multiply(const FeetInches &x)
        {
            FeetInches temp(feet*x.feet, inches*x.inches);

            return temp;
        }
};

int main()
{
    FeetInches one(20,50);
    FeetInches two(one);
    FeetInches three;

    three = one.multiply(two);

    cout << one.getFeet() << endl << two.getFeet() << endl << three.getFeet() << endl;

    return 0;
}
