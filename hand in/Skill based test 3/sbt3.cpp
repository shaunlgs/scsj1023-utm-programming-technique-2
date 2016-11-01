////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 2, 2015/2016
// Skill-Based Test 3
// 18 May 2016
////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>

using namespace std;

class Contact{
    private:
        string owner;
        string phone;
    public:
    	Contact();
    	string getOwner() const;
    	void setOwner(string _owner); 
    	string getPhone() const;
    	void setPhone(string _phone);
};

class Car{
    protected:
            string plateNumber;
            string model;
    public:
    	Car();
    	string getPlateNumber() const;
    	void setPlateNumber( string _plateNumber);
    	string getModel() const;
    	void setModel( string _model);
};

class SaleCar:public Car {
    private:
        double price;
        Contact contact;
    public:
    	SaleCar();
    	double getPrice() const;
    	void setPrice( double _price);
		Contact getContact() const;
		void setContact( Contact _contact);
};

class RentalCar:public Car {  
    private:
        double dailyRate;  
        double hourlyRate; 
    public:
    	RentalCar();
    	double getDailyRate() const;
    	void setDailyRate( double _rate);
    	double getHourlyRate() const;
    	void setHourlyRate( double _rate);
    	void print() const;

};

// Function prototypes for searching for a car from a list
//  The defintion of each function is given at the end of the program
int searchSaleCar(string, const SaleCar[], int);
int searchRentalCar(string, const RentalCar[], int);


// Task 1: Complete the definition of function readSaleCars. This function reads the list of cars for sale from a text file.
//         Parameters:
//         		fileName is the name of the input file
//         		cars is the array of cars read
//         		count is the number of cars read
//                                                                                              (7 marks)
  
void readSaleCars(string fileName, SaleCar cars[], int &count)
{
	ifstream fin(fileName.c_str());
	count = 0;
	
	string plateNumber, model;
	double price;
	string contactName, contactPhone;
	
	fin.ignore(1000,'\n'); // To skip the header (i.e., the first line)
	
	while ( getline(fin,plateNumber,',') ){

		getline(fin,model,',');
		fin >> price; fin.ignore();
		getline(fin,contactName,',');
		getline(fin,contactPhone);
		
		// Write your answer starting from here
		cars[count].setPlateNumber(plateNumber);
		cars[count].setModel(model);
		cars[count].setPrice(price);
		Contact temp;
		temp.setOwner(contactName);
		temp.setPhone(contactPhone);
		cars[count].setContact(temp);






	
		count++;
	}
	fin.close();
}


// Task 2: Complete the definition of function readRentalCars. This function reads the list of cars for rental from a text file.
//         Parameters:
//         		fileName is the name of the input file
//         		cars is the array of cars read
//         		count is the number of cars read
//                                                                                              (4 marks)

void readRentalCars(string fileName, RentalCar cars[], int &count)
{
	ifstream fin(fileName.c_str());
	count = 0;
	
	string plateNumber, model;
	double dailyRate, hourlyRate;

	fin.ignore(1000,'\n'); // To skip the header (i.e., the first line)	
	
	while ( getline(fin,plateNumber,',') ){

		getline(fin,model,',');
		fin >> dailyRate; fin.ignore();
		fin >> hourlyRate; fin.ignore();
		
		// Write your answer starting from here
		cars[count].setPlateNumber(plateNumber);
		cars[count].setModel(model);
		cars[count].setDailyRate(dailyRate);
		cars[count].setHourlyRate(hourlyRate);



			
		count++;
	}
	fin.close();
}


int main()
{
    SaleCar saleCars[100];              // To hold the list of cars for sale
    RentalCar mpvRentalCars[100];       // To hold the list MPV cars for rental
    RentalCar regularRentalCars[100];   // To hold the list regular cars for rental
    
    int nSaleCars;                      // The number of cars for sale
    int mpvCount;                       // The number of MPV cars for rental
    int regularCount;                   // The number of regular cars for rental
    string plateNumber;                 // The plate number of the car to search for
    
    
	// Task 3: Read the list of cars for sale from the file "sale_car.txt" and store them into the array saleCars.    (2 marks)
	string saleFileName = "sale_car.txt";
	readSaleCars(saleFileName, saleCars, nSaleCars);
	
	// Task 4: Read the list of MPV cars for rental from the file "rental_mpv.txt" and store them into the array mpvRentalCars.   (2 marks)
	string rentalMPVFileName = "rental_mpv.txt";
	readRentalCars(rentalMPVFileName, mpvRentalCars, mpvCount);
	
	// Task 5: Read the list of regular cars for rental from the file "rental_regular.txt" and store them into the array regularRentalCars. (2 marks)
	string rentalRegularFileName = "rental_regular.txt";
	readRentalCars(rentalRegularFileName, regularRentalCars, regularCount);
	
    
	cout << "Enter the plate number of the car to search for => ";
    cin >> plateNumber;
       
	cout << endl;
    
    // Task 6: Search for a car (using its plate number) in the the three lists.
    //          If the searched car is found, print in which list the car belongs to (i.e., list of cars for sale,
	//             list of mpv cars for rental or list of regular cars for rental)
	//          Also, if car is for sale, print the model and the owner of the car.
	//          If the car is for rental (i.e., either mpv or regular cars for rental), print all the information of the car
	//          However, if there is no car found, prompt the user with an appropriate messeage.
	//          See text in the question for example output.
	//                                                                                              (18 marks)
	
	// search if the car is in list of cars for sale
	int index;
	bool found = false;
	index = searchSaleCar(plateNumber,saleCars, nSaleCars);
	
	if(index != -1)
	{
		cout << "The car is in the list of cars for sale." << endl;
		// if the car is for sale, print the model and owner of the car
		cout << "Model : " << saleCars[index].getModel() << endl;
		cout << "Owner : " << saleCars[index].getContact().getOwner() << endl;
		found = true;
	}
	
	// search if the car is in list of mpv cars for rental
	index = searchRentalCar(plateNumber,mpvRentalCars, mpvCount);
	if(index != -1)
	{
		cout << "The car is in the list of mpv cars for rental." << endl;
		// if the car is for rental, print all the information of the car
		mpvRentalCars[index].print();
		found = true;
	}
	
	// search if the car is in list of regular cars for rental
	index = searchRentalCar(plateNumber,regularRentalCars, regularCount);
	if(index != -1)
	{
		cout << "The car is in the list of regular cars for rental." << endl;
		// if the car is for rental, print all the information of the car
		regularRentalCars[index].print();
		found = true;
	}
	
	// however, if car is not found, prompt user
	if(!found)
	{
		cout << "The car is not found." << endl;
	}










    
	return 0;
}



//--------------------------------------------------------------------------------------------	
// Definition of Class Contact

Contact::Contact()
{
	owner = phone = "";
}
    	
string Contact::getOwner() const
{ 
	return owner; 
}

void Contact::setOwner(string _owner)
{ 
	owner = _owner;
} 

string Contact::getPhone() const 
{ 
	return phone;
}

void Contact::setPhone(string _phone)
{
	phone = _phone;
} 
//--------------------------------------------------------------------------------------------	


//--------------------------------------------------------------------------------------------	
// Definition of Class Car

Car::Car()
{
	plateNumber = model = "";
}
    	
string Car::getPlateNumber() const 
{ 
	return plateNumber;
}
    	
void Car::setPlateNumber(string _plateNumber)
{ 
	plateNumber = _plateNumber;
} 

string Car::getModel() const 
{ 
	return model;
}

void Car::setModel(string _model)
{ 
	model = _model;
} 
//--------------------------------------------------------------------------------------------	


//--------------------------------------------------------------------------------------------	
// Definition of class SaleCar

SaleCar::SaleCar():Car()
{
	price = 0;
}
    	
double SaleCar::getPrice() const 
{ 
	return price;
}

void SaleCar::setPrice (double _price)
{ 
	price = _price;
} 
    	
Contact SaleCar::getContact() const 
{ 
	return contact;
}

void SaleCar::setContact(Contact _contact)
{ 
	contact = _contact;
} 
//--------------------------------------------------------------------------------------------	



	
//--------------------------------------------------------------------------------------------	
// Definition of class RentalCar

RentalCar::RentalCar( ):Car()
{
	dailyRate = hourlyRate = 0;
}
    	
double RentalCar::getDailyRate() const
{ 
	return dailyRate;
}

void RentalCar::setDailyRate(double _rate)
{ 
	dailyRate = _rate;
} 
    	
double RentalCar::getHourlyRate() const 
{ 
	return hourlyRate;
}

void RentalCar::setHourlyRate(double _rate)
{ 
	hourlyRate = _rate;
} 

void RentalCar::print() const
{
	cout << "Plate Number: " << plateNumber << endl;
	cout << "Model       : " << model << endl;
	cout << "Daily Rate  : RM " << dailyRate << endl;
	cout << "Hourly Rate : RM " << hourlyRate << endl;
}		
//--------------------------------------------------------------------------------------------	
    	

//--------------------------------------------------------------------------------------------
// Definitions for the searching functions

// The function 'searchSaleCar' searches for a car (given by its 'plateNumber') in a list of SaleCar objects.
//    A car is found when the plate number has a match in the list. 
//    Parameters:
//        		plateNumber is the plate number of the car to search for
//         		cars is the list of SaleCar objects to search from
//         		count is the number of cars of the list
//    Return value: 
//				if the searched car is found in the list, the function returns the index of the object of the found car
//              otherwise, it returns -1 (indicating no car is found)

int searchSaleCar(string plateNumber, const SaleCar cars[], int count)
{
	for (int i=0; i<count; i++){
		if (plateNumber == cars[i].getPlateNumber() ) return i;
	}
	
	return -1;
}


// The function 'searchRentalCar' searches for a car (given by its 'plateNumber') in a list of RentalCar objects.
//    A car is found when the plate number has a match in the list. 
//    Parameters:
//         		plateNumber is the plate number of the car to search for
//         		cars is the list of SaleCar objects to search from
//         		count is the number of cars of the list
//    Return value: 
//				if the searched car is found in the list, the function returns the index of the object of the found car
//              otherwise, it returns -1 (indicating no car is found)

int searchRentalCar(string plateNumber, const RentalCar cars[], int count)
{
	for (int i=0; i<count; i++){
		if (plateNumber == cars[i].getPlateNumber() ) return i;
	}
	
	return -1;
}
//--------------------------------------------------------------------------------------------




