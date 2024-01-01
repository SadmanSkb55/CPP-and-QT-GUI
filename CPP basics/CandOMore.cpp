#include<iostream>
#include<string>
using namespace std;
class Shape{//abstraction
    public:
    virtual double calculateArea() const = 0;//abstraction keyword virtual for a function
    void display() const {
        std::cout << "This is a shape." << std::endl;
    }
};
class Circle : public Shape {//inheritance
private://encapsulation
    double radius;

public://encapsulation
    Circle(double r) : radius(r) {}
    double calculateArea() const override {//overriden //run time polymorphsism overriden virtual function 
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() const override {
        return length * width;
    }
};

class MathOperations {//compile time polymormphsism
public:
    int add(int a, int b) {//function overloading go brrrrrrr
        return a + b;
    }
    int add(int a, int b, int c) {//function overloading go brrrrrrr
        return a + b + c;
    }
    double add(double a, double b) {//function overloading go brrrrrrr
        return a + b;
    }
};

class Student {
public:
    std::string name;
    int age;
    // Constructor
    Student(const std::string& n, int a) : name(n), age(a) {}
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};
// Function that takes a Student object by value
void displayStudentByValue(Student student) {
    std::cout << "Inside displayStudentByValue function:" << std::endl;
    student.display();
}
// Function that takes a Student object by reference
void displayStudentByReference(const Student& student) {
    std::cout << "Inside displayStudentByReference function:" << std::endl;
    student.display();
}
// Function that takes an array of Student objects
void displayStudentArray(const Student students[], int size) {
    std::cout << "Inside displayStudentArray function:" << std::endl;
    for (int i = 0; i < size; ++i) {
        students[i].display();
    }
}

int main(){
    Student student1("Alice", 20);
    Student student2("Bob", 22);

    // Passing objects to functions
    displayStudentByValue(student1);
    displayStudentByReference(student2);

    // Creating an array of Student objects
    const int arraySize = 3;
    Student studentArray[arraySize] = {
        {"Charlie", 19},
        {"David", 21},
        {"Eva", 23}
};
displayStudentArray(studentArray, arraySize);

Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    // Array of pointers to the base class
    Shape* shapes[] = {&circle, &rectangle};
    for (const auto shape : shapes) {
        shape->display();
        std::cout << "Area: " << shape->calculateArea() << std::endl;
    }

MathOperations math;

    std::cout << math.add(2, 3) << std::endl;           
    std::cout << math.add(2, 3, 4) << std::endl;       
    std::cout << math.add(2.5, 3.5) << std::endl;  



    return 0;
}