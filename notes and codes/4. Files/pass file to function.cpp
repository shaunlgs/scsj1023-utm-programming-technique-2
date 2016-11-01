#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LINE_SIZE = 81;

bool openFileIn(fstream &file, char *name)
{
     file.open(name, ios::in);
     if(file.fail())
                    return false;
     else
         return true;
}
void showContents(fstream &file)
{
     char line[MAX_LINE_SIZE];
     
     while(file >> line)
     {
                cout << line << endl;
     }
}

int main()
{
    fstream dataFile;
    
    if(!openFileIn(dataFile,"demofile2.txt"))
    {
                                           cout << "File open error!" << endl;
                                           return 0;
    }
    cout << "File opened successfully.\n";
    cout << "Now reading data from the file.\n\n";
    showContents(dataFile);
    dataFile.close();
    cout << "\nDone.\n";
    
    system("pause");
    return 0;
                                           
}
