#include <iostream>

int count7(int n);

int main(){
    using namespace std;
    int num = -1;
    while (num < 0){
        cout << "Enter Number (non-negative): ";
        cin >> num;
    }
    int count = count7(num);
    cout << "The number 7 appeared " << count << " times" << endl;

    return 0;
}

int count7(int n){
    int count = 0;
    while (n > 0){
        int digit = n%10;
        if (digit == 7){
            count++;
        }
        n = n/10;
    }
    return count;
}