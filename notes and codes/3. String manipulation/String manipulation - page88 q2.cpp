#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char input;
    cout << "Enter a character: ";
    cin.get(input);

    if(isspace(input))
                      cout << "You have enter a whitespace character. \n";
    if(isalpha(input))
                      cout << "You have enter an alphabetic character. \n";
    if(islower(input))
                      cout << "You have enter a lowercase letter. \n";
    if(isupper(input))
                      cout << "You have enter a uppercase letter. \n";
    if(isdigit(input))
                      cout << "You have enter a numeric digit. \n";
    if(ispunct(input))
                      cout << "You have enter a punctuation character. \n";
    if(isprint(input))
                      cout << "You have enter a printable character. \n";

    system("pause");
    return 0;
}
