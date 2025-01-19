#include <iostream>
using namespace std;

class Debt {
private:
    double balance;
    double interestRate;

public:
    // Constructor to initialize balance and interest rate
    Debt(double initialBalance, double initialInterestRate) 
        : balance(initialBalance), interestRate(initialInterestRate) {}

    // Method to print the current balance
    void printBalance() const {
        cout << "Current Balance: " << balance << endl;
    }

    // Method to grow the debt for one year
    void waitOneYear() {
        balance *= interestRate; // Increase balance by multiplying it by interest rate
    }
};

int main() {
    // Create an instance of Debt with initial balance and interest rate
    Debt myDebt(1000.0, 1.05); // Initial balance: 1000, Interest rate: 5%

    // Print the initial balance
    myDebt.printBalance();

    // Simulate waiting for one year and print balance
    myDebt.waitOneYear();
    myDebt.printBalance();

    // Simulate waiting for another year and print balance
    myDebt.waitOneYear();
    myDebt.printBalance();

    return 0;
}
