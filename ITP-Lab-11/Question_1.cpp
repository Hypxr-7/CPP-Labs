#include <iostream>

using std::cout, std::cin;

int fibonacci(int n);

int main(){
    cout << "Enter num: ";
    int num;
    cin >> num;
    cout << "The fib num at " << num << " is " << fibonacci(num);

    return 0;
}
int fibonacci(int n){
    if (n==1)
        return 1;
    if (n==2)
        return fibonacci(1);
    return fibonacci(n-1) + fibonacci(n-2);
}