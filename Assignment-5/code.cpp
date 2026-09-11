#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() : day(1), month(1), year(2000) {}

    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void acceptDate() {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }

    void printDate() const {
        cout << day << "/" << month << "/" << year;
    }
};

class Person {
private:
    string name;
    string address;
    Date birthDate;

public:
    void acceptPerson() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter birth date: " << endl;
        birthDate.acceptDate();
    }

    void printPerson() const {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birth date: ";
        birthDate.printDate();
        cout << endl;
    }
};

class Student {
private:
    int id;
    float marks;
    string course;
    Date joiningDate;
    Date endDate;

public:
    void acceptStudent() {
        cout << "Enter student id: ";
        cin >> id;
        cout << "Enter marks: ";
        cin >> marks;
        cout << "Enter course: ";
        cin >> course;
        cout << "Enter joining date: " << endl;
        joiningDate.acceptDate();
        cout << "Enter end date: " << endl;
        endDate.acceptDate();
    }

    void printStudent() const {
        cout << "Student id: " << id << endl;
        cout << "Marks: " << marks << endl;
        cout << "Course: " << course << endl;
        cout << "Joining date: ";
        joiningDate.printDate();
        cout << endl;
        cout << "End date: ";
        endDate.printDate();
        cout << endl;
    }
};

int main() {
    Person p;
    Student s;

    p.acceptPerson();
    s.acceptStudent();

    cout << "\n--- Person Details ---" << endl;
    p.printPerson();

    cout << "\n--- Student Details ---" << endl;
    s.printStudent();

    return 0;
}
