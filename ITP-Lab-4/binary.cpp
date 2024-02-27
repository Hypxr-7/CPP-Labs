#include <iostream>
using namespace std;

int main(){
    cout << "Enter Decimal Number: ";
    int dec_num;
    cin >> dec_num;
    
    int v = 1;
    int k = 0;
    while (v <= dec_num/2){
        v = 2*v;
        k++;
    }
    
    for (int i = 0; i <= k; i++ ){
        if (v <= dec_num){
            cout << "1";
            dec_num -= v;
        }
        else{
            cout << "0";
        }
        v = v/2;
    }
}