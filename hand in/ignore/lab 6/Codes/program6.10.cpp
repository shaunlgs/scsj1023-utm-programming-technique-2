#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class kawan2;

class kawan1
{
	int value;
	char girlF[10];
	int age;
	void secret() {strcpy(girlF, "Amy"); age = 30;}
public:
	kawan1(int a) { value = a; secret();}
	void print() { cout << " "<< value << " ";}
	friend void tukarGanti(kawan1 &, kawan2 &);
};

class kawan2
{
	int value;
	int age;
	char girlF[10];
	void secret() {strcpy(girlF, "Lisa");age=22;}
public:
	kawan2(int a) { value = a; secret();}
	void print() { cout << " "<< value << " ";}
	friend void tukarGanti(kawan1 &, kawan2 &);
};

void tukarGanti(kawan1 & x, kawan2 &y)
{
	int temp = x.value;
	x.value = y.value;
	y.value = temp;
}

int main()
{
	kawan1 objek1(100);
	kawan2 objek2(50);
	cout << "\nValue before function tukarGanti()";
	objek1.print();
	objek2.print();
	tukarGanti(objek1,objek2);
	cout << "\nValue after function tukarGanti()";
	objek1.print();
	objek2.print();
	return 0;
}
