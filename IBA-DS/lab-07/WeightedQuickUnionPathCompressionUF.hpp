#pragma once

#include <vector>

class WeightedQuickUnionPathCompressionUF {
public:
    WeightedQuickUnionPathCompressionUF(int n) : parent(n), size(n, 1), count(n) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int p) {
        while (p != parent[p]) {
            parent[p] = parent[parent[p]]; // Path compression
            p = parent[p];
        }
        return p;
    }

    void merge(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        } else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--; // Decrease the number of components
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int countComponents() const {
        return count;
    }

private:
    std::vector<int> parent;
    std::vector<int> size;
    int count; // Number of components
};
