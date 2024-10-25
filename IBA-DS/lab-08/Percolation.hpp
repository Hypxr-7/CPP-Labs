#pragma once

#include <cassert>
#include <stdexcept>
#include <vector>

class Percolation {
private:
    std::vector<std::vector<bool>> openPairs;
    std::vector<int> id;
    std::vector<int> sz;
    int n;

    int find(int p) {
        while (p != id[p]) p = id[p];
        return p;
    }

    void unionSites(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;

        if (sz[rootP] < sz[rootQ]) {
            id[rootP] = rootQ;
            sz[rootQ] += sz[rootP];
        } else {
            id[rootQ] = rootP;
            sz[rootP] += sz[rootQ];
        }
    }

public:
    // creates n-by-n grid, with all sites initially blocked
    Percolation(int n) : openPairs(n, std::vector<bool>(n, false)), id(n * n + 2), sz(n * n + 2, 1), n(n) {
        if (n <= 0) throw std::invalid_argument("n can not be less than or equal to 0");

        for (int i = 0; i < n * n; ++i) {
            id[i] = i;
        }
        id[n * n] = n * n; // virtual top site
        id[n * n + 1] = n * n + 1; // virtual bottom site
    }

    // opens the site (row, col) if it is not open already
    void open(int row, int col) {
        if (row < 0 || row >= n || col < 0 || col >= n)
            throw std::invalid_argument("Out of range");

        if (!openPairs[row][col]) {
            openPairs[row][col] = true;
            int index = row * n + col;

            if (row == 0) {
                unionSites(index, n * n); // connect to virtual top site
            }
            if (row == n - 1) {
                unionSites(index, n * n + 1); // connect to virtual bottom site
            }
            if (row > 0 && isOpen(row - 1, col)) { 
                unionSites(index, (row - 1) * n + col); // connect if up open
            }
            if (row < n - 1 && isOpen(row + 1, col)) {
                unionSites(index, (row + 1) * n + col); // connect if down open
            }
            if (col > 0 && isOpen(row, col - 1)) {
                unionSites(index, row * n + col - 1); // connect if left open
            }
            if (col < n - 1 && isOpen(row, col + 1)) {
                unionSites(index, row * n + col + 1); // connect if right open
            }
        }
    }

    // is the site (row, col) open?
    bool isOpen(int row, int col) {
        if (row < 0 || row >= n || col < 0 || col >= n)
            throw std::invalid_argument("Out of range");

        return openPairs[row][col];
    }

    // is the site (row, col) full?
    bool isFull(int row, int col) {
        if (row < 0 || row >= n || col < 0 || col >= n)
            throw std::invalid_argument("Out of range");

        int index = row * n + col;
        return isOpen(row, col) && find(index) == find(n * n); // Checks if connected to top site
    }

    // returns the number of open sites
    int numberOfOpenSites() {
        int count = 0;
        for (const auto& row : openPairs) {
            for (bool site : row) {
                if (site) ++count;
            }
        }
        return count;
    }

    // does the system percolate?
    bool percolates() {
        return find(n * n) == find(n * n + 1); // Checks if bottom site connected to top site
    }

    // unit testing (required)
    static void test() {
        Percolation perc(3);
        perc.open(0, 0);
        perc.open(1, 0);
        perc.open(2, 0);

        assert(perc.percolates() && "Test failed: System should percolate.");
        assert(perc.numberOfOpenSites() == 3 && "Test failed: Number of open sites should be 3.");
        assert(perc.isOpen(0, 0) && perc.isOpen(1, 0) && perc.isOpen(2, 0) && "Test failed: Sites (0,0), (1,0), and (2,0) should be open.");
        assert(perc.isFull(0, 0) && perc.isFull(1, 0) && perc.isFull(2, 0) && "Test failed: Sites (0,0), (1,0), and (2,0) should be full.");

        perc.open(1, 2);
        assert(perc.isOpen(1, 2) && "Test failed: Site (1,1) should be open.");
        assert(!perc.isFull(1, 2) && "Test failed: Site (1,1) should not be full.");
    }
};