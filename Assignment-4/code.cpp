#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time() : hour(0), minute(0), second(0) {}

    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSeconds() const { return second; }

    void setHour(int h) { hour = h; }
    void setMinute(int m) { minute = m; }
    void setSeconds(int s) { second = s; }

    void printTime() const {
        cout << hour << ":" << minute << ":" << second << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of Time objects: ";
    cin >> n;

    Time* arr = new Time[n];

    for (int i = 0; i < n; i++) {
        int h, m, s;
        cout << "Enter time " << i + 1 << " (hour minute second): ";
        cin >> h >> m >> s;
        arr[i] = Time(h, m, s);
    }

    int choice;
    do {
        cout << "\n---- Time Menu ----" << endl;
        cout << "1. Add Time" << endl;
        cout << "2. Display All Time" << endl;
        cout << "3. Display only hours of all times" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Time* temp = new Time[n + 1];
                for (int i = 0; i < n; i++) {
                    temp[i] = arr[i];
                }
                int h, m, s;
                cout << "Enter new time (hour minute second): ";
                cin >> h >> m >> s;
                temp[n] = Time(h, m, s);
                delete[] arr;
                arr = temp;
                n++;
                cout << "Time added." << endl;
                break;
            }
            case 2:
                for (int i = 0; i < n; i++) {
                    cout << "Time " << i + 1 << ": ";
                    arr[i].printTime();
                }
                break;
            case 3:
                for (int i = 0; i < n; i++) {
                    cout << "Time " << i + 1 << " hour: " << arr[i].getHour() << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    delete[] arr;
    return 0;
}
