#include <iostream>

using std::cout, std::cin, std::endl;

double pi(int n);

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;
    cout << pi(n) << endl;
    
    return 0;
}

double pi(int n) {
    double num = 0;
    for (double i = 0; i < n; i+= 4) {
        num += 4/(i+1);
        num -= 4/(i+3);
    }
    return num;
}