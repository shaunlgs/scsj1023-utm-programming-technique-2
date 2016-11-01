// This program demonstrates how construtors and
// destructors work
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class JobDesc
{
  private:
    char jobTitle[50];

  public:
    JobDesc(const char jTitle []);  // Constructor declaration
     ~JobDesc();              // Destructor declaration
};

// Function definition for the constructor
JobDesc::JobDesc (const char jTitle[])
{
  strcpy(jobTitle, jTitle);
  cout<<"You are now in the constructor of object " <<
      jobTitle << endl;
}

// Function definition for the destructor
JobDesc::~JobDesc()
{
  cout<< "You are now in the destructor of object " <<
      jobTitle << endl;
}

// Definition of an ordinary function: func()
void func()
{
  cout << "You are now in func()" << endl;
  JobDesc job2("Technician");
  cout << "After creating job2" << endl;
}

int main()
{
   cout << "You are in function main" << endl;
   JobDesc job1("Lecturer");
   cout << "After creating job1" << endl;
   cout << "Before calling to func()" << endl;
   func();
   cout << "After calling to func()" << endl;

   return 0;
}
