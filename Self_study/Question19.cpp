#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
    list<int> l1;

    for (int i = 0; i < 10; i++)
        l1.push_back(rand() % 100);

    cout << "Reverse order : ";
    list<int>::reverse_iterator ritr = l1.rbegin();
    while (ritr != l1.rend())
    {
        cout << *ritr << " ";
        ritr++;
    }
    cout << endl;

    list<int>::iterator itr = l1.begin();
    while (itr != l1.end())
    {
        *itr = *itr + 5;
        itr++;
    }

    cout << "After increment (const iterator) : ";
    list<int>::const_iterator citr = l1.begin();
    while (citr != l1.end())
    {
        cout << *citr << " ";
        citr++;
    }
    cout << endl;

    l1.sort();

    cout << "Sorted list : ";
    itr = l1.begin();
    while (itr != l1.end())
    {
        cout << *itr << " ";
        itr++;
    }
    cout << endl;

    return 0;
}