#pragma once

#include <vector>
#include "digraph.hpp"

class DepthFirstOrder {
    std::vector<bool> _marked;
    std::vector<int> _reversePostorder;

public:
    DepthFirstOrder(const Digraph &G) : _marked(G.V(), false) {
        _reversePostorder.reserve(G.V());
        for (int v = 0; v < G.V(); ++v) {
            if (!_marked[v]) {
                dfs(G, v);
            }
        }
    }

    const std::vector<int>& reversePostorder() const {
        return _reversePostorder;
    }

private:
    void dfs(const Digraph &G, int v) {
        _marked[v] = true;
        for (int w : G.adj(v)) {
            if (!_marked[w]) {
                dfs(G, w);
            }
        }
        _reversePostorder.push_back(v);
    }
};
