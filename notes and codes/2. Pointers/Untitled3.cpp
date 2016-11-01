#include <iostream>
using namespace std;

int main()
{
	int vals[] = {4, 7, 11};
	// we didn't declare a pointer, but we can dereference vals, vals (an array) is actually a pointer
	cout << *(vals+1) << endl;
	cout << *(vals+2) << endl;
	
	int* ptr;
	ptr = vals;
	cout << *(ptr+1) << endl;
	cout << *(ptr+2) << endl;
	
	system("PAUSE");
	return 0;
}
