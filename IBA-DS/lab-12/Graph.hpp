#pragma once

#include <cassert>
#include <forward_list>
#include <iostream>
#include <limits>
#include <vector>

class Graph {
private:
    int m;  // Number of edges
    std::vector<std::forward_list<int>> adj;

    bool isVertexValid(const int v) const {
        return (v >= 0 && v < V());
    }

public:
    Graph(const int vertices) : m(0), adj(vertices) {}

    int V() const { return adj.size(); }

    int E() const { return m; }

    void addEdge(const int v1, const int v2) {
        assert(isVertexValid(v1));
        assert(isVertexValid(v2));

        ++m;
        adj.at(v1).push_front(v2);
        adj.at(v2).push_front(v1);
    }

    int degree(const int v) const {
        assert(isVertexValid(v));
        return std::distance(adj.at(v).begin(), adj.at(v).end());
    }

    int maxDegree() const {
        int max = -1;
        int maxV;
        for (int vertex = 0; vertex < V(); ++vertex) {
            if (degree(vertex) > max) {
                max = degree(vertex);
                maxV = vertex;
            }
        }
        return maxV;
    }

    int minDegree() const {
        int min = std::numeric_limits<int>::max();
        int minV;
        for (int vertex = 0; vertex < V(); ++vertex) {
            if (degree(vertex) < min) {
                min = degree(vertex);
                minV = vertex;
            }
        }
        return minV;
    }

    void print() {
        std::cout << "Vertex with maximum degree: " << maxDegree() << '\n';
        std::cout << "Vertex with minimum degree: " << minDegree() << '\n';

        for (int i = 0; i < adj.size(); ++i)
            std::cout << "Vertex: " << i << " Degree: " << degree(i) << '\n';
    }
};