#include <iostream>
using namespace std;

int main(){

    int a[][4] = { {2, 5, 7, 1},
                    {1, 3, 6, 1},
                    {5, 4, 1, 3} };

    int b[][4] = { {1, 9, 5, 0},
                    {7, 1, 5, 4},
                    {3, 4, 2, 8} };
    
    int c[3][4] = {};

    for (int i = 0; i < size(a); i++){
        for (int j = 0; j < size(a[0]); j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for (int i = 0; i < size(c); i++){
        for (int j = 0; j < size(c[0]); j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}