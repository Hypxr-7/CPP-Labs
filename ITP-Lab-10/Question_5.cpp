#include <iostream>

using std::cout, std::cin;

double sumTo(int n);

int main(){
    cout << "Enter Num: ";
    int num;
    cin >> num;
    cout << "Sum of n reciprocals: " << sumTo(num);

    return 0;
}

double sumTo(int n){
    if (n == 1)
        return 1;
    return 1.0/n + sumTo(n-1);
}