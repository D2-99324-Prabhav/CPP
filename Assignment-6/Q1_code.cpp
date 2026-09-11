#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    int id;
    string title;
    double price;

public:
    Product() : id(0), title(""), price(0.0) {}

    Product(int i, const string& t, double p) : id(i), title(t), price(p) {}

    virtual double calculateDiscountedPrice() const {
        return price;
    }

    virtual void printProduct() const {
        cout << "ID: " << id << "\nTitle: " << title << "\nPrice: " << price << endl;
    }

    virtual ~Product() {}
};

class Book : public Product {
private:
    string author;

public:
    Book(int i, const string& t, const string& a, double p)
        : Product(i, t, p), author(a) {}

    double calculateDiscountedPrice() const override {
        return price * 0.90;
    }

    void printProduct() const override {
        cout << "Book" << endl;
        cout << "ID: " << id << "\nTitle: " << title << "\nAuthor: " << author << "\nPrice: " << price << "\nDiscounted Price: " << calculateDiscountedPrice() << endl;
    }
};

class Tape : public Product {
private:
    string artist;

public:
    Tape(int i, const string& t, const string& a, double p)
        : Product(i, t, p), artist(a) {}

    double calculateDiscountedPrice() const override {
        return price * 0.95;
    }

    void printProduct() const override {
        cout << "Tape" << endl;
        cout << "ID: " << id << "\nTitle: " << title << "\nArtist: " << artist << "\nPrice: " << price << "\nDiscounted Price: " << calculateDiscountedPrice() << endl;
    }
};

int main() {
    Product* arr[3];
    int choice;

    for (int i = 0; i < 3; i++) {
        cout << "\nProduct " << i + 1 << " type:" << endl;
        cout << "1. Book" << endl;
        cout << "2. Tape" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string title, author;
            double price;

            cout << "Enter id: ";
            cin >> id;
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter author: ";
            cin >> author;
            cout << "Enter price: ";
            cin >> price;

            arr[i] = new Book(id, title, author, price);
        } else if (choice == 2) {
            int id;
            string title, artist;
            double price;

            cout << "Enter id: ";
            cin >> id;
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter artist: ";
            cin >> artist;
            cout << "Enter price: ";
            cin >> price;

            arr[i] = new Tape(id, title, artist, price);
        } else {
            cout << "Invalid option. Exiting." << endl;
            return 0;
        }
    }

    double totalBill = 0.0;
    for (int i = 0; i < 3; i++) {
        totalBill += arr[i]->calculateDiscountedPrice();
        arr[i]->printProduct();
    }

    cout << "\nFinal bill: " << totalBill << endl;

    for (int i = 0; i < 3; i++) {
        delete arr[i];
    }

    return 0;
}
