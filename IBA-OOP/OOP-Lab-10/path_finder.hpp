#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <exception>
#include <queue>
#include <vector>
#include <limits>
#include "graph.hpp"

using std::string, std::getline, std::ifstream, std::cout, std::cerr;

class PathFinder {
    // prev[v] = previous vertex on shortest path from s to v
    // dist[v] = length of shortest path from s to v
    std::unordered_map<string, string>  prev;
    std::unordered_map<string, int> dist;

    public:
    // run BFS in graph G from given source vertex s
    PathFinder(Graph G, string s) {

        // put source on the queue
        std::queue<string> qu;
        qu.push(s);
        dist[s] = 0;

        // repeated remove next vertex v from queue and insert
        // all its neighbors, provided they haven't yet been visited
        while (!qu.empty()) {
            string v = qu.front();
            qu.pop();
            for (string w : G.adjacentTo(v)) {
                // if w not already assigned a distance
                if (dist.find(w) == dist.end()) { 
                    qu.push(w);
                    dist[w] = 1 + dist[v];
                    prev[w] = v;
                }
            }
        }
    }

    // is v reachable from the source s?
    bool hasPathTo(string v) {
        return dist.find(v) != dist.end();
    }

    // return the length of the shortest path from v to s
    int distanceTo(string v) {
        if (!hasPathTo(v)) return std::numeric_limits<int>::max();
        return dist[v];
    }

    // return the shortest path from v to s as a vector
    std::vector<string> pathTo(string v) {
        std::vector<string> path;
        while (prev.find(v) != prev.end()) {
            path.push_back(v);
            v = prev[v];
        }
        path.push_back(v);
        return path;
    }
};

