// This is the code for assignment 3, question 1 for Programming Technique II (TP II).
// Question 1 a) asks us to store the employee data keyed in by user into a file.
// Question 1 b) retrieves the employee data from the file and do some calculation
// such as determining age, displaying state name, as well as other employee information.
// Author: Ling Gen Sheng Shaun
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
using namespace std;

const int NAME_LENGTH = 51, IC_NUM_LENGTH = 13, ADDRESS1_LENGTH = 101, ADDRESS2_LENGTH = 101
, TOWN_LENGTH = 51, STATECODE_LENGTH = 3, INCOME_LENGTH = 7;

struct employee
{
	char name[NAME_LENGTH];
	char ic_num[IC_NUM_LENGTH];
	char address1[ADDRESS1_LENGTH];
	char address2[ADDRESS2_LENGTH];
	char town[TOWN_LENGTH];
	char stateCode[STATECODE_LENGTH];
	char income[INCOME_LENGTH];
};

int* getInfoFromIC(char* ic_number)
{
	char year_string[3];
	char month_string[3];
	char day_string[3];

	// extract year, month, day c-string from ic_number c-string
	year_string[0] = ic_number[0];
	year_string[1] = ic_number[1];
	year_string[2] = '\0';

	month_string[0] = ic_number[2];
	month_string[1] = ic_number[3];
	month_string[2] = '\0';

	day_string[0] = ic_number[4];
	day_string[1] = ic_number[5];
	day_string[2] = '\0';

	// convert year, month, day c-string to int
	int year = atoi(year_string);
	int month = atoi(month_string);
	int day = atoi(day_string);

    // array to return
	int* ic_info_array = new int[3];
	ic_info_array[0] = year;
	ic_info_array[1] = month;
	ic_info_array[2] = day;

	return ic_info_array;
}

/*
* This function returns the exact age (year, month, day) given birth age (year, month, day) from IC
*/
int* calculateExactAge(int* ic_info)
{
	int birth_year, birth_month, birth_day;

	// assume the person is born after 1920 and before 2020
	if(ic_info[0] <= 20)
	{
		birth_year = 2000 + ic_info[0];
	}
	else if (ic_info[0] > 20)
	{
		birth_year = 1900 + ic_info[0];
	}
	birth_month = ic_info[1];
	birth_day = ic_info[2];

	// assume the current date is 3/April/2016
	int current_year = 2016;
	int current_month = 4;
	int current_day = 3;
	int* exact_age = new int[3];
	int exact_year, exact_month, exact_day;

	// determine exact year
	if(current_month < birth_month)
	{
		exact_year = current_year - birth_year - 1;
	}
	else if(current_month > birth_month)
	{
		exact_year = current_year - birth_year;
	}
	else
	{
		if(current_day < birth_day)
		{
			exact_year = current_year - birth_year - 1;
		}
		else if(current_day >= birth_day)
		{
			exact_year = current_year - birth_year;
		}
	}

	// determine exact month (excess months)
	if(current_month < birth_month)
	{
		exact_month = 12 - birth_month + current_month;
	}
	else
	{
		exact_month = current_month - birth_month;
	}

	// determine exact day (excess days)
	if(current_day < birth_day)
	{
		// one of the month not yet fully filled
		exact_month -= 1;
		exact_day = (31 - birth_day) + current_day;
	}
	else if (current_day > birth_day)
	{
		exact_day = current_day - birth_day;
	}
	else
	{
		exact_day = 0;
	}

    // array to return
	exact_age[0] = exact_year;
	exact_age[1] = exact_month;
	exact_age[2] = exact_day;

	return exact_age;
}

/*
* This function get the state name using state code by referring to states.txt file
*/
char* getStateName(fstream &file, char* code)
{
	char* stateCode = new char[3];
	char* stateName = new char[40];
	while(file.getline(stateCode, 3, '\t'))
	{
		file.getline(stateName, 40, '\n');
		// if state code is found, return corresponding state name
		if(!strcmp(code,stateCode))
		{
			return stateName;
		}
	}
	return "";
}

// start program
int main()
{
	int numOfEmployee;
	fstream employeeData;

	// clear the file first dat file exists
	employeeData.open("employeeData.dat", ios::in | ios::binary);
	employeeData.close();

	// Question 1 a) write employee data from file using input from user
	// ask user for number of employee
	cout << "What is the number of employee?: ";
	cin >> numOfEmployee;
	cin.ignore();

	employeeData.open("employeeData.dat", ios::out | ios::binary);

	// for each employee
	for(int i=0; i<numOfEmployee; i++)
	{
		employee eachEmployee;

		// get each employee data from user
		cout << "Enter the name of employee #" << i+1 << ": ";
		cin.getline(eachEmployee.name, NAME_LENGTH);
		cout << "Enter the IC number (e.g. 920813105793) of employee #" << i+1 << ": ";
		cin.getline(eachEmployee.ic_num, IC_NUM_LENGTH);
		cout << "Enter the address1 of employee #" << i+1 << ": ";
		cin.getline(eachEmployee.address1, ADDRESS1_LENGTH);
		cout << "Enter the address2 of employee #" << i+1 << ": ";
		cin.getline(eachEmployee.address2, ADDRESS2_LENGTH);
		cout << "Enter the town of employee #" << i+1 << ": ";
		cin.getline(eachEmployee.town, TOWN_LENGTH);
		cout << "Enter the state code (e.g. 03) of employee #" << i+1 << ": ";
		cin.getline(eachEmployee.stateCode, STATECODE_LENGTH);
		cout << "Enter the monthly income (e.g. 1500) of employee #" << i+1 << ": ";
		cin.getline(eachEmployee.income, INCOME_LENGTH);

		// store each employee data into dat file
		employeeData.write(reinterpret_cast<char *>(&eachEmployee), sizeof(eachEmployee));

		cout << endl;
	}

	employeeData.close();

	// Question 1 b) read employee data from file and do some calculation

	employeeData.open("employeeData.dat", ios::in | ios::binary);

	cout << "-------------Question 1 b) i.-------------" << endl;

	int* ic_info_array = new int[3];
	int* exact_age = new int[3];
	// for each employee
	for(int i=0; i<numOfEmployee; i++)
	{
		employee eachEmployeeFromFile;
		employeeData.read(reinterpret_cast<char *>(&eachEmployeeFromFile), sizeof(eachEmployeeFromFile));

		cout << setw(10) << left << "Employee #" << i+1;

		// calculate exact age of each employee
		ic_info_array = getInfoFromIC(eachEmployeeFromFile.ic_num);
		exact_age = calculateExactAge(ic_info_array);

		// displays name and age of each employee
		cout << setw(5) << "" << setw(25) << left << eachEmployeeFromFile.name << setw(5) << "" << setw(4) << right << exact_age[0] << " years old" << endl;

		// uncomment the following line if want to print exact age
		// cout << "Exact age: " << exact_age[0] << " years " << exact_age[1] << " month " << exact_age[2]  << " days" << endl << endl;
	}

	employeeData.close();
	cout << endl;

	cout << "-------------Question 1 b) ii.-------------" << endl;

	employeeData.open("employeeData.dat", ios::in | ios::binary);

	int eachEmployeeIncome;
	char* eachEmployeeStateCode;
	char* eachEmployeeStateName;

    // for each employee
	for(int i=0; i<numOfEmployee; i++)
	{
		employee eachEmployeeFromFile;
		employeeData.read(reinterpret_cast<char *>(&eachEmployeeFromFile), sizeof(eachEmployeeFromFile));

		eachEmployeeIncome = atoi(eachEmployeeFromFile.income);
		eachEmployeeStateCode = eachEmployeeFromFile.stateCode;

		// if the employee has income less than 5000
		if(eachEmployeeIncome < 5000)
		{
			fstream stateFile;
			stateFile.open("states.txt", ios::in);

			cout << setw(10) << left << "Employee #" << i+1;

			// get state name from file using state code
			eachEmployeeStateName = getStateName(stateFile, eachEmployeeStateCode);
			// displays name and state name of each employee
			cout << setw(5) << "" << setw(25) << left << eachEmployeeFromFile.name << setw(7) << "" << setw(30) << left << eachEmployeeStateName << endl;

			stateFile.close();
		}
	}

	employeeData.close();
	cout << endl;

	cout << "-------------Question 1 b) iii.-------------" << endl;

	employeeData.open("employeeData.dat", ios::in | ios::binary);

    // for each employee
	for(int i=0; i<numOfEmployee; i++)
	{
		employee eachEmployeeFromFile;
		employeeData.read(reinterpret_cast<char *>(&eachEmployeeFromFile), sizeof(eachEmployeeFromFile));

		// displays all information of each employee
		cout << "Employee #" << i+1 << endl;
		cout << "Name: " << eachEmployeeFromFile.name << endl;
		cout << "IC number: " << eachEmployeeFromFile.ic_num << endl;
		cout << "Address1: " << eachEmployeeFromFile.address1 << endl;
		cout << "Address2: " << eachEmployeeFromFile.address2 << endl;
		cout << "Town: " << eachEmployeeFromFile.town << endl;
		cout << "State Code: " << eachEmployeeFromFile.stateCode << endl;
		cout << "Income: " << eachEmployeeFromFile.income << endl;
		cout << endl;
	}

	employeeData.close();

	return 0;
}

/* Input and Output
What is the number of employee?: 3
Enter the name of employee #1: Ling Gen Sheng Shaun
Enter the IC number (e.g. 920813105793) of employee #1: 920813105793
Enter the address1 of employee #1: A-13A-09 Blk A Apt Bayu Puteri
Enter the address2 of employee #1: No 3 Jalan Tropicana Selatan
Enter the town of employee #1: Petaling Jaya
Enter the state code (e.g. 03) of employee #1: 03
Enter the monthly income (e.g. 1500) of employee #1: 1500

Enter the name of employee #2: Abdul Baharin
Enter the IC number (e.g. 920813105793) of employee #2: 761223321032
Enter the address1 of employee #2: 13, Kampung Sungai Kayu Ara
Enter the address2 of employee #2: Jalan Petaling Street
Enter the town of employee #2: Kajang
Enter the state code (e.g. 03) of employee #2: 03
Enter the monthly income (e.g. 1500) of employee #2: 2500

Enter the name of employee #3: Teoh Kee Yen
Enter the IC number (e.g. 920813105793) of employee #3: 910112332222
Enter the address1 of employee #3: 7, Taman Dingdings
Enter the address2 of employee #3: Ayer Tawar
Enter the town of employee #3: Manjung
Enter the state code (e.g. 03) of employee #3: 14
Enter the monthly income (e.g. 1500) of employee #3: 4000

-------------Question 1 b) i.-------------
Employee #1     Ling Gen Sheng Shaun            23 years old
Employee #2     Abdul Baharin                   39 years old
Employee #3     Teoh Kee Yen                    25 years old

-------------Question 1 b) ii.-------------
Employee #1     Ling Gen Sheng Shaun            Selangor
Employee #2     Abdul Baharin                   Selangor
Employee #3     Teoh Kee Yen                    Wilayah Persekutuan Labuan

-------------Question 1 b) iii.-------------
Employee #1
Name: Ling Gen Sheng Shaun
IC number: 920813105793
Address1: A-13A-09 Blk A Apt Bayu Puteri
Address2: No 3 Jalan Tropicana Selatan
Town: Petaling Jaya
State Code: 03
Income: 1500

Employee #2
Name: Abdul Baharin
IC number: 761223321032
Address1: 13, Kampung Sungai Kayu Ara
Address2: Jalan Petaling Street
Town: Kajang
State Code: 03
Income: 2500

Employee #3
Name: Teoh Kee Yen
IC number: 910112332222
Address1: 7, Taman Dingdings
Address2: Ayer Tawar
Town: Manjung
State Code: 14
Income: 4000

*/
