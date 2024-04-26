#include <iostream>
using namespace std;

int main(){

    // utm

    //  int matrix[3][3] = {{1, 4, 6},
    //                      {0, 8, 1},
    //                      {0, 0, 4}};

//     int matrix[3][3] = {{1, 4, 6},
//                         {0, 8, 1},
//                         {0, 0, 0}};

    int matrix[5][5] = {{1, 2, 3, 4, 5},
                        {0, 6, 7, 8, 9},
                        {0, 0, 10, 11, 12},
                        {0, 0, 0, 13, 14},
                        {0, 0, 0, 0, 15}};


    // not utm

//     int matrix[3][3] = {{1, 4, 6},
//                         {0, 8, 1},
//                         {0, 5, 4}};

//    int matrix[5][5] = {{1, 2, 3, 4, 5},
//                        {6, 7, 8, 9, 10},
//                        {11, 12, 13, 14, 15},
//                        {16, 17, 18, 19, 20},
//                        {21, 22, 23, 24, 25}};

    bool isUTM = true;
    for (int i = 1; i < size(matrix); i++){
        for (int j = 0; j < i; j++){
            if (matrix[i][j] != 0){
                isUTM = false;
                break;
            }
        }
        if (!isUTM){
            break;
        }
    }

    if (isUTM){
        cout << "Matrix is Upper Triangular" << endl;
    }
    else{
        cout << "Matrix is Not Upper Triangular" << endl;

    }

    return 0;
}