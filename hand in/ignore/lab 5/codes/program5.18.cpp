#include <iostream>
using namespace std;

class Box
{
    private:
        int length, width, height;

    public:
        Box( );
        Box(int);
        ~Box( );
        void print( ) const;
};

// Definition of functions
Box:: Box ( ) {
   length=0; width=0; height=0;
   cout << "Invisible Box\n";
}

Box:: Box ( int x ) {
   length=x; width=x; height=x;
   cout << "Winning Box " << x << endl;
}

Box:: ~Box ( )
{  cout << "Smashed Box\n";   }

void Box:: print( ) const {
    cout << "Length = " << length;
    cout << "  Width = " << width;
    cout << "  Heigth = " << height << endl;
}

int main( )
{
    Box platinumBox;
    platinumBox.print( );

    cout << "Mystery Box: " << endl;
    Box goldBox(7);
    goldBox.print( );

    Box silverBox(0);
    silverBox.print( );
    return 0;
}
