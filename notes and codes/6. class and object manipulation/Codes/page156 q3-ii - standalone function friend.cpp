#include <iostream>
using namespace std;

class Accumulator
{
    private:
        int m_nValue;
    public:
        Accumulator() { m_nValue = 0; }
        void Add(int nValue) { m_nValue += nValue; }
        friend void Reset(Accumulator &cAccumulator);
        int getValue() { return m_nValue; }
};

void Reset(Accumulator &cAccumulator)
{
    cAccumulator.m_nValue = 0;
}

int main()
{
    Accumulator testAccumulator;

    testAccumulator.Add(100);
    cout << testAccumulator.getValue() << endl;

    Reset(testAccumulator); // call standalone function Reset(), not testAccumulator.Reset(). Reset is not a member function of class Accumulator.
    cout << testAccumulator.getValue() << endl;

}
