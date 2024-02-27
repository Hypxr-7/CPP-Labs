#include <iostream>

long long factorial(long long n);

int main(){
    using namespace std;
    long long n = -1;
    while (n < 0){
        cout << "Enter num (non-negative): ";
        cin >> n;
    }
    n = factorial(n);
    cout << "Factorial of this number is " << n;

    return 0;
}

long long factorial(long long n){
    long long fact = 1;
    for (long long i = 1; i < n+1; i++){
        fact *= i;
    }
    return fact;
}

// highest num that can be taken is 20