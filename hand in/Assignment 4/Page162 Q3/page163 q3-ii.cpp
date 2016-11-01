// This is part ii of page 162/ 163, question 3.
// Borrow some code from part i such as calculateArea, and duplicate functions and add a default constructor.
#include <iostream>
using namespace std;

class Rectangle
{
    int width, height;
    public:
        // default constructor does not accept any input
        Rectangle();
        // constructor
        Rectangle(int, int);
        int calculateArea();
        friend Rectangle duplicate(Rectangle);
};

// returns the area value of a Rectangle object
int Rectangle::calculateArea()
{
    int area;
    area = width * height;
    return area;
}

// This is a standalone function that has access to class Rectangle
// It will accepts a Rectangle object and multiply by 2 both the width and height of the object
// Then it will return the object
Rectangle duplicate(Rectangle exampleRectangle)
{
    exampleRectangle.width *= 2;
    exampleRectangle.height *= 2;
    return exampleRectangle;
}

// Default constructor sets width and height to 0
Rectangle::Rectangle()
{
    width = 0;
    height = 0;
}

// constructor that accepts integers
// sets the width and height
Rectangle::Rectangle(int a, int b)
{
    width = a;
    height = b;
}

int main()
{
    // initialize the two objects of class Rectangle
    // call default constructor when rectb is created
    Rectangle rect(10,30), rectb;
    // double the width and length of rect
    // pass the object returned to rectb
    rectb = duplicate(rect);
    // calculate the arae of rectb
    cout << rectb.calculateArea();

    return 0;
}

/* Output
1200
*/
