#include <iostream>
#include <string>
using namespace std;

// Base class: Transaction
class Transaction {
protected:
    string transactionID;
    long long transactionAmount; // Using long long to handle large amounts

public:
    // Constructor
    Transaction(string id, long long amount) 
        : transactionID(id), transactionAmount(amount) {}

    // Get transaction details
    string getTransactionID() const { return transactionID; }
    long long getTransactionAmount() const { return transactionAmount; }

    // Set transaction details (if required for extension)
    void setTransactionID(string id) { transactionID = id; }
    void setTransactionAmount(long long amount) { transactionAmount = amount; }

    // Virtual destructor for proper cleanup in derived classes
    virtual ~Transaction() = default;
};

// Derived class: DigitCounter
class DigitCounter : public Transaction {
public:
    // Constructor inheriting from Transaction
    DigitCounter(string id, long long amount) 
        : Transaction(id, amount) {}

    // Count occurrences of a specific digit in the transaction amount
    int countOccurrences(int digit) const {
        int count = 0;
        long long amount = transactionAmount;

        while (amount > 0) {
            if (amount % 10 == digit) {
                count++;
            }
            amount /= 10;
        }
        return count;
    }
};

// Main function
int main() {
    // Create an array of 5 transaction objects
    DigitCounter transactions[] = {
        DigitCounter("T001", 12343322),
        DigitCounter("T002", 25563322),
        DigitCounter("T003", 51322233),
        DigitCounter("T004", 55512344),
        DigitCounter("T005", 45678989)
    };

    int numTransactions = 5; // Number of transactions in the array
    char choice = 'y';
    const int threshold = 3; // Predefined threshold for flagging

    do {
        int digit;
        cout << "Choose a digit to inspect: ";
        cin >> digit;

        cout << "\nOutput:\n";
        bool flagged = false;

        // Process each transaction and check the occurrences of the digit
        for (int i = 0; i < numTransactions; i++) {
            int occurrences = transactions[i].countOccurrences(digit);

            if (occurrences > threshold) {
                cout << "REVIEW REQUIRED\n";
                cout << transactions[i].getTransactionAmount() << endl;
                flagged = true;
            }
        }

        if (!flagged) {
            cout << "No transactions flagged for REVIEW.\n";
        }

        // Prompt for another digit inspection
        cout << "\nWould you like to inspect another digit? (y/n): ";
        cin >> choice;
        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    cout << "Audit system exiting. Goodbye!\n";
    return 0;
}
