#include <iostream>
using namespace std;

int main(){
    cout << "Enter Number: ";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        if (i%10 == 1 && (i%100 == 1 || i%100 > 20))
            cout << i << "st Hello" << endl;
        else if (i%10 == 2 && (i%100 == 2 || i%100 > 20))
            cout << i << "nd Hello" << endl;
        else if (i%10 == 3 && (i%100 == 3 || i%100 > 20))
            cout << i << "rd Hello" << endl;
        else
            cout << i << "th Hello" << endl;
    }
}