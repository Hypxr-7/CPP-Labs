#include <iostream>
using namespace std;

int main(){

    int a[3][5] = { {12, 32, 54, 25, 43},
                    {89, 26, 46, 50, 15},
                    {74, 9, 98, 78, 21} };
    
    int j = 0;
    int sum = 0;
    cout << "Pick column index (0 - " << size(a[0]) - 1 << "): ";
    cin >> j;

    for (int i = 0; i < size(a); i++){
        sum += a[i][j];
    }

    cout << "Sum of column " << j << " is " << sum;

    return 0;
}
