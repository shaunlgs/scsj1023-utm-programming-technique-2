#include<iostream>
using namespace std;
class Test{

             int counter;
      public:
             Test(){
                    counter=0;
             }
             void numberSoFar(){
               counter++;
               cout<<counter<<endl;
               }
};
int main(){
    Test a, b, c;

    a.numberSoFar();
    b.numberSoFar();
    c.numberSoFar();

}
