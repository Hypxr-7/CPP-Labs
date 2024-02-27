#include <iostream>

using std::cin, std::cout;

int factorial(int n);

int main(){
    int n;
    cout << "Enter Num: ";
    cin >> n;
    n = factorial(n);
    cout << "Factorial: " << n;

    return 0;
}

int factorial(int n){
    if (n == 1)
        return n;
    if (n < 1)
        return 1;
    return n*factorial(n-1);
}