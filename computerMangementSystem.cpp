#include <iostream>
#include <string>
using namespace std;

class Computer {
private:
    string brand;
    string processor;
    int ram;

public:
    // Constructor 1: Initializes all fields
    Computer(string compBrand, string compProcessor, int compRam) 
        : brand(compBrand), processor(compProcessor), ram(compRam) {}

    // Constructor 2: Initializes brand and processor, sets RAM to 8
    Computer(string compBrand, string compProcessor) 
        : brand(compBrand), processor(compProcessor), ram(8) {}

    // Getter for RAM
    int getRam() const {
        return ram;
    }

    // Method to get an array of computers with RAM >= given size
    static Computer* getComputersWithRam(Computer computers[], int size, int ramSize, int& resultCount) {
        // Create a temporary dynamic array to store results
        Computer* result = new Computer[size];
        resultCount = 0;

        // Filter computers based on RAM size
        for (int i = 0; i < size; i++) {
            if (computers[i].getRam() >= ramSize) {
                result[resultCount++] = computers[i];
            }
        }

        return result;
    }

    // Display method for testing
    void display() const {
        cout << "Brand: " << brand << ", Processor: " << processor << ", RAM: " << ram << " GB" << endl;
    }
};

int main() {
    // Create an array of Computer objects
    Computer computers[] = {
        Computer("Dell", "Intel i5", 16),
        Computer("HP", "AMD Ryzen 5", 8),
        Computer("Apple", "M1", 32),
        Computer("Lenovo", "Intel i3", 4)
    };
    int size = sizeof(computers) / sizeof(computers[0]);

    // Find computers with RAM >= 8
    int resultCount = 0;
    Computer* filteredComputers = Computer::getComputersWithRam(computers, size, 8, resultCount);

    // Display the filtered computers
    cout << "Computers with RAM >= 8 GB:\n";
    for (int i = 0; i < resultCount; i++) {
        filteredComputers[i].display();
    }

    // Clean up dynamic memory
    delete[] filteredComputers;

    return 0;
}

