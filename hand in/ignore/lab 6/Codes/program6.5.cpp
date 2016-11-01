#include <iostream>
using namespace std;

class Accumulator
{
    private:
        int m_nValue;
    public:
        Accumulator() { m_nValue = 0; }
        void Add(int nValue) { m_nValue += nValue; }

        // Make the Reset() function a friend of this class
        friend void Reset(Accumulator &cAccumulator);

        int getValue() { return m_nValue; }
};

void Reset(Accumulator &cAccumulator)
{
    cAccumulator.m_nValue = 0;
}

int main()
{
    // object of class Accumulator is created
    // default constructor is called, and m_nValue is set to 0
    Accumulator testAccumulator;

    // add 200 to the m_nValue of object
    testAccumulator.Add(200);

    // print the m_nValue after adding and before reset
    cout << testAccumulator.getValue() << endl;

    // reset the m_nValue of object
    Reset(testAccumulator);

    // print the m_nValue after reset
    cout << testAccumulator.getValue() << endl;

    return 0;
}

