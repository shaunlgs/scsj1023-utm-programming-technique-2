#include <iostream>
using namespace std;

class Storage
{
    private:
        int m_nValue;
        double m_dValue;
    public:
        Storage(int nValue, double dValue)
        {
            m_nValue = nValue;
            m_dValue = dValue;
        }

        friend class Display;
};

class Display
{
    private:
        bool m_bDisplayIntFirst;
    public:
        Display(bool bDisplayIntFirst)
        {
            m_bDisplayIntFirst = bDisplayIntFirst;
        }
        void DisplayItem(Storage &cStorage)
        {
            if(m_bDisplayIntFirst)
                cout << cStorage.m_nValue << " " << cStorage.m_dValue << endl;
            else
                cout << cStorage.m_dValue << " " << cStorage.m_nValue << endl;
        }
};

int main()
{
    Storage testStorage(3, 1.234);
    Display testDisplay(false);
    testDisplay.DisplayItem(testStorage);
    return 0;
}
