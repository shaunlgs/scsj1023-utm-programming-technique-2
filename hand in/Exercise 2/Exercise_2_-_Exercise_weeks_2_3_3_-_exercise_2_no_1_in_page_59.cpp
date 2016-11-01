#include <iostream>
using namespace std;

int main()
{
    int Count = 5, Data;
    int *pCount, *pData;

    pCount = &Count;
    Data = *pCount;
    pData = &Data;

    cout << Count << &Count << pCount << *pCount << endl;
    cout << Data << &Data << pData << *pData << endl;

    return 0;
}
