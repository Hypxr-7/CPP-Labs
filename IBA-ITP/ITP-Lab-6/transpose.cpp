#include <iostream>
using namespace std;

int main(){

    int a[4][3] = { {9, 5, 7},
                {1, 3, 6},
                {5, 4, 1},
                {0, 8, 2} };

    int b[size(a[0])][size(a)] = {};

    for (int i = 0; i < size(a); i++){
        for (int j = 0; j < size(a[0]); j++){
            b[j][i] = a[i][j];
        }
    }

    cout << "Initial Matrix: " << endl;
    for (int i = 0; i < size(a); i++){
        for (int j = 0; j < size(a[0]); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Transposed Matrix: " << endl;
    for (int i = 0; i < size(b); i++){
        for (int j = 0; j < size(b[0]); j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}