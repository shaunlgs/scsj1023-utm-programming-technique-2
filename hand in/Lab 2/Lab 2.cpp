// This program stores information about lecturer using structure and pointer concepts.

#include <iostream>
using namespace std;

int main(){
    struct LecturerInfo{
        string name;
        char room[10];
        int extension;
    };
    struct Lecturer{
        int ID;
        LecturerInfo contact;
        string department;
        char facultyCode[10];
    };

    Lecturer dayang = {1234, {"Dayang Norhayati", "306-06", 32354}, "Software Engineering", "FSKSM"};
    Lecturer *me;
    me = &dayang;

    cout << me->contact.name <<endl;
    cout << me->department;
    cout << endl;
    cout << endl;

    // i) Define an array of structure variable called lecturerTP2 (maximum size 10) with the initialized values as follows.
    Lecturer lecturerTP2[10] = {
        {1234, {"Dayang Norhayati", "305-03", 32354}, "Software Engineering", "FC"},
        {5678, {"Norazah Yusof", "305-06", 32341}, "Software Engineering", "FC"},
        {9101, {"Haswadi Hasan", "438-08", 32374}, "Computer Science", "FC"}};

    // ii) Define a pointer variable to point to the third element of the array.
    Lecturer *ptrThird;
    ptrThird = &lecturerTP2[2];

    // iii) Add your lecturer or other Programming Technique II lecturer into the array using the pointer variable defined in (ii).
    Lecturer fourthLecturer = {6829, {"Mohamad Ashari", "306-36", 12313}, "Software Engineering", "FC"};
    Lecturer fifthLecturer = {3512, {"Lizawati", "301-55", 98373}, "Software Engineering", "FC"};
    Lecturer sixthLecturer = {7812, {"Rose Alinda", "312-06", 32111}, "Information System", "FC"};
    Lecturer seventhLecturer = {9910, {"Naomie Salim", "402-02", 11331}, "Information System", "FC"};
    Lecturer eighthLecturer = {3167, {"Rohayanti Hassan", "318-06", 32122}, "Software Engineering", "FC"};
    Lecturer ninthLecturer = {3320, {"Hassan Chizari", "306-09", 36789}, "Software Engineering", "FC"};
    Lecturer tenthLecturer = {4887, {"Murtadha Ahmad", "306-12", 33212}, "Software Engineering", "FC"};

    (*(ptrThird+1)) = fourthLecturer;
    (*(ptrThird+2)) = fifthLecturer;
    (*(ptrThird+3)) = sixthLecturer;
    (*(ptrThird+4)) = seventhLecturer;
    (*(ptrThird+5)) = eighthLecturer;
    (*(ptrThird+6)) = ninthLecturer;
    (*(ptrThird+7)) = tenthLecturer;

    // iv) Print all contents of the array using lecturerTP2 variable.
    for(int i=0; i<10; i++)
    {
        cout << "Lecturer #" << i+1 << endl;
        cout << "ID: " << lecturerTP2[i].ID << endl;
        cout << "Name: " << lecturerTP2[i].contact.name << endl;
        cout << "Room: " << lecturerTP2[i].contact.room << endl;
        cout << "Extension: " << lecturerTP2[i].contact.extension << endl;
        cout << "Department: " << lecturerTP2[i].department << endl;
        cout << "Faculty code: " << lecturerTP2[i].facultyCode << endl;
        cout << endl;
    }

    return 0;
}

/* Output for iv)
Dayang Norhayati
Software EngineeringLecturer

#1
ID: 1234
Name: Dayang Norhayati
Room: 305-03
Extension: 32354
Department: Software Engineering
Faculty code: FC

Lecturer #2
ID: 5678
Name: Norazah Yusof
Room: 305-06
Extension: 32341
Department: Software Engineering
Faculty code: FC

Lecturer #3
ID: 9101
Name: Haswadi Hasan
Room: 438-08
Extension: 32374
Department: Computer Science
Faculty code: FC

Lecturer #4
ID: 6829
Name: Mohamad Ashari
Room: 306-36
Extension: 12313
Department: Software Engineering
Faculty code: FC

Lecturer #5
ID: 3512
Name: Lizawati
Room: 301-55
Extension: 98373
Department: Software Engineering
Faculty code: FC

Lecturer #6
ID: 7812
Name: Rose Alinda
Room: 312-06
Extension: 32111
Department: Information System
Faculty code: FC

Lecturer #7
ID: 9910
Name: Naomie Salim
Room: 402-02
Extension: 11331
Department: Information System
Faculty code: FC

Lecturer #8
ID: 3167
Name: Rohayanti Hassan
Room: 318-06
Extension: 32122
Department: Software Engineering
Faculty code: FC

Lecturer #9
ID: 3320
Name: Hassan Chizari
Room: 306-09
Extension: 36789
Department: Software Engineering
Faculty code: FC

Lecturer #10
ID: 4887
Name: Murtadha Ahmad
Room: 306-12
Extension: 33212
Department: Software Engineering
Faculty code: FC
*/
