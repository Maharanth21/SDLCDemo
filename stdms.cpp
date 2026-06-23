#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
};

vector<Student> students;

void addStudent() {
    Student s;

    cout << "\nEnter Student ID: ";
    cin >> s.id;

    cout << "Enter Student Name: ";
    cin >> s.name;

    cout << "Enter Student Age: ";
    cin >> s.age;

    students.push_back(s);

    cout << "Student Added Successfully!\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "\nNo Student Records Found!\n";
        return;
    }

    cout << "\nStudent Records:\n";

    for (const auto &s : students) {
        cout << "ID: " << s.id
             << ", Name: " << s.name
             << ", Age: " << s.age << endl;
    }
}

void searchStudent() {
    int id;
    cout << "\nEnter Student ID to Search: ";
    cin >> id;

    for (const auto &s : students) {
        if (s.id == id) {
            cout << "\nStudent Found:\n";
            cout << "ID: " << s.id
                 << "\nName: " << s.name
                 << "\nAge: " << s.age << endl;
            return;
        }
    }

    cout << "Student Not Found!\n";
}

void deleteStudent() {
    int id;
    cout << "\nEnter Student ID to Delete: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "Student Deleted Successfully!\n";
            return;
        }
    }

    cout << "Student Not Found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}