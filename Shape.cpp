#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Abstract Base Class
class Shape {
public:
    // Virtual Destructor
    virtual ~Shape() {}

    // Pure virtual function for getting the area
    virtual int getArea() = 0;

    // Pure virtual function to get the shape type
    virtual string getShapeType() = 0;

    // Pure virtual function to check if two shapes are equal
    virtual bool isEqual(Shape* other) = 0;
};

// Derived Class Rectangle
class Rectangle : public Shape {
private:
    int length;
    int width;

public:
    // Parameterized constructor
    Rectangle(int l, int w) : length(l), width(w) {}

    // Implementing getArea for Rectangle
    int getArea() override {
        return length * width;
    }

    // Implementing getShapeType for Rectangle
    string getShapeType() override {
        return "Rectangle";
    }

    // Implementing isEqual to compare two Rectangle objects
    bool isEqual(Shape* other) override {
        Rectangle* rect = dynamic_cast<Rectangle*>(other);
        if (rect != nullptr) {
            return (this->length == rect->length && this->width == rect->width);
        }
        return false;
    }
};

// Derived Class Circle
class Circle : public Shape {
private:
    int radius;

public:
    // Parameterized constructor
    Circle(int r) : radius(r) {}

    // Implementing getArea for Circle
    int getArea() override {
        return static_cast<int>(M_PI * radius * radius); // Using M_PI for pi
    }

    // Implementing getShapeType for Circle
    string getShapeType() override {
        return "Circle";
    }

    // Implementing isEqual to compare two Circle objects
    bool isEqual(Shape* other) override {
        Circle* circ = dynamic_cast<Circle*>(other);
        if (circ != nullptr) {
            return this->radius == circ->radius;
        }
        return false;
    }
};

// Derived Class Square
class Square : public Shape {
private:
    int side;

public:
    // Parameterized constructor
    Square(int s) : side(s) {}

    // Implementing getArea for Square
    int getArea() override {
        return side * side;
    }

    // Implementing getShapeType for Square
    string getShapeType() override {
        return "Square";
    }

    // Implementing isEqual to compare two Square objects
    bool isEqual(Shape* other) override {
        Square* sq = dynamic_cast<Square*>(other);
        if (sq != nullptr) {
            return this->side == sq->side;
        }
        return false;
    }
};

// Main function
int main() {
    // Create instances of Rectangle, Circle, and Square
    Rectangle rect(5, 10);
    Circle circ(7);
    Square sq(5);

    // Displaying areas and shape types
    cout << "Shape: " << rect.getShapeType() << ", Area: " << rect.getArea() << endl;
    cout << "Shape: " << circ.getShapeType() << ", Area: " << circ.getArea() << endl;
    cout << "Shape: " << sq.getShapeType() << ", Area: " << sq.getArea() << endl;

    // Checking equality of two shapes
    Shape* shape1 = new Rectangle(5, 10);
    Shape* shape2 = new Rectangle(5, 10);
    Shape* shape3 = new Circle(7);

    cout << "\nAre shape1 and shape2 equal? " << (shape1->isEqual(shape2) ? "Yes" : "No") << endl;
    cout << "Are shape1 and shape3 equal? " << (shape1->isEqual(shape3) ? "Yes" : "No") << endl;

    // Clean up
    delete shape1;
    delete shape2;
    delete shape3;

    return 0;
}
