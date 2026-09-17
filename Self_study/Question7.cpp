#include<iostream>
using namespace std;

namespace college
{
    class Student
    {
    private:
        int rollNo;
        string name;

    public:
        Student(void) : rollNo(0), name("")
        {   }
        Student(int rollNo, string name) : rollNo(rollNo), name(name)
        {   }

        void setRollNo(int rollNo) { this->rollNo = rollNo; }
        int getRollNo(void) { return rollNo; }

        void setName(string name) { this->name = name; }
        string getName(void) { return name; }

        void display(void)
        {
            cout << "Roll No : " << rollNo << endl;
            cout << "Name : " << name << endl;
        }
    };

    class Teacher
    {
    private:
        int id;
        string name;

    public:
        Teacher(void) : id(0), name("")
        {   }
        Teacher(int id, string name) : id(id), name(name)
        {   }

        void setId(int id) { this->id = id; }
        int getId(void) { return id; }

        void setName(string name) { this->name = name; }
        string getName(void) { return name; }

        void display(void)
        {
            cout << "Id : " << id << endl;
            cout << "Name : " << name << endl;
        }
    };
}

int main()
{
    college::Student s1(1, "Malik");
    s1.display();

    college::Teacher t1(101, "Sharma");
    t1.display();

    return 0;
}