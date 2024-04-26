#include <iostream>
using namespace std;

int main() {
    cout << "Enter Number: ";
    int num, digit;
    cin >> num;
    bool isOdd = true;
    while (num > 0){
        digit = num%10;
        if (digit%2 == 0){
            isOdd = false;
        }
        num = num / 10;
    }
    
    if (isOdd == true)
        cout << "True";
    else
        cout << "False";
}