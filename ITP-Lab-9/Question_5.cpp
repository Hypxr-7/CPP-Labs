#include <iostream>
#include <vector>
#include <cstdlib>

using std::cout, std::endl, std::vector;

vector<vector<int>> genRandomMatrix(int m, int n);
void printMatrix(const vector<vector<int>>& a);
int findMaxOnesCol(const vector<vector<int>>& a);
int findMaxOnesRow(const vector<vector<int>>& a);

int main() {

    vector<vector<int>> randomMatrix = genRandomMatrix(4,4);

    cout << "Random Matrix:" << endl;
    printMatrix(randomMatrix);

    cout << endl << "The largest row index: " << findMaxOnesRow(randomMatrix);
    cout << endl << "The largest column index: " << findMaxOnesCol(randomMatrix);

    return 0;
}

vector<vector<int>> genRandomMatrix(int m, int n) {
    srand(time(0));
    vector<vector<int>> matrix(m, vector<int>(n, 0)); 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int rn = rand() % 2; 
            matrix[i][j] = rn; 
        }
    }

    return matrix;
}


void printMatrix(const vector<vector<int>>& a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int findMaxOnesCol(const vector<vector<int>>& a) {
    
    int max = 0;
    int maxcol = 0;

    for (int i = 0; i < a.size(); i++) {
        int col = 0;
        for (int j = 0; j < a[i].size(); j++) {
            if (a[j][i] == 1)
                col++;
        }
        if (col > max) {
            max = col;
            maxcol = i;
        }
    }
    return maxcol;
}


int findMaxOnesRow(const vector<vector<int>>& a) {
    
    int max = 0;
    int maxrow = 0;

    for (int i = 0; i < a.size(); i++) {
        int row = 0;
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] == 1)
                row++;
        }
        if (row > max) {
            max = row;
            maxrow = i;
        }
    }
    return maxrow;
}