#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Base class Account
class Account {
protected:
    string accountHolderName;
    double balance;

public:
    // Constructor
    Account(string name, double initialBalance)
        : accountHolderName(name), balance(initialBalance) {}

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " to " << accountHolderName << "'s account." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw method
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << " from " << accountHolderName << "'s account." << endl;
        } else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    // Display method
    virtual void display() const {
        cout << "Account Holder: " << accountHolderName << ", Balance: " << balance << endl;
    }

    // Getter for balance
    double getBalance() const {
        return balance;
    }

    // Getter for account holder name
    string getAccountHolderName() const {
        return accountHolderName;
    }

    virtual ~Account() = default; // Virtual destructor for proper cleanup
};

// Savings Account
class Savings : public Account {
private:
    double interestRate;

public:
    Savings(string name, double initialBalance, double rate)
        : Account(name, initialBalance), interestRate(rate) {}

    // Calculate interest
    void calculateInterest() const {
        double interest = balance * interestRate;
        cout << "Interest for " << accountHolderName << ": " << interest << endl;
    }

    // Display details
    void display() const override {
        cout << "Savings Account - ";
        Account::display();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

// Current Account
class Current : public Account {
private:
    double minimumBalance;

public:
    Current(string name, double initialBalance, double minBalance)
        : Account(name, initialBalance), minimumBalance(minBalance) {}

    // Check if balance meets the minimum requirement
    void checkMinimumBalance() const {
        if (balance < minimumBalance) {
            cout << accountHolderName << "'s account is below the minimum balance of " << minimumBalance << endl;
        } else {
            cout << accountHolderName << "'s account meets the minimum balance requirement." << endl;
        }
    }

    // Display details
    void display() const override {
        cout << "Current Account - ";
        Account::display();
        cout << "Minimum Balance: " << minimumBalance << endl;
    }
};

// Fixed Deposit Account
class FixedDeposit : public Account {
private:
    int maturityPeriod; // in years
    double interestRate;

public:
    FixedDeposit(string name, double initialBalance, int period, double rate)
        : Account(name, initialBalance), maturityPeriod(period), interestRate(rate) {}

    // Calculate maturity amount
    void calculateMaturityAmount() const {
        double maturityAmount = balance * pow((1 + interestRate), maturityPeriod);
        cout << "Maturity Amount for " << accountHolderName << " after " << maturityPeriod << " years: " << maturityAmount << endl;
    }

    // Display details
    void display() const override {
        cout << "Fixed Deposit Account - ";
        Account::display();
        cout << "Maturity Period: " << maturityPeriod << " years, Interest Rate: " << interestRate << endl;
    }
};

// Function to get low balance accounts
Account** getLowBalanceAccounts(Account* accounts[], int size, double threshold, int& lowBalanceCount) {
    // Create a dynamic array to store low balance accounts
    Account** lowBalanceAccounts = new Account*[size];
    lowBalanceCount = 0;

    for (int i = 0; i < size; i++) {
        if (accounts[i]->getBalance() < threshold) {
            lowBalanceAccounts[lowBalanceCount++] = accounts[i];
        }
    }

    return lowBalanceAccounts;
}

int main() {
    // Create instances of each account type
    Savings savingsAccount("Alice", 5000, 0.05);
    Current currentAccount("Bob", 2000, 1000);
    FixedDeposit fdAccount("Charlie", 10000, 5, 0.07);

    // Create an array of accounts
    Account* accounts[] = {&savingsAccount, &currentAccount, &fdAccount};
    int size = sizeof(accounts) / sizeof(accounts[0]);

    // Demonstrate functionality
    cout << "Displaying all accounts:\n";
    for (int i = 0; i < size; i++) {
        accounts[i]->display();
        cout << endl;
    }

    cout << "\nPerforming specific operations:\n";
    savingsAccount.calculateInterest();
    currentAccount.checkMinimumBalance();
    fdAccount.calculateMaturityAmount();

    // Find low balance accounts
    int lowBalanceCount = 0;
    Account** lowBalanceAccounts = getLowBalanceAccounts(accounts, size, 3000, lowBalanceCount);

    cout << "\nAccounts with balance less than 3000:\n";
    for (int i = 0; i < lowBalanceCount; i++) {
        lowBalanceAccounts[i]->display();
        cout << endl;
    }

    // Clean up dynamic memory
    delete[] lowBalanceAccounts;

    // Search for an account by name
    string searchName = "Alice";
    cout << "\nSearching for account holder: " << searchName << endl;
    for (int i = 0; i < size; i++) {
        if (accounts[i]->getAccountHolderName() == searchName) {
            accounts[i]->display();
        }
    }

    return 0;
}
