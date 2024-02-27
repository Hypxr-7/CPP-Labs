#include <iostream>
#include <cmath>
using namespace std;

// will take 2 to 3 min for very large input like 87'539'319

int main(){
    cout << "Enter Number: ";
    int n;
    cin >> n;

    for (int i = 1; i <= cbrt(n); i++){
        for (int j = i+1; j <= cbrt(n); j++){
            for (int k = j+1; k <= cbrt(n); k++){
                for (int l = k+1; l <= cbrt(n); l++){
                    if (pow(i, 3) + pow(j, 3) == pow(k, 3) + pow(l, 3)){
                        cout << i << "^3 + " << j << "^3 = " << k << "^3 + " << l << "^3" << endl;
                    }
                    if (pow(i, 3) + pow(k, 3) == pow(j, 3) + pow(l, 3)){
                        cout << i << "^3 + " << k << "^3 = " << j << "^3 + " << l << "^3" << endl;
                    }
                    if (pow(i, 3) + pow(l, 3) == pow(k, 3) + pow(j, 3)){
                        cout << i << "^3 + " << l << "^3 = " << k << "^3 + " << j << "^3" << endl;
                    }
                }
            }
        }
    }
}