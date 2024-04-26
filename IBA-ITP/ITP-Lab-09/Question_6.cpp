#include <iostream>
#include <vector> 

using std::cout, std::cin, std::endl, std::vector;

vector<vector<int>> toMatrix(int num);
void printCoinsMatrix(const vector<vector<int>>& a);

int main() {
    cout << "Enter a number: ";
    int denary;
    cin >> denary;

    vector<vector<int>> binarymatrix = toMatrix(denary);
    printCoinsMatrix(binarymatrix);

    

}

vector<vector<int>> toMatrix(int num) {
    vector<vector<int>> v = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    for (int i = 2; i >= 0; i--) {
        for (int j = 2; j >= 0; j--) {
            v[i][j] = num%2;
            num = num/2;
        }
    }
    return v;
}

void printCoinsMatrix(const vector<vector<int>>& a) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == 1)
                cout << "T ";
            else 
                cout << "H ";
        }
        cout << endl; 
    }

}