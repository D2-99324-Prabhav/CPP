// Q13 - Payment, CreditCard, UPI, Cash with PaymentFactory
#include<iostream>
#include <cstring>
using namespace std;

class Payment
{
public:
    virtual void makePayment(double amount) = 0;
    virtual ~Payment(void)
    {   }
};

class CreditCard : public Payment
{
public:
    void makePayment(double amount)
    {
        cout << "Paid " << amount << " using Credit Card" << endl;
    }
};

class UPI : public Payment
{
public:
    void makePayment(double amount)
    {
        cout << "Paid " << amount << " using UPI" << endl;
    }
};

class Cash : public Payment
{
public:
    void makePayment(double amount)
    {
        cout << "Paid " << amount << " using Cash" << endl;
    }
};

class PaymentFactory
{
public:
    static Payment* create(char *mode)
    {
        if (strcmp(mode, "credit card") == 0)
            return new CreditCard();
        else if (strcmp(mode, "upi") == 0)
            return new UPI();
        else if (strcmp(mode, "cash") == 0)
            return new Cash();
        else
            return NULL;
    }
};

int main()
{
    char mode[20];
    cout << "Enter mode "<<endl;
    cout<<"credit Card\n"<<"upi\n"<<"cash\n"<<endl;
    cin >> mode;

    Payment *p1 = PaymentFactory::create(mode);

    if (p1 != NULL)
    {
        p1->makePayment(500);
        delete p1;
    }
    else
    {
        cout << "Invalid mode" << endl;
    }

    return 0;
}