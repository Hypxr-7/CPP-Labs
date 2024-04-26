#include <iostream>
using namespace std;

int main(){
    cout << "Enter Number: ";
    int n;
    cin >> n;
    double Harmonic = 0;
    for (float i = 1; i <= n; i++){
        Harmonic += 1 / i;
    }
    cout << "Harmonic Number: " <<  Harmonic << endl;
}