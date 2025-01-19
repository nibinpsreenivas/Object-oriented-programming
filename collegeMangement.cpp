#include <iostream>
#include <string>
using namespace std;

// Maximum number of students in a course
const int MAX_STUDENTS = 100;

// Student class definition
class Student {
private:
    string studentName;
    string studentID;
    string major;

public:
    // Constructor 1: Initialize all fields
    Student(string name, string id, string majorField) 
        : studentName(name), studentID(id), major(majorField) {}

    // Constructor 2: Initialize name and ID, default major to "Undeclared"
    Student(string name, string id) 
        : studentName(name), studentID(id), major("Undeclared") {}

    // Default constructor
    Student() : studentName(""), studentID(""), major("Undeclared") {}

    // Getters
    string getName() const { return studentName; }
    string getID() const { return studentID; }
    string getMajor() const { return major; }
};

// Course class definition
class Course {
private:
    string courseName;
    string courseCode;
    string instructorName;
    Student students[MAX_STUDENTS];
    int studentCount;

public:
    // Constructor: Initialize course details
    Course(string name, string code, string instructor) 
        : courseName(name), courseCode(code), instructorName(instructor), studentCount(0) {}

    // Add a student to the course
    void addStudent(const Student& student) {
        if (studentCount < MAX_STUDENTS) {
            students[studentCount++] = student;
        } else {
            cout << "Course is full. Cannot add more students.\n";
        }
    }

    // Method to get all undeclared students
    void getUndeclaredStudents(Student undeclared[], int& count) const {
        count = 0;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getMajor() == "Undeclared") {
                undeclared[count++] = students[i];
            }
        }
    }

    // Method to search for a student by ID
    Student* searchStudent(const string& id) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getID() == id) {
                return &students[i];
            }
        }
        return nullptr;
    }

    // Display course details
    void displayCourseDetails() const {
        cout << "Course: " << courseName << " (" << courseCode << ")\n";
        cout << "Instructor: " << instructorName << "\n";
        cout << "Enrolled Students:\n";
        for (int i = 0; i < studentCount; i++) {
            cout << "- " << students[i].getName() << " (ID: " << students[i].getID() 
                 << ", Major: " << students[i].getMajor() << ")\n";
        }
    }
};

int main() {
    // Create a course instance
    Course course("Intro to Programming", "CS101", "Dr. Jones");

    // Create student instances
    Student student1("Alice", "S001", "Computer Science");
    Student student2("Bob", "S002");
    Student student3("Charlie", "S003", "Mathematics");

    // Add students to the course
    course.addStudent(student1);
    course.addStudent(student2);
    course.addStudent(student3);

    // Display course details
    course.displayCourseDetails();

    // Get undeclared students
    cout << "\nUndeclared Students:\n";
    Student undeclared[MAX_STUDENTS];
    int undeclaredCount = 0;
    course.getUndeclaredStudents(undeclared, undeclaredCount);
    for (int i = 0; i < undeclaredCount; i++) {
        cout << "- " << undeclared[i].getName() << " (ID: " << undeclared[i].getID() << ")\n";
    }

    // Search for a student by ID
    string searchID = "S002";
    Student* foundStudent = course.searchStudent(searchID);
    if (foundStudent) {
        cout << "\nStudent Found:\n";
        cout << foundStudent->getName() << " (ID: " << foundStudent->getID() 
             << ", Major: " << foundStudent->getMajor() << ")\n";
    } else {
        cout << "\nStudent with ID " << searchID << " not found.\n";
    }

    return 0;
}
