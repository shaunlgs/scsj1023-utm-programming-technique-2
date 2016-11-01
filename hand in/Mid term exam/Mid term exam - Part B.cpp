#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Bread
{
      private:
              string code;
              float price;
              int quantity;
              string name;
      public:
             void setCode(string inputCode) { code = inputCode; }
             void setPrice(float inputPrice) { price = inputPrice; }
             void setQuantity(int inputQuantity) { quantity = inputQuantity; }
             void setName(string inputName) { name = inputName; }
             string getCode() {return code;}
             int getQuantity() {return quantity;}
             float getPrice();
             string getName();
             friend float calculateTotal(Bread[]);
};

float Bread::getPrice()
{
      string priceString;
      int cents;
      priceString = code.substr(3,3);
      cents = atoi(priceString.c_str());
      price = cents / 100.00;
      return price;
}

string Bread::getName()
{
       name = code.substr(0,3);
       if(!strcmp(name.c_str(),"101"))
       {
        name = "Raisin Croissant";
       }
       else if(!strcmp(name.c_str(),"102"))
       {
            name = "Sugar Croissant";
       }
       else if(!strcmp(name.c_str(),"201"))
       {
            name = "Sambal Bun";
       }
       else if(!strcmp(name.c_str(),"202"))
       {
            name = "Cheese Bun";
       }
       else
       {
            name = "Kaya Braid";
       }
       return name;
}

float calculateTotal(Bread* arrayBread)
{
    float total = 0.00;

    for(int i=0; i<4; i++)
    {
        total += arrayBread[i].getPrice() * arrayBread[i].getQuantity();
    }

    return total;
}

int main()
{
    Bread soldBread[4];
    string tempCode;
    int tempQuantity;
    float totalSales = 0.00;

    cout << "Please enter the information of bread:" << endl;

    cout << endl;

    for(int i=0; i<4; i++)
    {
            cout << "Bread #" << i+1 << endl;
            cout << "Code: ";
            cin >> tempCode;
            cout << "Quantity: ";
            cin >> tempQuantity;
            cout << endl;

            soldBread[i].setCode(tempCode);
            soldBread[i].setQuantity(tempQuantity);
    }

    cout << "Record of Daily Bread Sales" << endl;

    cout << endl;

    cout << setw(10) << left << "No" << setw(15) <<  left << "Bread Code" << setw(25) << left << "Bread Name" << setw(15) << left << "Price(RM)" << setw(8) << left << "Quantity" << endl;

    for(int i=0; i<4; i++)
    {
       cout << setw(10) << left << i+1;
       cout << setw(15) << left << soldBread[i].getCode();
       cout << setw(25) << left << soldBread[i].getName();
       cout << setw(15) << left << fixed << setprecision(2) << soldBread[i].getPrice();
       cout << setw(8) <<left << soldBread[i].getQuantity();
       cout << endl;
    }

    cout << "Total daily sales: RM" << fixed << setprecision(2) << calculateTotal(soldBread) << endl;

    system("pause");
    return 0;
}
