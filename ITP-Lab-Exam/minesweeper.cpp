#include <iostream>

int** mines_count(bool** mines, int m, int n) {
    int** counts = new int*[m];
    for (int i = 0; i < m; i++) {
        counts[i] = new int[n]();
    }

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

    int** counts = mines_count(grid, m, n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; j++)
            std::cout << counts[i][j] << " ";
        std::cout << "\n";
    }

    for (int i = 0; i < m; ++i) {
        delete[] grid[i];
        delete[] counts[i];
    }
    delete[] counts;

    return 0;
}