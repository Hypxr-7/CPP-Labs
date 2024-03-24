#include <iostream>

int main(){
    using namespace std;

    unsigned long long fibNum[100] = {};

    fibNum[0] = 1;
    fibNum[1] = 1;

    for (int i = 2; i < size(fibNum); i++){
        fibNum[i] = fibNum[i-1] + fibNum[i-2];
    }
    
    for (int i = 0; i < size(fibNum); i++){
        cout << i+1 << " " << fibNum[i] << endl;
    }
}