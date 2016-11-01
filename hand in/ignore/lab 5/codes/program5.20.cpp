#include <iostream>
#include <cstdlib>
using namespace std;

class DayOfYear
{
 public:
    friend bool same (DayOfYear date1,DayOfYear date2);
    DayOfYear(int newMonth, int newDay);
    DayOfYear();
    void enter();
    void display();
    int get_month();
    int get_day();
 private:
    void check_date();
    int month;
    int day;
};

bool same (DayOfYear date1,DayOfYear date2)
{
   return (date1.month == date2.month && date1.day == date2.day);
}

DayOfYear::DayOfYear(int d_month, int d_day)
{
   month = d_month;
   day = d_day;
   check_date();
}

DayOfYear::DayOfYear()
{
   month = 1;
   day = 1;
}

void DayOfYear :: enter()
{
   cout << "     Month (in number):";
   cin >> month;
   cout << "     day (in number):";
   cin >> day;
   check_date();
}

void DayOfYear :: display()
{
  switch (month)
  {
   case 1 : cout << day << " January." << endl;
            break;
   case 2 : cout << day << " February." << endl;
            break;
   case 3 : cout << day << " March." << endl;
            break;
   case 4 : cout << day << " April." << endl;
            break;
   case 5 : cout << day << " May." << endl;
            break;
   case 6 : cout << day << " June." << endl;
            break;
   case 7 : cout << day << " July." << endl;
            break;
   case 8 : cout << day << " August." << endl;
            break;
   case 9 : cout << day << " September." << endl;
            break;
   case 10 : cout << day << " October." << endl;
            break;
   case 11 : cout << day << " November." << endl;
            break;
   case 12 : cout << day << " December." << endl;
            break;
   default : cout << "Invalid number!";
   }
}

void DayOfYear :: check_date()
{
   if ((month < 1) || (month > 12) || (day<1) ||
       (day>31))
   {
      cout << "The date is invalid!! End the program.\n";
      exit(1);
   }
}

int DayOfYear::get_month()
{
   return month;
}

int DayOfYear::get_day()
{
   return day;
}

int main()
{
  DayOfYear dateToday, independenceDay(8,31);

  cout << "Enter today¡¯s date:\n";
  dateToday.enter();
  cout << "Today is: ";
  dateToday.display();
    cout << "Malaysia¡¯s Independence Day.";
  independenceDay.display();

  if (same(dateToday, independenceDay))
     cout << "Merdeka! Merdeka! Merdeka!\n";
  else
     cout << "Selamat Datang! Welcome to Malaysia.\n";
  return 0;
}

