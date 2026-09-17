#include<iostream>
#include<fstream>
using namespace std;

class Student
{
private:
    int rollNo;
    int marks;

public:
    Student(void) : rollNo(0), marks(0)
    {   }

    void accept(void)
    {
        cout << "Roll No : ";
        cin >> rollNo;
        cout << "Marks : ";
        cin >> marks;
    }

    void display(void)
    {
        cout << "Roll No : " << rollNo << endl;
        cout << "Marks : " << marks << endl;
    }

    void save(ofstream &out)
    {
        out.write((char*)this, sizeof(Student));
    }

    void load(ifstream &in)
    {
        in.read((char*)this, sizeof(Student));
    }
};

int main()
{
    Student s1;
    s1.accept();

    ofstream out("student.dat", ios::binary);
    s1.save(out);
    out.close();

    Student s2;
    ifstream in("student.dat", ios::binary);
    s2.load(in);
    in.close();

    cout << "Loaded Student\n";
    s2.display();

    return 0;
}