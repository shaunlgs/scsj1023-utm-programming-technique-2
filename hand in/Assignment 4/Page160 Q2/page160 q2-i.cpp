// This program is taken from "Programming Techniques II (C++), Fourth Edition, 2015" by Faculty of Computing, Universiti Teknologi Malaysia, page 160, question 2.
// It demonstrates the uses of friend in classes.
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
    // copy the c-string to the variable girlF[] and sets the age
    void secret() {strcpy(girlF, "Amy"); age=30;}
    public:
        // construct sets the value and call the function secret()
        kawan1(int a) {value=a; secret();}
        void print() {cout << " " << value << " ";}
        friend void tukarGanti(kawan1 &, kawan2 &);
};

class kawan2
{
    int value;
    int age;
    char girlF[10];
    // copy the c-string to the variable girlF[] and sets the age
    void secret() {strcpy(girlF, "Lisa"); age=22;}
    public:
        // construct sets the value and call the function secret()
        kawan2(int a) {value=a; secret();}
        void print() {cout << " " << value << " ";}
        friend void tukarGanti(kawan1 &, kawan2 &);
};

// standalone function, tukarGanti is the friend of classes, kawan1 and kawan2
// this means that it can access the private members of the classes.
// this function swaps the value of both objects that is taken in as input
void tukarGanti(kawan1 &x, kawan2 &y)
{
    int temp = x.value;
    x.value = y.value;
    y.value = temp;
}

int main()
{
    // initialize two objects of class kawan1 and kawan2
    kawan1 objek1(100);
    kawan2 objek2(50);
    cout << "\nValue before function tukarGanti()";
    objek1.print();
    objek2.print();
    // call function tukarGanti
    tukarGanti(objek1, objek2);
    cout << "\nValue after function tukarGanti()";
    objek1.print();
    objek2.print();
    return 0;
}

/* Output

Value before function tukarGanti() 100  50
Value after function tukarGanti() 50  100
*/
