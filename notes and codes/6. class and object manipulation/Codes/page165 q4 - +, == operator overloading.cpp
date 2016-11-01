#include <iostream>
using namespace std;

class Length
{
    private:
        int len_inches;
    public:
        Length(int feet, int inches)
        {
            len_inches = 12*feet+inches;
        }
        int getFeet()
        {
            return len_inches/12;
        }
        int getInches()
        {
            return len_inches%12;
        }
        // bool operator<(Length);
        friend bool operator<(Length, Length);
        friend bool operator==(Length, Length);
};

/* overloading operator < requires only one argument if it is a member of a class
bool Length::operator<(Length b)
{
    if(this->getFeet()<b.getFeet())
    {
        return true;
    }
    else if (this->getFeet()==b.getFeet() && this->getInches()<b.getInches())
    {
        return true;
    }
    return false;
}
*/

// i.
bool operator<(Length a, Length b)
{
    if(a.getFeet() < b.getFeet())
    {
        return true;
    }
    else if(a.getFeet() == b.getFeet() && a.getInches() < b.getInches())
    {
        return true;
    }
    return false;
}

// ii.
bool operator==(Length a, Length b)
{
    if(a.getFeet() == b.getFeet() && a.getInches() == b.getInches())
    {
        return true;
    }
    return false;
}

int main()
{
    // iii.a.
    Length lens[4] = {Length(5,6), Length(3,7), Length(5,6), Length(11,3)};

    // iii.b. find indexes of Length objects with equal length
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<(4-i)-1; j++)
        {
            if(lens[i] == lens[i+j+1])
            {
                cout << "Same length at index " << i << " and " << j+1 << endl;
            }
        }
    }

    // iii.c. find shortest and longest Length object
    int shortestIndex = 0;
    int longestIndex = 0;
    for(int i=0; i<4; i++)
    {
        if(lens[i] < lens[shortestIndex])
        {
            shortestIndex = i;
        }
        if(lens[longestIndex] < lens[i])
        {
            longestIndex = i;
        }
    }
    cout << "Shortest Length in feet is " << lens[shortestIndex].getFeet() << " feet at index " << shortestIndex << endl;
    cout << "Longest Length in feet is " << lens[longestIndex].getFeet() << " feet at index " << longestIndex << endl;
}
