#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

class Course {
public:
    string code;
    string name;
    int credits;
    Course* next;

    Course(string c, string n, int cr) : code(c), name(n), credits(cr), next(nullptr) {}
};

class Department {
public:
    Course* head;

    Department() : head(nullptr) {}

    void addCourse(string code, string name, int credits) {
        Course* newCourse = new Course(code, name, credits);
        newCourse->next = head;
        head = newCourse;
    }

    void showCourses() {
        Course* current = head;
        while (current) {
            cout << current->code << " " << current->name << " " << current->credits << "cr" << endl;
            current = current->next;
        }
    }

    void removeCourse(string code) {
        Course* current = head;
        Course* previous = nullptr;
        while (current) {
            if (current->code == code) {
                if (previous) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << "Course not found!" << endl;
    }
};

class University {
public:
    unordered_map<string, Department> departments;

    University() {
        // Initialize departments
        departments["ARC"];
        departments["CSE"];
        departments["EEE"];
        departments["LAW"];
        departments["MAT"];
        departments["ENG"];
        departments["GED"];
    }

    void addCourseToDepartment(string department, string code, string name, int credits) {
        if (departments.find(department) != departments.end()) {
            departments[department].addCourse(code, name, credits);
        } else {
            cout << "Department not found!" << endl;
        }
    }

    void showAllCourses() {
        for (auto& dept : departments) {
            cout << dept.first << " Courses:" << endl;
            dept.second.showCourses();
            cout << endl;
        }
    }

    void showSpecificCourses(string department) {
        if (departments.find(department) != departments.end()) {
            cout << department << " Courses:" << endl;
            departments[department].showCourses();
        } else {
            cout << "Department not found!" << endl;
        }
    }

    void removeCourse(string department, string code) {
        if (departments.find(department) != departments.end()) {
            departments[department].removeCourse(code);
        } else {
            cout << "Department not found!" << endl;
        }
    }

    void loadCoursesFromFile(string filename) {
        ifstream file(filename);
        string line, code, name, creditStr;
        int credits;

        while (getline(file, line)) {
            stringstream ss(line);
            ss >> code;
            ss.ignore();
            getline(ss, name, ' ');
            ss >> creditStr;
            credits = stoi(creditStr.substr(0, creditStr.size() - 2));

            string deptCode = code.substr(0, 3);
            addCourseToDepartment(deptCode, code, name, credits);
        }
        file.close();
    }
};

int main() {
    University uni;
    uni.loadCoursesFromFile("courses.txt");

    int choice;
    string department, code, name;
    int credits;

    do {
        cout << "1. Show All Courses\n2. Show Specific Department Courses\n3. Add Course\n4. Remove Course\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            uni.showAllCourses();
            break;
        case 2:
            cout << "Enter Department Code: ";
            cin >> department;
            uni.showSpecificCourses(department);
            break;
        case 3:
            cout << "Enter Department Code: ";
            cin >> department;
            cout << "Enter Course Code: ";
            cin >> code;
            cout << "Enter Course Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Credits: ";
            cin >> credits;
            uni.addCourseToDepartment(department, code, name, credits);
            break;
        case 4:
            cout << "Enter Department Code: ";
            cin >> department;
            cout << "Enter Course Code: ";
            cin >> code;
            uni.removeCourse(department, code);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
