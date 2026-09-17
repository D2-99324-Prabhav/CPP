#include<iostream>
#include<memory>
using namespace std;

class Student
{
public:
    Student(void)
    {
        cout << "Student Constructor Called" << endl;
    }
    ~Student(void)
    {
        cout << "Student Destructor Called" << endl;
    }
    void display(void)
    {
        cout << "Student display called" << endl;
    }
};

int main()
{
    cout << "unique_ptr demo\n";
    unique_ptr<Student> u1(new Student());
    u1->display();
    unique_ptr<Student> u2 = move(u1);
    u2->display();

    cout << "\nshared_ptr demo\n";
    shared_ptr<Student> s1(new Student());
    cout << "Count : " << s1.use_count() << endl;
    shared_ptr<Student> s2 = s1;
    cout << "Count : " << s1.use_count() << endl;

    cout << "\nweak_ptr demo\n";
    weak_ptr<Student> w1 = s1;
    cout << "Count after weak_ptr : " << s1.use_count() << endl;
    if (!w1.expired())
    {
        shared_ptr<Student> s3 = w1.lock();
        s3->display();
    }

    return 0;
}