#include <iostream>
using namespace std;

int main(){
    cout << "Enter Length of Sides: ";
    int l;
    cin >> l;
    l--;
    for (int i = 0; i < l+1; i++){
        for (int j = 0; j < i+1; j++){
            cout << "*";
        }
        for (int k = 0; k < l-i; k++){
            cout << ".";
        }
        cout << endl;
    }
}