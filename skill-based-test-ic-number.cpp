////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 1, 2016/2017
// Skill-based Test 1 - *** using C-strings
// Prepared by: Ashari Alias
// 25 October 2016
////////////////////////////////////////////////////////////////////////////////

// Remarks: Test Run (by the author),  24 minutes.

#include <iostream>
#include <fstream> //File stream
#include <string> // string type conversion 
#include <string.h>
#include <cstdlib>

using namespace std;

int getAge(const char id[])
{
   char sYear[5]="19";
   char tmp[3];
   int year;
   
   strncpy(tmp,id, 2); // copy 2 characters from tmp to id
   strcat(sYear, tmp); // combine sYear and tmp
   year = atoi(sYear); // assign year with int sYear
   return 2016 - year;    
}

void getGender(const char id[], char gender[])
{
   char sLastDigit[2];
   int lastDigit;
   
   strncpy(sLastDigit, id, 1);
   lastDigit = atoi(sLastDigit);
   if (lastDigit % 2) 
   	strcpy(gender,"Male");   
   else 
   	strcpy(gender,"Female");    
}

void writeReceipt(const char id[], const char name[], const char gender[], int age)
{
     char fileName[80];
     fstream rpt;
     strcpy(fileName, id);
     strcat(fileName, ".out");
     
     rpt.open(fileName,ios::out);
     rpt << name << endl;
     rpt << gender << endl;
     rpt << age << " years old" << endl;
     rpt.close();
}

int main()
{
     char fileName[80];
     fstream db;
     int count;
     char id[13];
     char name[80];
     int age;
     char gender[20];
     char reportFile[80];
     
     cout << "Enter the input file: ";
     cin >> fileName;    // ??
     cin.ignore();
     
     db.open(fileName, ios::in);  // ??
     if (!db)
     {
             cout << "Error! Unable to open the input file. " << endl 
                  << "       No output file is created" << endl;
     }
     else
     {
      count = 0;
      while(!db.eof()) // if not eof
      {
           db >> id; // read id from input file
           db.ignore();
           
           db.getline(name,sizeof(name),'\n'); // read name from file
           age = getAge(id);
           getGender(id, gender);
           writeReceipt(id, name, gender, age); // call writeReceipt function
      }
      
      cout << "The information of each person has been written into the corresponding file." << endl; 
      cout << "Please check your folder." << endl; 
     }
     
     db.close();

    system("pause");
    return 0;
}

	
