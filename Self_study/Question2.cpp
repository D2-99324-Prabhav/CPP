#include<iostream>
using namespace std;

inline int factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
        result = result * i;
    return result;
}

inline double power(double base, int exp)
{
    double result = 1;
    for (int i = 0; i < exp; i++)
        result = result * base;
    return result;
}

int main()
{
    int n;
    cout << "Enter number : ";
    cin >> n;
    cout << "Factorial : " << factorial(n) << endl;

    double base;
    int exp;
    cout << "Enter base : ";
    cin >> base;
    cout << "Enter exponent : ";
    cin >> exp;
    cout << "Power : " << power(base, exp) << endl;

    return 0;
}