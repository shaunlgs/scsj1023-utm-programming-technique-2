#include <iostream>
using namespace std;

class Number
{
    private:
        int m_num;
    public:
        Number();
        Number(int n);
        // prefix overloading
        Number operator++();
        // postfix overloading
        Number operator++(int);
        int GetNumber();
        void SetNumber(int n);
};

Number::Number()
{

}

Number::Number(int n)
{
    m_num = n;
}

int Number::GetNumber()
{
    return m_num;
}

void Number::SetNumber(int n)
{
    m_num = n;
}

// prefix overloading
Number Number::operator++ ()
{
    m_num += 1;
    return *this;
}

// postfix overloading
Number Number::operator++ (int)
{
    Number temp = *this;
    m_num += 1;
    return temp;
}

int main()
{
    Number num1(5);

    ++num1;
    cout << num1.GetNumber() << endl;
    num1++;
    cout << num1.GetNumber() << endl;

    return 0;
}
