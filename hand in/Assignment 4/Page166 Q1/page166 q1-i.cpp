// This program is taken from "Programming Techniques II (C++), Fourth Edition, 2015" by Faculty of Computing, Universiti Teknologi Malaysia, page 166, question 1, two parts.
// Second part is in another .cpp file.
#include <iostream>
using namespace std;

class SavingsAccount
{
    // i. static member variable of type double
    // to store annual interest rate in decimal (e.g. 0.03 which is equivalent to 3%)
    static double annualInterestRate;
    // ii. the balance the account currently has
    double savingBalance;
    public:
        // iii. this function determines the monthly interest gained by multiplying 1/12 of the annual interest rate by the balance
        // the new balance is updated
        void calculateMonthlyInterest()
        {
            double monthlyInterest;
            monthlyInterest = savingBalance * annualInterestRate / 12.0;
            savingBalance += monthlyInterest;
        }
        // iv. sets a new annual interest rate
        // this is a static function because it accesses a static member variable
        static void modifyInterestRate(double newInterestRate)
        {
            annualInterestRate = newInterestRate;
        }
};
