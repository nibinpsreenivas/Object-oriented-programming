public class Debt {
    // Instance variables
    private double balance;
    private double interestRate;

    // Constructor
    public Debt(double initialBalance, double initialInterestRate) {
        this.balance = initialBalance;
        this.interestRate = initialInterestRate;
    }

    // Method to print the current balance
    public void printBalance() {
        System.out.printf("Current balance: %.2f%n", balance);
    }

    // Method to grow the debt after one year
    public void waitOneYear() {
        balance *= interestRate; // Increase balance by multiplying with interest rate
    }

    // Main method to demonstrate functionality
    public static void main(String[] args) {
        // Create a Debt object
        Debt myDebt = new Debt(1000.00, 1.05); // Initial balance: 1000, Interest rate: 5%

        // Print the initial balance
        myDebt.printBalance();

        // Simulate growth of debt over 3 years
        for (int i = 1; i <= 3; i++) {
            myDebt.waitOneYear();
            System.out.print("After year " + i + ": ");
            myDebt.printBalance();
        }
    }
}
