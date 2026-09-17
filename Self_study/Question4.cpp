#include<iostream>
using namespace std;

class Laptop
{
private:
    int brandId;
    double price;

public:
    Laptop(void) : brandId(1), price(50000)
    {
        cout << "Laptop Constructor Called" << endl;
    }

    ~Laptop(void)
    {
        cout << "Laptop Destructor Called" << endl;
    }

    void display(void)
    {
        cout << "Brand Id : " << brandId << endl;
        cout << "Price : " << price << endl;
    }
};

int main()
{
    Laptop l1;
    l1.display();

    return 0;
}