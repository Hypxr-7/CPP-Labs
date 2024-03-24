#include <iostream>
using namespace std;

int main() {
    cout << "Enter Number: ";
    long long num;
    cin >> num;
    for (int i = 2; i <= num; i++){
        bool isPrime = true;
        if (num%i == 0){
            for (int j = 2; j < i; j++){
                if (i%j == 0){
                    isPrime = false;
                }
            }
        if (isPrime == true){
            cout << "Number: " << i << endl;
            }
        }
    }
}