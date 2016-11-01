// This is the second part of page 166, question 1.
// Borrow codes from part 1, and added printBalance to display the balance.
#include <iostream>
#include <iomanip>
using namespace std;

class SavingsAccount
{
    static double annualInterestRate;
    double savingBalance;
    public:
        SavingsAccount(double balance)
        {
            savingBalance = balance;
        }
        void calculateMonthlyInterest()
        {
            double monthlyInterest;
            monthlyInterest = savingBalance * annualInterestRate / 12.0;
            savingBalance += monthlyInterest;
        }
        static void modifyInterestRate(double newInterestRate)
        {
            annualInterestRate = newInterestRate;
        }
        void printBalance()
        {
            cout << "The balance is: RM" << fixed << setprecision(2) << savingBalance << endl;
        }
};

double SavingsAccount::annualInterestRate = 0.03;

int main()
{
    // i. set the saver1 and saver2 objects' balance to RM2000.00 and RM3000.00 respectively
    SavingsAccount saver1(2000.00), saver2(3000.00);

    // ii. set the annual interest rate to 3% (before the main function), then calculate monthly interest and new balances for saver1 and saver2
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    saver1.printBalance();
    saver2.printBalance();

    // iii. set the new annual interest rate to 4%, then calculate monthly interest and new balances for saver1 and saver2
    SavingsAccount::modifyInterestRate(0.04);
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    saver1.printBalance();
    saver2.printBalance();

    return 0;
}

/* Output
The balance is: RM2005.00
The balance is: RM3007.50
The balance is: RM2011.68
The balance is: RM3017.53
*/
