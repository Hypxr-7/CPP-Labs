#include <iostream>

using std::cout, std::cin;

int gcd(int m, int n);

int main(){
    int num1, num2;
    cout << "Enter num 1: ";
    cin >> num1;
    cout << "Enetr num 2: ";
    cin >> num2;
    cout << "The GCD is " << (num1 < num2 ? gcd(num1, num2) : gcd(num2, num1));

    return 0;
}

int gcd(int m, int n){
    if (m==n)
        return m;
     if (m < n-m)
        return gcd(m, n-m);
    return gcd(n-m, m);
}