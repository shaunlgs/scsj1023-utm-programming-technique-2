// This program contains two classes, Person, and Cat. This is an association.
// Each person can have many cats. A person gains a cat when he/ she adopts the cat.
// This program will create some person, and cats. Each person will adopt some cats.
// Then, the information of person and cats will be printed on screen.
#include <iostream>
#include <string>
using namespace std;

class Cat
{
    private:
        string name;
        int age;
        int yearAdopt;
    public:
        Cat();
        Cat(string, int, int);
        string getName() const
        {
            return name;
        }
        int getAge() const
        {
            return age;
        }
        int calcNumOfYear();
};

class Person
{
    private:
        string name;
        string address;
        // keep track of how many cats has been adopted by this person
        int numCat;
        // initialize array with 10 Cat elements to store a maximum of 10 cats
        Cat myCat[10] = {};
    public:
        Person(string, string);
        void adopt(Cat);
        void print();
};

Cat::Cat()
{

}

// This is the constructor of class Cat.
// The constructor accepts the name, age, and year adopted by person.
// It then sets the name, age, and yearAdopt.
Cat::Cat(string name, int age, int yearAdopt)
{
    this->name = name;
    this->age = age;
    this->yearAdopt = yearAdopt;
}

// calcNumOfYear() is a member function of class Cat.
// It calculates the number of years the cat has been adopted by person.
// The current year is assumed to be 2016.
int Cat::calcNumOfYear()
{
    return 2016-yearAdopt;
}

// This is the constructor of class Person.
// The constructor accepts the name and address of the person
// and sets the name and address.
Person::Person(string name, string address)
{
    this->name = name;
    this->address = address;
    numCat = 0;
}

// adopt() is a member function of class Person.
// The function adopts a cat.
// The function accepts a Cat object and stores in the myCat Cat array.
// Number of cats is incremented.
void Person::adopt(Cat catObj)
{
    myCat[numCat] = catObj;
    numCat += 1;
}

// print() is a member function of class Person.
// The function prints the person information (name, address, number of cats adopted),
// and each cat's information (name, age, number of years the cat is adopted by the person)
void Person::print()
{
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Number of cats: " << numCat << endl;
    cout << endl;

    for(int i=0; i<numCat; i++)
    {
        cout << "Cat #" << i+1 << ": " << endl;
        cout << "Name: " << myCat[i].getName() << endl;
        cout << "Age: " << myCat[i].getAge() << endl;
        cout << "Years adopted: " << myCat[i].calcNumOfYear() << endl;
        cout << endl;
    }
    cout << "----------------------------------" << endl;
}

int main()
{
    // create two persons
    Person shaun = Person("Shaun", "A-13A-09 Apartment Bayu Puteri, No 3 Jalan Tropicana Selatan, PJU 3, Petaling Jaya");
    Person ahmad = Person("Ahmad", "108, Bandar Utama 2/3, Petaling Jaya");

    // create six cats
    Cat firstCat = Cat("Garfield", 7, 2013);
    Cat secondCat = Cat("Rawr", 4, 2015);
    Cat thirdCat = Cat("Meow", 9, 2010);
    Cat fourthCat = Cat("Godzilla", 13, 2009);
    Cat fifthCat = Cat("Harimau", 3, 2011);
    Cat sixthCat = Cat("Kitty", 10, 2008);

    // each person adopts some cats
    shaun.adopt(firstCat);
    shaun.adopt(secondCat);
    shaun.adopt(thirdCat);
    shaun.adopt(fourthCat);
    ahmad.adopt(fifthCat);
    ahmad.adopt(sixthCat);

    // print the information of the person, number of cats they adopted, and the information of cats they adopted
    shaun.print();
    ahmad.print();

    return 0;
}

/* output
Name: Shaun
Address: A-13A-09 Apartment Bayu Puteri, No 3 Jalan Tropicana Selatan, PJU 3, Pe
taling Jaya
Number of cats: 4

Cat #1:
Name: Garfield
Age: 7
Years adopted: 3

Cat #2:
Name: Rawr
Age: 4
Years adopted: 1

Cat #3:
Name: Meow
Age: 9
Years adopted: 6

Cat #4:
Name: Godzilla
Age: 13
Years adopted: 7

----------------------------------
Name: Ahmad
Address: 108, Bandar Utama 2/3, Petaling Jaya
Number of cats: 2

Cat #1:
Name: Harimau
Age: 3
Years adopted: 5

Cat #2:
Name: Kitty
Age: 10
Years adopted: 8

----------------------------------
*/
