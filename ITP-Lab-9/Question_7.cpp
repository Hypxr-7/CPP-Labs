#include <iostream>
#include <vector> 

using std::cout, std::endl, std::vector;

bool sudokuCheckRepetition(vector<vector<int>> a);
bool sudokuCheckSum(vector<vector<int>> a);

int main() {

    vector<vector<int>> a = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9} };

    vector<vector<int>> b = {
    {4,3,5,2,6,9,7,8,1},
    {6,8,2,5,7,1,4,9,3},
    {1,9,7,8,3,4,5,6,2},
    {8,2,6,1,9,5,3,4,7},
    {3,7,4,6,8,2,9,1,5},
    {9,5,1,7,4,3,6,2,8},
    {5,1,9,3,2,6,8,7,4},
    {2,4,8,9,5,7,1,3,6},
    {7,6,3,4,1,8,2,5,9}
    };


    if (sudokuCheckSum(a) && sudokuCheckRepetition(a))
        cout << "The sudoku puzzle is valid!\n";
    else 
        cout << "Your sudoku puzzle is wrong :(\n";

    if (sudokuCheckSum(b) && sudokuCheckRepetition(b))
        cout << "The sudoku puzzle is valid!\n";
    else 
        cout << "Your sudoku puzzle is wrong :(\n";

}

bool sudokuCheckRepetition(vector<vector<int>> a) {
    bool norep = true;  
    vector<int> arr = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[a[i][j]-1] == 1) {
                cout << "Your sudoku puzzle is wrong! You can't use one digit twice in a row" << endl;
                norep = false;
                break;
            }
            else 
                arr[a[i][j]-1]++;
        }
        arr.assign(9, 0);
    }
    arr = {0, 0, 0, 0, 0, 0, 0, 0, 0}; 
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[a[j][i]-1] == 1) {
                cout << "Your sudoku puzzle is wrong! You can't use one digit twice in a columns" << endl;
                norep = false;
                break;}
            else 
                arr[a[j][i]-1]++;
        }
        arr.assign(9, 0);
    }

    return norep;
}

bool sudokuCheckSum(vector<vector<int>> a) {
    bool issum45 = true; 
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            sum = sum + a[i][j]; 
        }
        if (sum != 45) {
            issum45 = false;
            break;
        }
        sum = 0;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            sum = sum + a[j][i]; 
        }
        if (sum != 45) {
            issum45 = false;
            break;
        }
        sum = 0;
    }
    return issum45;
}
