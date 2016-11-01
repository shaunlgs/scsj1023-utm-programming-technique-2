// This program contains the new kawan1 and kawan2 class from part i.
// This also implements the gossip member function of class kawan1 and kawan2.
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
    void secret() {strcpy(girlF, "Amy"); age=30;}
    public:
        kawan1(int a) {value=a; secret();}
        void print() {cout << " " << value << " ";}
        void gossip(kawan2);
        // class kawan2 can access class kawan1
        friend class kawan2;
};

class kawan2
{
    int value;
    int age;
    char girlF[10];
    void secret() {strcpy(girlF, "Lisa"); age=22;}
    public:
        kawan2(int a) {value=a; secret();}
        void print() {cout << " " << value << " ";}
        void gossip(kawan1);
        // kawan1::gossip() member function of kawan1 class can access class kawan2
        friend void kawan1::gossip(kawan2);
};

// write the functions here
// member function, gossip of kawan1 will take an object of type kawan2 as input
// it access the private member variable value and girlF of kawan2 object
void kawan1::gossip(kawan2 examplekawan2)
{
    cout << value << " gossips on " << examplekawan2.value << endl;
    cout << value << " says " << examplekawan2.value << " girl friend is " << examplekawan2.girlF << endl;
}
// member function, gossip of kawan2 will take an object of type kawan1 as input
// it access the private member variable value and age of kawan1 object
void kawan2::gossip(kawan1 examplekawan1)
{
    cout << value << " gossips on " << examplekawan1.value << endl;
    cout << value << " says " << examplekawan1.value << " age is " << examplekawan1.age << endl;
}

int main()
{
    // initialize objects of class kawan1 and kawan2
    kawan1 objek1(100);
    kawan2 objek2(50);
    // call the member function gossip of each object
    objek1.gossip(objek2);
    objek2.gossip(objek1);
    return 0;
}

/* Output
100 gossips on 50
100 says 50 girl friend is Lisa
50 gossips on 100
50 says 100 age is 30
*/
