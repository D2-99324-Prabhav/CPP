#include <iostream>
using namespace std;

class Cylinder {
private:
    static const double PI;
    double radius;
    double height;

public:
    Cylinder() : radius(1.0), height(1.0) {}

    Cylinder(double r, double h) : radius(r), height(h) {}

    double getRadius() const {
        return radius;
    }

    void setRadius(double r) {
        radius = r;
    }

    double getHeight() const {
        return height;
    }

    void setHeight(double h) {
        height = h;
    }

    double calculateVolume() const {
        return PI * radius * radius * height;
    }
};

const double Cylinder::PI = 3.14;

int main() {
    Cylinder c1;
    Cylinder c2(3.0, 5.0);

    cout << "Default cylinder volume: " << c1.calculateVolume() << endl;
    cout << "Given cylinder volume: " << c2.calculateVolume() << endl;

    c1.setRadius(2.5);
    c1.setHeight(4.0);
    cout << "Updated cylinder volume: " << c1.calculateVolume() << endl;

    return 0;
}
