#include <iostream>
using namespace std;

class Rectangle {
    int height, width;
    public:
        Rectangle(int a=0, int b=0)
        {
            height = b;
            width = a;
        }
        int getWidth()
        {
            return width;
        }
        int getHeight()
        {
            return height;
        }
        friend Rectangle operator+(Rectangle, Rectangle);
        Rectangle operator-(Rectangle);
};

Rectangle operator+(Rectangle a, Rectangle b)
{
    int newWidth = a.getWidth() + b.getWidth();
    int newHeight = a.getHeight() + b.getHeight();
    return Rectangle(newWidth, newHeight);
}

Rectangle Rectangle::operator-(Rectangle a)
{
    int newWidth = this->getWidth() - a.getWidth();
    int newHeight = this->getHeight() - a.getHeight();
    if (newWidth < 0)
    {
        newWidth = 0;
    }
    if(newHeight < 0)
    {
        newHeight = 0;
    }
    return Rectangle(newWidth, newHeight);
}

int main()
{
    Rectangle firstObj(10, 5), secondObj(2, 3);
    cout << "First obj width: " << firstObj.getWidth() << "\t";
    cout << "First obj height: " << firstObj.getHeight() << endl;
    cout << "Second obj width: " << secondObj.getWidth() << "\t";
    cout << "Second obj height: " << secondObj.getHeight() << endl;
    cout << endl;

    Rectangle thirdObj;
    thirdObj = firstObj + secondObj;
    cout << "Testing operator overloading of +:" << endl;
    cout << "Third obj width: " << thirdObj.getWidth() << "\t";
    cout << "Third obj height: " << thirdObj.getHeight() << endl;
    cout << endl;

    Rectangle fourtObj;
    fourtObj = firstObj - secondObj;
    cout << "Testing operator overloading of -:" << endl;
    cout << "Fourth obj width: " << fourtObj.getWidth() << "\t";
    cout << "Fourth obj height: " << fourtObj.getHeight() << endl;
    cout << endl;


    return 0;
}
