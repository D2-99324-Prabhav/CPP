#include<iostream>
using namespace std;

class Programmer
{
public:
    Programmer(void)
    {
        cout << "Programmer Constructor Called" << endl;
    }
    void work(void)
    {
        cout << "Programmer is writing code" << endl;
    }
};

class Teacher
{
public:
    Teacher(void)
    {
        cout << "Teacher Constructor Called" << endl;
    }
    void work(void)
    {
        cout << "Teacher is teaching" << endl;
    }
};

class ProgrammingTeacher : public Programmer, public Teacher
{
public:
    ProgrammingTeacher(void)
    {
        cout << "ProgrammingTeacher Constructor Called" << endl;
    }
};

int main()
{
    ProgrammingTeacher pt1;

    pt1.Programmer::work();
    pt1.Teacher::work();

    return 0;
}