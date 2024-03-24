#include <iostream>

using namespace std;

int mines_count(bool** mines, int m, int n){
    int counts[m][m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mines[i][j]) {
                counts[i][j] = 99;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue;
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && !mines[ni][nj]) {
                            counts[ni][nj]++;
                        }
                    }
                }
            }
        }
    }

    return counts;
}

int main() {
    const int m = 4, n = 4;
    bool* grid[m];
    grid[0] = new bool[n] {false, false, false, false};
    grid[1] = new bool[n] {false, true, false, false};
    grid[2] = new bool[n] {false, false, false, false};
    grid[3] = new bool[n] {false, false, false, true};
    // call mines_count()
    int** counts = mines_count(grid, m, n);
    // print counts
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; j++)
            std::cout << counts[i][j] << " ";
    std::cout << "\n";
    }
    // free memory
    for (int i = 0; i < m; ++i)
    delete[] grid[i];

    return 0;
}