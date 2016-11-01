#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#define DEFAULT_SIZE 5

typedef char SubjectCode[9];    // a new data type for
                                // subject codes
class Student{
    private:
        char *name;         // student name
        SubjectCode *subjects; // an array of subject codes
        int maxSubject;     // the maximum subjects
        int subjectCount;   // the number of subjects taken
    public:
        Student();
        Student(const char n[]);
        Student(int max);
        Student(const SubjectCode codes[], int count);
        ~Student();
        const char * getName() const;
        const char * getSubject(int index) const;
        void print() const;
        void setName(const char newName[]);
        void insertSubject(const SubjectCode code);
        void setSubject(int index, const SubjectCode code);

};  // end of class declaration

// class member function implementation

// Constructor 1 (default constructor) sets the name to
// NULL and the maxSubject to DEFAULT_SIZE
Student::Student()
{
   name = '\0';
   maxSubject = DEFAULT_SIZE;
   subjects = new SubjectCode[maxSubject];
   subjectCount = 0;
}

// Constructor 2 sets the name with n
//    and the maxSubject to DEFAULT_SIZE
Student::Student(const char n[])
{
    name = new char[20];
    strcpy(name,n);
    maxSubject = DEFAULT_SIZE;
   subjects = new SubjectCode[maxSubject];
    subjectCount = 0;
}

// Constructor 3 sets the maxSubject to max
//    and the name to NULL
Student::Student(int max)
{
    name = '\0';
    maxSubject = max;
   subjects = new SubjectCode[maxSubject];
   subjectCount = 0;
}

// Constructor 4 set the name to NULL and insert subject
//   codes to array 'subjects' using data 'codes'. //
//   The maxSubject is set to count.
Student::Student(const SubjectCode codes[], int count)
{
    name = '\0';
    maxSubject = count;
   subjects = new SubjectCode[maxSubject];
    for(int i=0; i<count; i++)
    {
        strcpy(subjects[i],codes[i]);
    }
   subjectCount = count;
}

// Destructor free the name and subjects. It also
//   prints a message 'Object бн. is destroyed
Student::~Student()
{
    delete name;
    delete subjects;
    cout << "Object is destroyed" << endl;
}

// Accessor Functions
//returns the name
const char * Student::getName() const
{
    return name;
}

// returns the subject code of index 'index'
const char * Student::getSubject(int index) const
{
    return subjects[index];
}

// Print the object information containing
// Name, Maximum subject could be taken,
// Number of subjects taken and
//   List of subjects taken:
void Student::print() const
{
    cout << "Name: " << name << endl;
    cout << "Maximum subject could be taken: " << maxSubject << endl;
    cout << "Number of subjects taken: " << subjectCount << endl;
    cout << "List of subjects taken: ";
    for(int i=0; i<subjectCount; i++)
    {
        cout << subjects[i] << " ";
    }
    cout << endl;
}

// Mutator Functions
// Sets the student name
void Student::setName(const char newName[])
{
    name = new char[20];
    strcpy(name,newName);
}

// Insert a subject code into the array
//  'subjects'.  This function must firstly check
//   either the array the array is already full.
//   The array is full if subjectCount reaches
//   the maxSubject
void Student::insertSubject(const SubjectCode code)
{
    if(subjectCount >= maxSubject)
    {
        return;
    }

    strcpy(subjects[subjectCount],code);

    subjectCount += 1;
}

// Replace the subject of index 'index'
void Student::setSubject(int index, const SubjectCode code)
{
    strcpy(subjects[index],code);
}

int main()
{
    Student stu1;

    stu1.setName("Afiq");
    stu1.insertSubject("SCSJ1223");
    stu1.insertSubject("SCSJ1243");
    stu1.insertSubject("SCSJ1253");
    stu1.print();
    cout << "The first subject taken by " << stu1.getName()
     << " is " << stu1.getSubject(0) << endl << endl;

    Student stu2("Ahmad Hussein");

    stu2.insertSubject("SCSJ2023");
    stu2.insertSubject("SCSJ2343");
    stu2.print();

    stu2.setSubject(1,"SCSJ3633");
    cout << stu2.getName();
    cout << " has changed his/her second subject to "
     << stu2.getSubject(1) << endl << endl;

    Student stu3(3);

    stu3.setName("Husna");
    stu3.insertSubject("SCSJ1223");
    stu3.insertSubject("SCSJ1243");
    stu3.insertSubject("SCSJ1253");
    stu3.insertSubject("SCSJ2023");
    stu3.insertSubject("SCSJ2343");

    stu3.print();

    cout << endl;

    const SubjectCode list[]={"SCSJ1123", "SCSJ3633",
                         "SCSJ3023", "SCSJ2623" };
    Student stu4(list,4);
    stu4.setName("Abu Bakar");
    stu4.print();

    return 0;
}
