#include <iostream>
using namespace std;

class Number
{
    private:
        int m_num;
    public:
        Number();
        Number(int n);
        int GetNumber();
        void SetNumber(int n);
        Number operator++();
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

Number Number::operator++ ()
{
    m_num += 1;
	return *this;
}

int main()
{
	Number num1(5);
	++num1;
	cout << num1.GetNumber() << endl;
	return 0;
}
