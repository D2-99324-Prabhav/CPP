#include<iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(void) : name(""), age(0)
    {   }
    Person(string name, int age) : name(name), age(age)
    {   }

    void display(void)
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }

    virtual void work(void) = 0;
};

class Student : public Person
{
private:
    int marks;

public:
    Student(string name, int age, int marks) : Person(name, age), marks(marks)
    {   }

    void study(void)
    {
        cout << name << " is studying" << endl;
    }

    void work(void)
    {
        study();
    }
};

class Teacher : public Person
{
private:
    double salary;

public:
    Teacher(string name, int age, double salary) : Person(name, age), salary(salary)
    {   }

    void teach(void)
    {
        cout << name << " is teaching" << endl;
    }

    void work(void)
    {
        teach();
    }
};

int main()
{
    Person *p1 = new Student("Malik", 22, 90);
    p1->display();
    p1->work();
    delete p1;

    Person *p2 = new Teacher("Sharma", 40, 60000);
    p2->display();
    p2->work();
    delete p2;

    return 0;
}