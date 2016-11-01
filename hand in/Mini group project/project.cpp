// This program stores and displays or outputs to file student and lecturer information
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// class Faculty and class Lecturer has a composition relationship.
// Lecturer object has a Faculty object.
class Faculty
{
    private:
        string name;
        string code;
    public:
        Faculty(string name, string code)
        {
            this->name = name;
            this->code = code;
        }
        string getName()
        {
            return name;
        }
        string getCode()
        {
            return code;
        }
};

// class Person is the base class of class Student and class Lecturer
class Person
{
    private:
        string name;
        int age;
        string address;
    public:
        Person(string name, int age, string address)
        {
            this->name = name;
            this->age = age;
            this->address = address;
        }
        string getName()
        {
            return name;
        }
        int getAge()
        {
            return age;
        }
        string getAddress()
        {
            return address;
        }
};

// class Student is the derived class of class Person
class Student : public Person
{
    private:
        string matricNo;
        static int studentCount;
    public:
        Student(string name, int age, string address, string matricNo) : Person(name, age, address)
        {
            this->matricNo = matricNo;
            studentCount++;
        }
        string getMatricNo()
        {
            return matricNo;
        }
        static int getStudentCount()
        {
            return studentCount;
        }
};

// class Lecturer is the derived class of class Person
class Lecturer : public Person
{
    private:
        Faculty fac;
        static int lecturerCount;
    public:
        Lecturer(string name, int age, string address, string facultyName, string facultyCode)
        : Person(name, age, address), // pass arguments from constructor of derived class Lecturer to constructor of base class Person
        fac(facultyName, facultyCode) // invoke constructor of fac object of class Faculty
        {
            lecturerCount++;
        }
        string getFacName()
        {
            return fac.getName();
        }
        string getFacCode()
        {
            return fac.getCode();
        }
        static int getLecturerCount()
        {
            return lecturerCount;
        }
};

// static attributes to store number of students and number of lecturers
int Student::studentCount = 0;
int Lecturer::lecturerCount = 0;

int main()
{
    // vectors to store students and lecturers
    vector<Student> studentVector;
    vector<Lecturer> lecturerVector;

    int sentinel;
    char sentinel2;

    string studentName, studentAddress, studentMatricNo, lecturerName, lecturerAddress, facultyName, facultyCode;
    int studentAge, lecturerAge;

    fstream outData;
    outData.open("output.txt", ios::out);

    // program info
    cout << "---------------------------------------------------" << endl;
    cout << "Mini group project program start" << endl;
    cout << "hand in on: 21/May/2016" << endl;
    cout << "by: Hasrul, Murtadha, Shaun, Suhadah" << endl;
    cout << "---------------------------------------------------" << endl;

    do
    {
        // prompt user to enter choice
        cout << endl;
        cout << "Enter your choice:" << endl;
        cout << "1. Enter data" << endl;
        cout << "2. Display data" << endl;
        cout << "3. Output to file" << endl;
        cout << "4. Quit" << endl;
        cin >> sentinel;

        if(sentinel == 1)
        {
            // ask user which data to enter
            cout << endl;
            cout << "What data do you like to enter?" << endl;
            cout << "a. Student data" << endl;
            cout << "b. Lecturer data" << endl;
            cin >> sentinel2;

            // enter data
            if(sentinel2 == 'a')
            {
                // enter student data
                cout << endl;

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, studentName, '\n');

                cout << "Enter matric number: ";
                getline(cin, studentMatricNo, '\n');

                cout << "Enter age: ";
                cin >> studentAge;

                cout << "Enter address: ";
                cin.ignore();
                getline(cin, studentAddress, '\n');

                Student studentObj(studentName, studentAge, studentAddress, studentMatricNo);

                studentVector.push_back(studentObj);
            }
            else if(sentinel2 == 'b')
            {
                // enter lecturer data
                cout << endl;

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, lecturerName, '\n');

                cout << "Enter age: ";
                cin >> lecturerAge;

                cout << "Enter address: ";
                cin.ignore();
                getline(cin, lecturerAddress, '\n');

                cout << "Enter faculty name: ";
                getline(cin, facultyName, '\n');

                cout << "Enter faculty code: ";
                getline(cin, facultyCode, '\n');

                Lecturer lecturerObj(lecturerName, lecturerAge, lecturerAddress, facultyName, facultyCode);

                lecturerVector.push_back(lecturerObj);
            }
        }
        else if(sentinel == 2)
        {
            // displays info
            cout << endl;
            cout << "------------------Displaying data------------------" << endl;
            cout << "There are " << Student::getStudentCount() << " student(s) and " << Lecturer::getLecturerCount() << " lecturer(s)." << endl;
            cout << endl;

            // student info
            if(studentVector.size() != 0)
            {
               cout << "Student info:" << endl;
            }
            for(int i=0; i<studentVector.size(); i++)
            {
                cout << "Student #" << i+1 << "'s name: " << studentVector[i].getName() << endl;
                cout << "Student #" << i+1 << "'s matric number: " << studentVector[i].getMatricNo() << endl;
                cout << "Student #" << i+1 << "'s age: " << studentVector[i].getAge() << endl;
                cout << "Student #" << i+1 << "'s address: " << studentVector[i].getAddress() << endl;
                cout << endl;
            }

            // lecturer info
            if(lecturerVector.size() != 0)
            {
               cout << "Lecturer info:" << endl;
            }
            for(int i=0; i<lecturerVector.size(); i++)
            {
                cout << "Lecturer #" << i+1 << "'s name: " << lecturerVector[i].getName() << endl;
                cout << "Lecturer #" << i+1 << "'s age: " << lecturerVector[i].getAge() << endl;
                cout << "Lecturer #" << i+1 << "'s address: " << lecturerVector[i].getAddress() << endl;
                cout << "Lecturer #" << i+1 << "'s faculty name: " << lecturerVector[i].getFacName() << endl;
                cout << "Lecturer #" << i+1 << "'s faculty code: " << lecturerVector[i].getFacCode() << endl;
                cout << endl;
            }
        }
        else if(sentinel == 3)
        {
            // output to file
            outData << "------------------Displaying data------------------" << endl;
            outData << "There are " << Student::getStudentCount() << " student(s) and " << Lecturer::getLecturerCount() << " lecturer(s)." << endl;
            outData << endl;

            // student info
            if(studentVector.size() != 0)
            {
               outData << "Student info:" << endl;
            }
            for(int i=0; i<studentVector.size(); i++)
            {
                outData << "Student #" << i+1 << "'s name: " << studentVector[i].getName() << endl;
                outData << "Student #" << i+1 << "'s matric number: " << studentVector[i].getMatricNo() << endl;
                outData << "Student #" << i+1 << "'s age: " << studentVector[i].getAge() << endl;
                outData << "Student #" << i+1 << "'s address: " << studentVector[i].getAddress() << endl;
                outData << endl;
            }

            // lecturer info
            if(lecturerVector.size() != 0)
            {
               outData << "Lecturer info:" << endl;
            }
            for(int i=0; i<lecturerVector.size(); i++)
            {
                outData << "Lecturer #" << i+1 << "'s name: " << lecturerVector[i].getName() << endl;
                outData << "Lecturer #" << i+1 << "'s age: " << lecturerVector[i].getAge() << endl;
                outData << "Lecturer #" << i+1 << "'s address: " << lecturerVector[i].getAddress() << endl;
                outData << "Lecturer #" << i+1 << "'s faculty name: " << lecturerVector[i].getFacName() << endl;
                outData << "Lecturer #" << i+1 << "'s faculty code: " << lecturerVector[i].getFacCode() << endl;
            }

            cout << "Student and lecturer data is outputted in a output.txt file." << endl;
        }
    }
    while(sentinel != 4);

    return 0;
}
