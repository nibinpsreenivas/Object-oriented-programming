#include <iostream>
using namespace std;

class Triangle {
private:
    double side1;
    double side2;
    double side3;

public:
    // Constructor to initialize the sides of the triangle
    Triangle(double s1, double s2, double s3) 
        : side1(s1), side2(s2), side3(s3) {}

    // Function to check if the triangle is equilateral
    bool isEquilateral() const {
        return (side1 == side2 && side2 == side3);
    }

    // Function to check if the triangle is isosceles
    bool isIsosceles() const {
        return (side1 == side2 || side1 == side3 || side2 == side3) && !isEquilateral();
    }

    // Function to check if the triangle is scalene
    bool isScalene() const {
        return (side1 != side2 && side1 != side3 && side2 != side3);
    }

    // Display the type of triangle
    void displayTriangleType() const {
        if (isEquilateral()) {
            cout << "The triangle is equilateral." << endl;
        } else if (isIsosceles()) {
            cout << "The triangle is isosceles." << endl;
        } else if (isScalene()) {
            cout << "The triangle is scalene." << endl;
        } else {
            cout << "Invalid triangle." << endl;
        }
    }
};

int main() {
    // Input sides of the triangle
    double a, b, c;
    cout << "Enter the lengths of the three sides of the triangle: ";
    cin >> a >> b >> c;

    // Create a Triangle object
    Triangle triangle(a, b, c);

    // Display the type of triangle
    triangle.displayTriangleType();

    return 0;
}
