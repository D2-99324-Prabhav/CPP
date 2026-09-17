#include<iostream>
using namespace std;

class Matrix
{
private:
    int arr[2][2];

public:
    Matrix(void)
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                arr[i][j] = 0;
    }

    void accept(void)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << "Enter element [" << i << "][" << j << "] : ";
                cin >> arr[i][j];
            }
        }
    }

    void display(void)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                cout << arr[i][j] << "\t";
            cout << endl;
        }
    }

    Matrix operator+(Matrix other)
    {
        Matrix temp;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                temp.arr[i][j] = this->arr[i][j] + other.arr[i][j];
        return temp;
    }

    Matrix operator-(Matrix other)
    {
        Matrix temp;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                temp.arr[i][j] = this->arr[i][j] - other.arr[i][j];
        return temp;
    }

    Matrix operator*(Matrix other)
    {
        Matrix temp;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                temp.arr[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    temp.arr[i][j] += this->arr[i][k] * other.arr[k][j];
            }
        }
        return temp;
    }
};

int main()
{
    Matrix m1, m2;
    cout << "Enter Matrix 1\n";
    m1.accept();
    cout << "Enter Matrix 2\n";
    m2.accept();

    Matrix m3 = m1 + m2;
    cout << "Sum\n";
    m3.display();

    Matrix m4 = m1 - m2;
    cout << "Difference\n";
    m4.display();

    Matrix m5 = m1 * m2;
    cout << "Product\n";
    m5.display();

    return 0;
}