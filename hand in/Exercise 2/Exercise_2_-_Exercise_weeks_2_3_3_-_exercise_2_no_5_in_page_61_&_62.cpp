#include <iostream>
using namespace std;

void f1(int &a, int &b, int &c)
{
    c = 3; //3
    cout << a << " ";
    cout << b << " ";
    cout << c << " " << endl;
    b = a; //4
    cout << a << " ";
    cout << b << " ";
    cout << c << " " << endl;
    a = c; //5
    cout << a << " ";
    cout << b << " ";
    cout << c << " " << endl;
}

void print(int a, int b, int c, int d, int e, int f)
{
    cout << a << " ";
    cout << b << " ";
    cout << c << " ";
    cout << d << " ";
    cout << e << " ";
    cout << f << " " << endl;
}

void test(int a, int b, int c, int* d, int* e, int* f)
{
    cout << a << " ";
    cout << b << " ";
    cout << c << " ";
    cout << d << " ";
    cout << e << " ";
    cout << f << " " << endl;
}

int main()
{
    int num1=7, num2=5, num3=3, *num4, *num5, *num6; //20
    cout << "&num1 = " << &num1 << endl;
    cout << "&num2 = " << &num2 << endl;
    cout << "&num3 = " << &num3 << endl;
    test(num1, num2, num3, num4, num5, num6);
    num4 = &num2; //22
    test(num1, num2, num3, num4, num5, num6);
    num6 = &num3; //23
    test(num1, num2, num3, num4, num5, num6);
    num5 = &num1; //24
    test(num1, num2, num3, num4, num5, num6);

    print(num1, num2, num3, *num4, *num5, *num6); //26
    f1(num2, num3, num1);
    num6 = &num1; //28
    test(num1, num2, num3, num4, num5, num6);
    print(num1, num2, num3, *num4, *num5, *num6); //29

    return 0;
}
