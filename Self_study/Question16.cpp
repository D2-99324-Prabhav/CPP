#include<iostream>
using namespace std;

class Student
{
private:
    int rollNo;

public:
    Student(void) : rollNo(0)
    {   }

    void setRollNo(int rollNo)
    {
        if (rollNo < 0)
            throw string("Invalid roll number");
        this->rollNo = rollNo;
    }

    void display(void)
    {
        cout << "Roll No : " << rollNo << endl;
    }
};

class AutoPtr
{
private:
    Student *ptr;

public:
    AutoPtr(Student *ptr)
    {
        this->ptr = ptr;
    }

    Student* operator->()
    {
        return this->ptr;
    }

    ~AutoPtr(void)
    {
        delete this->ptr;
    }
};

int main()
{
    try
    {
        AutoPtr s(new Student());
        int rollNo;
        cout << "Roll No : ";
        cin >> rollNo;
        s->setRollNo(rollNo);
        s->display();
    }
    catch (string message)
    {
        cout << message << endl;
    }

    return 0;
}