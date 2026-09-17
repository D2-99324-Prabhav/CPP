/*Q2. Implement following classes. Test all functionalities in main() of each created class. Note that
employee is inherited into manager and salesman.*/

#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    Employee() : id(0), salary(0) {}
    Employee(int id, double salary) : id(id), salary(salary) {}

    void accept()
    {
        cout << "ID : ";
        cin >> id;
        cout << "salary : ";
        cin >> salary;
    }

    void display()
    {
        cout << "ID : " << id << endl;
        cout << "Salary : " << salary << endl;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId()
    {
        return this->id;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }

    double getSalary()
    {
        return this->salary;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

public:
    Manager() : bonus(0) {}
    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus) {}

    void accept()
    {
        Employee::accept();
        this->acceptManager();
    }

    void display()
    {
        Employee::display();
        this->displayManager();
    }

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getBonus()
    {
        return this->bonus;
    }

protected:
    void acceptManager()
    {
        cout << "Bonus : ";
        cin >> bonus;
    }

    void displayManager()
    {
        cout << "Bonus : " << bonus << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    double commission;

public:
    Salesman() : commission(0) {}
    Salesman(int id, double salary, double commission) : Employee(id, salary), commission(commission) {}

    void accept()
    {
        Employee::accept();
        this->acceptSalesman();
    }

    void display()
    {
        Employee::display();
        this->displaySalesman();
    }

    void setCommission(double commission)
    {
        this->commission = commission;
    }

    double getCommission()
    {
        return commission;
    }

protected:
    void acceptSalesman()
    {
        cout << "Commission : ";
        cin >> commission;
    }

    void displaySalesman()
    {
        cout << "Commission : " << commission << endl;
    }
};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager() {}
    SalesManager(int id, double salary, double bonus, double commission) :Employee(id,salary), Manager(id, salary, bonus), Salesman(id, salary, commission) {}

    void accept()
    {
        Employee::accept();
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }

    void display()
    {
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};

int main()
{
    SalesManager salesManager;
    salesManager.accept();
    cout << "--------Display--------" << endl;
    salesManager.display();

    cout<<endl;
    cout<<"Bonus : "<<salesManager.getBonus()<<endl;
    cout<<"Commission : "<<salesManager.getCommission()<<endl;
}