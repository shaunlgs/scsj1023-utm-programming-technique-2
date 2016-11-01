#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fdata1, fdata2;
    fdata1.open("hasil.txt");
    fdata2.open("lapor.txt");
    fdata1 << "$" << 555 << "," << 50 << endl;
    cout << "Terima kasih" << endl;
    fdata2 << "Selamat datang ";
    fdata1 << "***" << -3.4 << "CR" << endl;
    fdata2 << "Ke FSKSM, UTM" << endl;
    cout << "Jumpa lagi" << endl;
    fdata1.close();
    fdata2.close();
    
    system("pause");
    return 0;
}
