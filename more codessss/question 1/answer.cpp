#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

class Subjects
{
  char GradeEarned;
  char Code[10];
  char Name[30];
  int CreditHour;
  string PointValue;
  double PointEarned;


 public:
  //constructor
    void Subject(char a[], char b[], int c, char d, double e) {
        strcpy(Code, a);
        strcpy(Name, b);
        CreditHour = c;
        GradeEarned= d;
        PointEarned= e;
    }

  //mutator functions
  void   setCode(string);
  void   setSubjectName(string);
  void   setCreditHour(int);
  void   setGradeEarned(char);
  void   setSubjectPointValue(double);

  //accessor functions
  char*    getCode(){return Code;}
  char* getSubjectName(){return Name;}
  int getCreditHour(){return CreditHour;}
  char getGradeEarned(){return GradeEarned;}
  string getPointValue(){return PointValue;}
  double getPointEarned(){return PointEarned;}
};

class TypeSubject
{
 string Point;
 char A,B,C,D,E;

 public:
  string getPoint(char cd){
   if(cd=='A')
   {
    Point = "4.0";
   }else if(cd=='B')
   {
    Point = "3.0";
   }else if(cd=='C')
   {
    Point = "2.0";
   }else if(cd=='D')
   {
    Point = "1.0";
   }else if(cd=='E')
   {
    Point = "0.0";
   }else
   {
    Point = "Undefined Point Value";
   }

   return Point;
  }

};

int main()
{


    char GredEarned;
 	double PPointValue;
    int Loop;
    string StudentMatricNo, StudentName;
    fstream outData;
    outData.open("output.txt", ios::out);

    cout << " Enter the student's matric no => ";
	getline(cin, StudentMatricNo);
    cout << " Enter the student's name => ";
    getline(cin, StudentName);
    cout << " Enter the number of subjects => ";
    cin  >> Loop;
    cin.ignore();

    Subjects obs[Loop];
    TypeSubject obj;

    double sum=0,PointEarned,TotalPointEarned=0,cgpa;
    char Name[30];
	char GGredEarned;
	char Code[10];
    int CreditHour,TotalCreditHour=0;

    for(char i=0; i<Loop; i++)
     {
      cout << "\n Subject #";
      cout << (i+1) << endl;

      cout << " Code => ";
      cin.getline(Code, 10, '\n');

      cout << " Name => ";
      cin.getline(Name, 30, '\n');

      cout << " Credit Hour => ";
      cin >> CreditHour;
      cin.ignore();

      cout << " Gred Earned => ";
      cin >> GGredEarned;
      cin.ignore();

      cout << " Point Value => ";
      cout << obj.getPoint(GGredEarned) << endl;

      PPointValue = atof(obj.getPoint(GGredEarned).c_str());

      PointEarned=PPointValue*CreditHour;

      TotalPointEarned += PointEarned;

      TotalCreditHour += CreditHour;

      cgpa=TotalPointEarned/TotalCreditHour;


      obs[i].Subject(Code,Name,CreditHour,GGredEarned,PointEarned);
     }
 cout <<"--------------------------------------------------------------------------------" << endl;

 cout << setw(14) << "Student's Name" << ": " << StudentName << endl;
 cout << setw(14) << left << "Student's ID" << ": " << StudentMatricNo << endl << endl;

 cout << setw(18) << left << "Subject's Code" << setw(21) << left << "Name" << setw(14) << left << "Credit Hour" << setw(8) << left << "Grade" << setw(15) << left << "Point Earned" << endl << endl;

 outData <<"--------------------------------------------------------------------------------" << endl;

 outData << setw(14) << "Student's Name" << ": " << StudentName << endl;
 outData << setw(14) << left << "Student's ID" << ": " << StudentMatricNo << endl << endl;

 outData << setw(18) << left << "Subject's Code" << setw(21) << left << "Name" << setw(14) << left << "Credit Hour" << setw(8) << left << "Grade" << setw(15) << left << "Point Earned" << endl << endl;

 for(char i=0; i, i<Loop; i++)
 {
    cout << setw(19) << left << obs[i].getCode() << setw(20) << left << obs[i].getSubjectName() << setw(5) << right << obs[i].getCreditHour() << setw(12) << right << obs[i].getGradeEarned() << setw(11) << right << setprecision(1) << fixed << obs[i].getPointEarned() << endl;

  outData << setw(19) << left << obs[i].getCode() << setw(20) << left << obs[i].getSubjectName() << setw(5) << right << obs[i].getCreditHour() << setw(12) << right << obs[i].getGradeEarned() << setw(11) << right << setprecision(1) << fixed << obs[i].getPointEarned() << endl;
 }

 cout<< "CGPA : " << setprecision(2) << fixed <<cgpa;
 outData<< "CGPA : " << setprecision(2) << fixed <<cgpa;


 return 0;
}
