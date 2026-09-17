/*Q1. Provide menu driven code for the functionalities:
1. Add Manager
2. Add Salesman
3. Add Salesmanager
4. Display the count of all employees with respect to designation
5. Display All Managers
6. Display All Salesman
7. Display All SalesManagers*/

#include <iostream>
#include <typeinfo>
using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    Employee() : id(0), salary(0) {}
    Employee(int id, double salary) : id(id), salary(salary) {}

    virtual void accept()
    {
        cout << "ID : ";
        cin >> id;
        cout << "salary : ";
        cin >> salary;
    }

    virtual void display()
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
    SalesManager(int id, double salary, double bonus, double commission) : Employee(id, salary), Manager(id, salary, bonus), Salesman(id, salary, commission) {}

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

int menuList()
{
    int choice;
    cout << "0.Exit" << endl;
    cout << "1.Add Manager " << endl;
    cout << "2.Add Salesman" << endl;
    cout << "3.Add Salesmanager " << endl;
    cout << "4.Display the count of all employees with respect to designation" << endl;
    cout << "5.Display All Managers " << endl;
    cout << "6.Display All Salesman " << endl;
    cout << "7.Display All SalesManagers" << endl;
    cout << "Enter choice  : ";
    cin >> choice;
    return choice;
}

int main()
{
    int choice, index = 0, countManager = 0, countSalesman = 0, countSalesManager = 0;
    Employee *employee[10] = {NULL};

    while ((choice = menuList()) != 0)
    {
        try
        {
            switch (choice)
            {
            case 1:
                employee[index] = new Manager();
                employee[index]->accept();
                index++;
                break;

            case 2:
                employee[index] = new Salesman();
                employee[index]->accept();
                index++;
                break;

            case 3:
                employee[index] = new SalesManager();
                employee[index]->accept();
                index++;
                break;

            case 4:
                for (int i = 0; i < 10; i++)
                {
                    if (employee[i] != NULL && typeid(*employee[i]) == typeid(Manager))
                    {
                        countManager++;
                    }
                    else if (employee[i] != NULL && typeid(*employee[i]) == typeid(Salesman))
                    {
                        countSalesman++;
                    }
                    else if(employee[i] != NULL && typeid(*employee[i]) == typeid(SalesManager))
                    {
                        countSalesManager++;
                    }
                }
                cout << "Manager Count : " << countManager << endl;
                cout << "Salesman Count : " << countSalesman << endl;
                cout << "SalesManager Count : " << countSalesManager << endl;
                break;

            case 5:
                for (int i = 0; i < 10; i++)
                {
                    if (employee[i] != NULL && typeid(*employee[i]) == typeid(Manager))
                        employee[i]->display();
                }
                break;

            case 6:
                for (int i = 0; i < 10; i++)
                {
                    if (employee[i] != NULL && typeid(*employee[i]) == typeid(Salesman))
                        employee[i]->display();
                }
                break;

            case 7:
                for (int i = 0; i < 10; i++)
                {
                    if (employee[i] != NULL && typeid(*employee[i]) == typeid(SalesManager))
                        employee[i]->display();
                }
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
            }
        }
        catch (...)
        {
            cout << "!!!!!Program Crash!!!!!" << endl;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (employee[i] != NULL)
        {
            delete employee[i];
            employee[i] = NULL;
        }
    }
    return 0;
}