#include <iostream>

using std::cout, std::cin;

int isEven(int n);

int main(){
    cout << "Enter num: ";
    int num;
    cin >> num;
    cout << "Even Numbers: " << isEven(num);

    return 0;
}

int isEven(int n){
    if (n == 0)
        return 0;
    if ((n%10)%2 == 0)
        return (isEven(n/10)*10 + (n%10)); 
    return isEven(n/10);
}