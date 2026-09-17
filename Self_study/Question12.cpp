#include<iostream>
using namespace std;

class Product
{
protected:
    string title;
    double price;

public:
    Product(void) : title(""), price(0.0)
    {   }

    virtual void accept(void)
    {
        cout << "Title : ";
        cin >> title;
        cout << "Price : ";
        cin >> price;
    }

    virtual void display(void)
    {
        cout << "Title : " << title << endl;
        cout << "Price : " << price << endl;
    }

    virtual ~Product(void)
    {   }
};

class Book : public Product
{
private:
    int pages;

public:
    Book(void) : pages(0)
    {   }

    void accept(void)
    {
        Product::accept();
        cout << "Pages : ";
        cin >> pages;
    }

    int getPages(void)
    {
        return pages;
    }
};

class Tape : public Product
{
private:
    int playtime;

public:
    Tape(void) : playtime(0)
    {   }

    void accept(void)
    {
        Product::accept();
        cout << "Playtime : ";
        cin >> playtime;
    }

    int getPlaytime(void)
    {
        return playtime;
    }
};

int main()
{
    Product **arr = new Product*[5];
    int choice;

    for (int i = 0; i < 5; i++)
    {
        cout << "1. Book, 2. Tape, Enter choice : ";
        cin >> choice;

        if (choice == 1)
        {
            arr[i] = new Book();
            arr[i]->accept();
        }
        else if (choice == 2)
        {
            arr[i] = new Tape();
            arr[i]->accept();
        }
    }

    for (int i = 0; i < 5; i++)
    {
        Book *b = dynamic_cast<Book*>(arr[i]);
        if (b != NULL)
            cout << "Pages : " << b->getPages() << endl;

        Tape *t = dynamic_cast<Tape*>(arr[i]);
        if (t != NULL)
            cout << "Playtime : " << t->getPlaytime() << endl;
    }

    for (int i = 0; i < 5; i++)
        delete arr[i];
    delete[] arr;

    return 0;
}