#include<iostream>
using namespace std;
class Test{

              static int counter;
      public:
             void numberSoFar(){
               counter++;
               cout<<counter<<endl;
               }
};
int Test::counter=0;
int main(){
    Test a, b, c;
    a.numberSoFar();
    b.numberSoFar();
    c.numberSoFar();

}
