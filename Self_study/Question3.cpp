#include<iostream>
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

    int getMarks(void)
    {
        return marks;
    }

    int getRollNo(void)
    {
        return rollNo;
    }
};

int main()
{
    int n;
    cout << "Enter number of students : ";
    cin >> n;

    Student *arr = new Student[n];

    for (int i = 0; i < n; i++)
        arr[i].accept();

    cout << "\nAll Student Records\n";
    for (int i = 0; i < n; i++)
        arr[i].display();

    int highestIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].getMarks() > arr[highestIndex].getMarks())
            highestIndex = i;
    }

    cout << "\nHighest Marks\n";
    arr[highestIndex].display();

    delete[] arr;

    return 0;
}