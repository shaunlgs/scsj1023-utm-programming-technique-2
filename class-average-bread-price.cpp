#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Breads
{
   private:
      int code;
      double price;
      string name;

	public:
	    Breads();
	    Breads(int, double, string);
		void setCode(int);
		void setPrice(double);
		void setBreadname(string);
		int getCode()const;
		double getPrice()const;
		string getBreadname()const;
		~Breads();
};

Breads::Breads()
{
    this->code = 0;
    this->price = 0.00;
    name = "";
}

Breads::Breads(int code, double price, string name)
{
    this->code = code;
    this->price = price;
    this->name = name;
}

void Breads::setCode(int code)
{
	this->code = code;
}
void Breads::setPrice(double price)
{
	this->price = price;
}
void Breads::setBreadname(string name)
{
	this->name = name;
}
int Breads::getCode()const
{
	return code;
}
double Breads::getPrice()const
{
	return price;
}
string Breads::getBreadname()const
{
	return name;
}

Breads::~Breads()
{

}

int main( )
{

  Breads breadsArray[100];
  int n, loop;
  int tempCode;
  double tempPrice;
  string tempName;

  cout<<"How many bread type to enter :";
  cin>>n;

  for (loop=0;loop<n;loop++)
  {
  	cout<<"Enter the information of bread #"<<loop+1<<":\n";
  	cout << "Bread Code: ";
  	cin >> tempCode;
  	cin.ignore();
  	cout << "Bread Name: ";
  	getline(cin, tempName);
  	cout << "Price(RM): ";
  	cin >> tempPrice;
  	cout << endl;
  	breadsArray[loop].setCode(tempCode);
  	breadsArray[loop].setPrice(tempPrice);
  	breadsArray[loop].setBreadname(tempName);
  }
  cout<<endl;

    Breads anotherBread(100, 1.00, "Gardenia");

    cout << setw(4) << "No" << setw(13) << "Bread Code" << setw(24) << "Bread Name" << setw(13) << "Price(RM)" << endl;
    cout << endl;

    double total = 0;
    double average;
  for (loop=0;loop<n;loop++)
  {
    cout << setw(4) << loop+1 << setw(13) << breadsArray[loop].getCode() << setw(24) << breadsArray[loop].getBreadname() << setw(13) << setprecision(2) << fixed << breadsArray[loop].getPrice() << endl;
    total += breadsArray[loop].getPrice();
  }

  cout << endl;

  cout << "Total Price(RM):\t" << setprecision(2) << fixed << average << endl;


   return 0;
}
