#include <iostream>

using std::cout, std::cin;

int count7(int n);

int main(){
    int n;
    cout << "Enter Num: ";
    cin >> n;
    n = count7(n);
    cout << "Count of 7s: " << n;

    return 0;
}

int count7(int n){
    if (n == 0){
        return 0;
    }
    if (n%10 == 7){
        return 1 + count7(n/10);
    }
    else{
        return count7(n/10);
    }

}