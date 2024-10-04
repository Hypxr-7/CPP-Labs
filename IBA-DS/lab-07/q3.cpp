/*
* Generate a maze using the union find data structure
*/


#include <iostream>
#include <vector>
#include <utility>
#include <random>
#include "RandomizedQueue.hpp"
#include "WeightedQuickUnionPathCompressionUF.hpp"


std::vector<std::pair<int, int>> createMaze(int n);
void drawMaze(int n, const std::vector<std::pair<int, int>>& connections);


int main() {
    constexpr int n = 15; // Size of the n x n grid
    
    std::vector<std::pair<int, int>> connections = createMaze(n);
    drawMaze(n, connections);

    return 0;
}


void drawMaze(int n, const std::vector<std::pair<int, int>>& connections) {
    std::vector<std::vector<char>> grid(n * 2 + 1, std::vector<char>(n * 2 + 1, '#'));

    // Initialize the grid with spaces
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i * 2 + 1][j * 2 + 1] = ' '; //skips every other row and column, essentially making a tile pattern
        }
    }

    // Apply the connections
    for (const auto& [x, y] : connections) {
        int x1 = x / n, y1 = x % n;
        int x2 = y / n, y2 = y % n;
        if (x1 == x2) {
            grid[x1 * 2 + 1][std::min(y1, y2) * 2 + 2] = ' '; // connection in same row
        } else {
            grid[std::min(x1, x2) * 2 + 2][y1 * 2 + 1] = ' '; // connection in different rows
        }
    }

    // Mark the start point with 'S'
    grid[1][1] = 'S';

    // Mark the end point with 'E'
    grid[n * 2 - 1][n * 2 - 1] = 'E';

    // Print the grid
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell;
        }
        std::cout << '\n';
    }
}


std::vector<std::pair<int, int>> createMaze(int n) {
    RandomizedQueue<std::pair<int, int>> edges;
    
    // Generate all connections in an N-by-N grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < n - 1) edges.enqueue({i * n + j, (i + 1) * n + j}); // Vertical connection
            if (j < n - 1) edges.enqueue({i * n + j, i * n + j + 1});   // Horizontal connection
        }
    }

    int start = 0;
    int end = n * n - 1;

    WeightedQuickUnionPathCompressionUF uf(n * n);
    std::vector<std::pair<int, int>> connections;

    // repeat until all sites are connected or no more edges left
    while (uf.countComponents() != 1 && !edges.empty()) {
        auto [x, y] = edges.dequeue();

        // if edges are not connected, connect and add to connections
        if (!uf.connected(x, y)) {
            uf.merge(x, y);
            connections.push_back({x, y});
        }
    }

    return std::move(connections); // returning a vector is expensive
}
