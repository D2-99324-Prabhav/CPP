#include<iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accountNumber, string accountHolderName, double balance) : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(balance)
    {   }

    void deposit(double amount)
    {
        balance = balance + amount;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
            balance = balance - amount;
        else
            cout << "Insufficient balance" << endl;
    }

    void displayBalance(void)
    {
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Balance : " << balance << endl;
    }
};

int main()
{
    BankAccount b1(101, "Malik", 5000);
    b1.displayBalance();

    b1.deposit(2000);
    b1.displayBalance();

    b1.withdraw(1000);
    b1.displayBalance();

    return 0;
}