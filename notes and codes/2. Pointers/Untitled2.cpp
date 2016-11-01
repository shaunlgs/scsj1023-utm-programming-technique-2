#include <iostream>
using namespace std;

int main ()
{
	int x = 25;
	int* ptr;
	ptr = &x;
	
	cout << "The value of x is " << x << endl;
	// use indirection operator/ dereferennce
	cout << "The value in x is " << *ptr << endl;
	
	*ptr = 100;
	
	cout << "The value of x is " << x << endl;
	// use indirection operator/ dereferennce
	cout << "The value in x is " << *ptr << endl;
	
	system("PAUSE");
	return 0;
}
