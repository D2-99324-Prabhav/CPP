#include<iostream>
using namespace std;

class InvalidMarksException
{
private:
    string message;

public:
    InvalidMarksException(string message)
    {
        this->message = message;
    }
    string getMessage(void)
    {
        return message;
    }
};

class Student
{
private:
    int rollNo;
    int marks;

public:
    Student(void) : rollNo(0), marks(0)
    {   }

    void setMarks(int marks)
    {
        if (marks < 0)
            throw InvalidMarksException("Marks cannot be negative");
        this->marks = marks;
    }

    void accept(void)
    {
        cout << "Roll No : ";
        cin >> rollNo;

        int m;
        cout << "Marks : ";
        cin >> m;
        setMarks(m);
    }

    void display(void)
    {
        cout << "Roll No : " << rollNo << endl;
        cout << "Marks : " << marks << endl;
    }
};

int main()
{
    Student s1;

    try
    {
        s1.accept();
        s1.display();
    }
    catch (InvalidMarksException exception)
    {
        cout << exception.getMessage() << endl;
    }

    return 0;
}