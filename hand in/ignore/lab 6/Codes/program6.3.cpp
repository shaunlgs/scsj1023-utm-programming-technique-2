#include <iostream>
using namespace std;
class T{
              static int i;
              int j;
      public:
             T(int j){
                   this->j=j;
             }
             int getI(){
                 i++;
                 return i;
             }
             int getJ(){
                 j++;
                 return j;
             }
};
int T::i=0;
int main(){
    T t1(0), t2(0), t3(0);
    cout<<"t1's static i="<<t1.getI()<<endl;
    cout<<"and instance j="<<t1.getJ()<<endl;
    cout<<"t2's static i="<<t2.getI()<<endl;
    cout<<"t2's instance j="<<t2.getJ()<<endl;
    cout<<"t3's static i="<<t3.getI()<<endl;
    cout<<"t3's instance j="<<t3.getJ()<<endl;

}
