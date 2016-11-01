#include <iostream>
using namespace std;

class FeetInches {
    private:
       int feet;
       int inches;
    public:
        FeetInches(int f=0, int i=0){
            feet = f;
            inches = i;
        }

        // copy constructor
        FeetInches(const FeetInches &objToBeCopied)
        {
            feet = objToBeCopied.feet;
            inches = objToBeCopied.feet;
        }

        void setFeet(int f)
        { feet = f; }

        void setInches(int i)
        { inches = i; }

        int getFeet() const
        { return feet; }

        int getInches() const
        { return inches; }

        // multiply the calling object's feet by the argument's object's feet
        // same for inches
        FeetInches multiply(const FeetInches &obj)
        {
            FeetInches tempObj;
            tempObj.feet = feet * obj.feet;
            tempObj.inches = inches * obj.inches;
            return tempObj;
        }
};

int main(){

   FeetInches one(20,50);
   FeetInches two(one);
   FeetInches three;

   three = one.multiply(two);

   cout << one.getFeet() << endl
    << two.getFeet() << endl
    << three.getFeet() << endl;

}
