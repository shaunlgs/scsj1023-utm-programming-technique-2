// This program is taken from "Programming Techniques II (C++), Fourth Edition, 2015" by Faculty of Computing, Universiti Teknologi Malaysia, page 162/ 163, question 3, part i and part ii.
// Part ii is in another .cpp file.

#include <iostream>
using namespace std;

// Declaration of class Rectangle
class Rectangle
{
    int width, height;
    public:
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
