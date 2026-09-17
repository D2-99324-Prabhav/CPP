/*Q1. Write a class Distance to hold feet and inches. Overload operator + as member function. Also,
overload ++ operator (to increment inches) as member function and -- operator as friend function.
Overload << and >> operators to accept and display distance.*/

#include <iostream>
using namespace std;

class Distance
{
private:
    int foot;
    int inches;

public:
    Distance() : foot(0), inches(0) {}
    Distance(int foot, int inches) : foot(foot), inches(inches) {}

    Distance operator+(Distance other)
    {
        Distance temp;
        temp.foot = this->foot + other.foot;
        temp.inches = this->inches + other.inches;
        return temp;
    }

    Distance operator++()
    {
        Distance temp;
        temp.foot = this->foot++;
        temp.inches = this->inches++;
    }

    friend istream &operator>>(istream &in, Distance &d);
    friend ostream &operator<<(ostream &out, const Distance &d);
    friend Distance operator--(Distance &other);
};

Distance operator--(Distance &other)
{
    Distance temp;
    temp.foot = other.foot--;
    temp.inches = other.inches--;
    return temp;
}

ostream &operator<<(ostream &out, const Distance &d)
{
    out << d.foot << " feet " << d.inches << " inches"<<endl;
    return out;
}

istream &operator>>(istream &in, Distance &d)
{
    cout << "Enter feet: ";
    in >> d.foot;

    cout << "Enter inches: ";
    in >> d.inches;

    return in;
}

int main()
{
    Distance d1(3, 6);
    Distance d2(4, 3);

    Distance d3 = d2 + d1;
    cout << d3;

    ++d2;
    cout << d2;

    --d1;
    cout << d1;

    Distance d4;
    cin>>d4;
    cout<<d4;
}
