#include <iostream>
using namespace std;

class Faculty{
 public:
    void display();
    int fac; };

int main(){
  Faculty major, minor;

  cout << "Enter the faculty of your major:\n";
  cout << "   (in numeric code):";
  cin >> major.fac;

  cout << "\nEnter the faculty of your minor:\n";
  cout << "     month (in numeric code):";
  cin >> minor.fac;

  cout << "Your major is in the Faculty of ";
  major.display();
  cout << endl;

  cout << "Your minor is in the Faculty of ";
  minor.display();
  cout << endl;

  if (major.fac == minor.fac)
    cout << "You cannot major and minor in the same faculty!!\n";
  else
    cout << "Your records are in order.\n";

  return 0;
}

void Faculty::display(){
  switch (fac)  {
   case 1 : cout << fac << " Computing.\n";
            break;
   case 2 : cout << fac << " Civil Engineering.\n";
            break;
   case 3 : cout << fac << " Electrical Engineering.\n";
            break;
   case 4 : cout << fac << " Mechanical Engineering.\n";
            break;
   case 5 : cout << fac << " Chemical Engineering.\n";
            break;
   case 6 : cout << fac <<" Bio-medical Engineering.\n";
            break;
   case 7 : cout << fac << " Human Resources.\n";
            break;
   case 8 : cout << fac << " Education.\n";
            break;
   case 9 : cout << fac << " Science.\n";
            break;
   case 10 : cout << fac << " Architecture.\n";
            break;
   case 11 : cout << fac << " Geo-science.\n";
  }
}
