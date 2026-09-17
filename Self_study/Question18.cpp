#include<iostream>
using namespace std;

template<typename T>
class Array
{
private:
    T *arr;
    int size;

public:
    Array(int size) : size(size)
    {
        arr = new T[size];
    }

    void accept(void)
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter element : ";
            cin >> arr[i];
        }
    }

    void display(void)
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << "\t";
        cout << endl;
    }

    T& operator[](int index)
    {
        return arr[index];
    }

    ~Array(void)
    {
        delete[] arr;
    }
};

int main()
{
    Array<int> a1(5);
    a1.accept();
    a1.display();
    cout << "Element at index 2 : " << a1[2] << endl;

    return 0;
}