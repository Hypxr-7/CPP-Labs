#include <iostream>

using namespace std;

int multiplyDigits(int n){
    if (n < 10)
        return n;
    else
        return ((n%10) * (multiplyDigits(n/10)));
}

int bugger(int n){
    if (n < 10)
        return 0;
    else
        return (1 + bugger(multiplyDigits(n)));
}

int main(){
    int num;
    cout << "Enter number: ";
    cin >> num;
    cout << "Persistent Little Bugger: " << bugger(num);

    return 0;
}