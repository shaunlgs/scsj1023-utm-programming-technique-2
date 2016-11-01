// This program contains two classes, House, and Room. This is a fixed aggregation shown by a solid diamond.
// Each house can have many rooms.
// This program will create some houses, and rooms. Each house will have several rooms.
// Then, the address of house and name of each rooms will be printed on screen.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Room
{
    private:
        string name;
    public:
        Room();
        Room(string);
        string getName() const
        {
            return name;
        }
};

class House
{
    private:
        // vector to store rooms
        vector<Room> roomType;
        string address;
    public:
        House(int, string);
        // sets the rooms by accepting vector of rooms
        void setRoom(vector<Room>);
        // print address of the house and name of each rooms
        void print();
};

Room::Room()
{

}

// This is the constructor of class Room.
// The constructor accepts the name of the room and set the name of the room.
Room::Room(string name)
{
    this->name = name;
}

// This is the constructor of class House.
// The constructor accepts the number of rooms the house has and the house address.
// The number of room is used to resize the vector roomType so that it knows how many rooms to store.
// Address is set.
House::House(int numRoom, string address)
{
    roomType.resize(numRoom);
    this->address = address;
}

// setRoom() is a member function of class House.
// The function accepts a vector of Room, and assign it to vector roomType.
void House::setRoom(vector<Room> roomVector)
{
    this->roomType = roomVector;
}

// print() is a member function of class House.
// The function prints the address of the house,
// and the name of each room the house has.
void House::print()
{
    cout << "Address: " << address << endl;
    cout << endl;
    for(int i=0; i<roomType.size(); i++)
    {
        cout << "Room #" << i+1 << ": ";
        cout << roomType[i].getName() << endl;
    }
    cout << endl;
    cout << "---------------------------------------------" << endl;
}

int main()
{
    // create six rooms
    Room firstRoom = Room("Garage");
    Room secondRoom = Room("Living room");
    Room thirdRoom = Room("Kitchen");
    Room fourthRoom = Room("Shower");
    Room fifthRoom = Room("Dining room");
    Room sixthRoom = Room("Drawing room");

    // rooms are stored in room vector, roomVector1 or roomVector2
    // vector is used instead of array because vector gives the number of elements, this helps in printing.
    // Also, they can automatically increase size when the vector is full.
    vector<Room> roomVector1;
    roomVector1.push_back(fifthRoom);
    roomVector1.push_back(secondRoom);
    roomVector1.push_back(thirdRoom);
    roomVector1.push_back(fourthRoom);
    vector<Room> roomVector2;
    roomVector2.push_back(firstRoom);
    roomVector2.push_back(sixthRoom);

    // create two houses
    House firstHouse = House(4, "A-13A-09 Blk A Apt Bayu Puteri, No 3, Jalan Tropicana Selatan, PJU 3, Petaling Jaya");
    House secondHouse = House(2, "19, Bandar Utama 2/5, 47800, Petaling Jaya");

    // assign the rooms to each house
    firstHouse.setRoom(roomVector1);
    secondHouse.setRoom(roomVector2);

    // print the information of house, and the name of room they have
    firstHouse.print();
    secondHouse.print();


    return 0;
}

/* Output
Address: A-13A-09 Blk A Apt Bayu Puteri, No 3, Jalan Tropicana Selatan, PJU 3, P
etaling Jaya

Room #1: Dining room
Room #2: Living room
Room #3: Kitchen
Room #4: Shower

---------------------------------------------
Address: 19, Bandar Utama 2/5, 47800, Petaling Jaya

Room #1: Garage
Room #2: Drawing room

---------------------------------------------

*/
