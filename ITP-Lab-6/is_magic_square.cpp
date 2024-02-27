#include <iostream>
using namespace std;

int main(){
    int matrix[3][3] = { {2, 7, 6},
                         {9, 5, 1},
                         {4, 3, 8} };

//    int matrix[5][5] = { { 1, 7, 13, 19, 25},
//                         {14, 20, 21, 2, 8},
//                         {22, 3, 9, 15, 16},
//                         {10, 11, 17, 23, 4},
//                         {18, 24, 5, 6, 12} };

//    int matrix[5][5] = {{1, 2, 3, 4, 5},
//                        {6, 7, 8, 9, 10},
//                        {11, 12, 13, 14, 15},
//                        {16, 17, 18, 19, 20},
//                        {21, 22, 23, 24, 25}};

    bool isMagicMat;

    int col_sum[size(matrix)] = {};
    int row_sum[size(matrix)] = {};
    int l_diag_sum = 0;
    int r_diag_sum = 0;

    // check if matrix is square
    if (size(matrix) == size(matrix[0])){

        for (int i = 0; i < size(matrix); i++){
            for (int j = 0; j < size(matrix); j++){
                row_sum[i] += matrix[i][j];
                col_sum[j] += matrix[i][j];
            }
        }

        for (int i = 0; i < size(matrix); i++){
            l_diag_sum += matrix[i][i];
        }

        for (int i = size(matrix) - 1; i >= 0; i--){
            r_diag_sum += matrix[i][i];
        }
        isMagicMat = true;
        for (int i = 0; i < size(matrix) - 1; i++){
            if (col_sum[i] != col_sum[i+1]){
                isMagicMat = false;
                break;
            }
            if (row_sum[i] != row_sum[i+1]){
                isMagicMat = false;
                break;
            }
            if (l_diag_sum != r_diag_sum){
                isMagicMat = false;
                break;
            }
        }

    }
    else{
        isMagicMat = false;
    }

    cout << boolalpha << isMagicMat << endl;

    return 0;
}
