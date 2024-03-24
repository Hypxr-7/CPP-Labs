// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int y, m, d, temp;
    cout << "Enter year: ";
    cin >> y;
    cout << "Enter month: ";
    cin >> m;
    cout << "Enter day: ";
    cin >> d;
    
    y = y - (14 - m) / 12;
    temp = y + y/4 - y/100 + y/400;
    m = m + 12 * ((14 - m) / 12) -2;
    d = ((d + temp + 31 * m/12)) % 7;
    
    if (d == 0)
        cout << "Sunday";
    if (d == 1)
        cout << "Monday";
    if (d == 2)
        cout << "Tuesday";
    if (d == 3)
        cout << "Wednesday";
    if (d == 4)
        cout << "Thursday";
    if (d == 5)
        cout << "Friday";
    if (d == 6)
        cout << "Saturday";
}