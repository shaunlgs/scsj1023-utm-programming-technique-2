#include <iostream>
using namespace std;

class Test5{
      public:
        static int max(int, int);
};

int Test5::max(int x, int y){
    int result;
    if(x>y)
       result=x;
    else
        result=y;
    return result;
}

int main(){
    int i=5;
    int j=2;
    int k=max(i, j);
    cout<<"The max between\t" <<i<<"\tand\t"<<j<<"\tis\t"<<k;
}
