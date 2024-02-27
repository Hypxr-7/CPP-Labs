#include <iostream>
using namespace std;

int main(){
    cout << "Enter Length of Sides: ";
    int l;
    cin >> l;
    for (int i = 0; i < l; i++){
        for (int j = 0; j < i+1; j++){
            cout << "*";
        }
        cout << endl;
    }
}