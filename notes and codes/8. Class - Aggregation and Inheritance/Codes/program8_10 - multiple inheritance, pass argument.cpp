#include <string>
#include <iostream>
using namespace std;

class Person
{
    private:
        string name;
        int age;
        bool IsMale;
    public:
        Person(string name, int age, bool bIsMale) : name(name), age(age), IsMale(bIsMale)
        {

        }
        string getName() { return name; }
        int getAge() { return age; }
        bool getIsMale() { return IsMale; }
};

class Employee
{
    private:
        string m_strEmployer;
        double m_dWage;
    public:
        Employee(string strEmployer, double dWage) : m_strEmployer(strEmployer), m_dWage(dWage)
        {

        }
        string GetEmployer() { return m_strEmployer; }
        double GetWage() { return m_dWage; }
};

class Teacher : public Person, public Employee
{
    private:
        int m_nTeachesGrade;
    public:
        Teacher(string strName, int nAge, bool bIsMale, string strEmployer, double dWage, int nTeachesGrade)
        : Person(strName, nAge, bIsMale),
        Employee(strEmployer, dWage),
        m_nTeachesGrade(nTeachesGrade)
        {

        }
        void display()
        {
            cout << "Name:\t" << Person::getName() << endl;
            cout << "Age:\t" << Person::getAge() << endl;
            cout << "Employer:\t" << Employee::GetEmployer() << endl;
            cout << "Wage:\t" << Employee::GetWage() << endl;
            cout << "Grade:\t" << m_nTeachesGrade << endl;
        }
};

int main()
{
    Teacher teach1("Allan", 35, true, "UTM", 4500, 45);
    teach1.display();

    return 0;
}
