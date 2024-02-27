#include <iostream>
using namespace std;

int main() {
    cout << "Enter Number 1: ";
    int num1;
    cin >> num1;
    cout << "Enter Number 2: ";
    int num2;
    cin >> num2;
    int temp;
    while (true){
        if (num2 == 0){
            cout << "GCD: " << abs(num1);
            break;
        }
        temp = num1;
        num1 = num2;
        num2 = temp%num2;
    }
}