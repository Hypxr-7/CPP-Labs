#include <iostream>
#include <vector>
#include <queue>

using std::vector;

vector<vector<int>> highestPeak(const vector<vector<int>>& isWater);

int main() {
//    vector<vector<int>> isWater {{0, 1},
//                                 {0, 0}};

    vector<vector<int>> isWater {{0, 0, 1},
                                 {1, 0, 0},
                                 {0, 0, 0}};

    auto heights = highestPeak(isWater);

    for (const auto& vec : heights){
        for (const auto& v : vec){
            std:: cout << v << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}

vector<vector<int>> highestPeak(const vector<vector<int>>& isWater){
    int m { static_cast<int>(isWater.size()) };
    int n { static_cast<int>(isWater[0].size()) };
    vector<vector<int>> height(m, vector<int>(n, -1));
    std::queue<std::pair<int, int>> queue;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (isWater[i][j] == 1) {
                height[i][j] = 0;
                queue.emplace(i, j);
            }

    const int direction[5] {-1, 0, 1, 0, -1};
    while (!queue.empty()) {
        std::pair<int, int> position = queue.front();
        queue.pop();
        for (int k = 0; k < 4; ++k) {
            int x {position.first + direction[k] };
            int y {position.second + direction[k + 1] };
            if (x >= 0 && x < m && y >= 0 && y < n && height[x][y] == -1){
                height[x][y] = height[position.first][position.second] + 1;
                queue.emplace(x, y);
            }
        }
    }
    return height;
}
