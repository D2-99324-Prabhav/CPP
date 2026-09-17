#include<iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    double balance;

public:
    BankAccount(int accountNumber, double balance) : accountNumber(accountNumber), balance(balance)
    {   }

    void deposit(double amount)
    {
        if (amount < 0)
            throw amount;
        balance = balance + amount;
    }

    void withdraw(double amount)
    {
        if (amount < 0)
            throw amount;
        if (amount > balance)
            throw string("Insufficient balance");
        balance = balance - amount;
    }

    void display(void)
    {
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance : " << balance << endl;
    }
};

int main()
{
    BankAccount b1(101, 5000);

    try
    {
        b1.deposit(-500);
    }
    catch (double amount)
    {
        cout << "Invalid deposit amount : " << amount << endl;
    }

    try
    {
        b1.withdraw(10000);
    }
    catch (string message)
    {
        cout << "Error : " << message << endl;
    }
    catch (double amount)
    {
        cout << "Invalid withdraw amount : " << amount << endl;
    }

    b1.display();

    return 0;
}