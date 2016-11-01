// This program creates several instances (fruits) of class Fruit and populate them with data.
// Then, the data of each fruit is displayed.
#include <iostream>
#include "Fruit.h"
using namespace std;

int main()
{
    // create objects/ instances of class Fruit
    Fruit apple, jackfruit, banana, mango, kiwi;

    // let user enter all necessary data for each fruit
    apple.readData();
    jackfruit.readData();
    banana.readData();
    mango.readData();
    kiwi.readData();

    cout << endl;

    // display data of each fruit
    apple.displayInfo();
    jackfruit.displayInfo();
    banana.displayInfo();
    mango.displayInfo();
    kiwi.displayInfo();

    return 0;
}

/* Input and Output
Please enter the name of the fruit: apple
Please enter the price per KG (e.g. 12.25) of the fruit: 7.98
Please enter the country of origin of the fruit: Switzerland

Please enter the name of the fruit: Jackfruit
Please enter the price per KG (e.g. 12.25) of the fruit: 8.91
Please enter the country of origin of the fruit: Singapore

Please enter the name of the fruit: Banana
Please enter the price per KG (e.g. 12.25) of the fruit: 13.80
Please enter the country of origin of the fruit: Thailand

Please enter the name of the fruit: Mango
Please enter the price per KG (e.g. 12.25) of the fruit: 12.60
Please enter the country of origin of the fruit: Taiwan

Please enter the name of the fruit: Kiwi
Please enter the price per KG (e.g. 12.25) of the fruit: 20.30
Please enter the country of origin of the fruit: New Zealand


Name: apple
Price per KG: 7.98
Country of origin: Switzerland

Name: Jackfruit
Price per KG: 8.91
Country of origin: Singapore

Name: Banana
Price per KG: 13.80
Country of origin: Thailand

Name: Mango
Price per KG: 12.60
Country of origin: Taiwan

Name: Kiwi
Price per KG: 20.30
Country of origin: New Zealand
*/
