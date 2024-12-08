#include <iostream>
#include <sstream>
#include <vector>

#include "digraph.hpp"

bool dfs(const int v, const Digraph& graph, std::vector<bool>& visited,
         std::vector<bool>& onStack) {
    visited[v] = true;
    onStack[v] = true;

    for (const int neighbor : graph.adj(v))
        if (!visited[neighbor]) {
            if (dfs(neighbor, graph, visited, onStack))
                return true;
        } else if (onStack[neighbor])
            return true;

    onStack[v] = false;
    return false;
}

bool hasCycle(const Digraph& graph) {
    const int numVertices = graph.V();
    std::vector visited(numVertices, false);
    std::vector onStack(numVertices, false);

    for (int v = 0; v < numVertices; ++v)
        if (!visited[v])
            if (dfs(v, graph, visited, onStack))
                return true;

    return false;
}


int main() {
    std::istringstream input(
        "5 5\n"
        "0 1\n"
        "1 2\n"
        "2 0\n"
        "3 4\n"
        "4 3");
    Digraph graph(input);

    if (hasCycle(graph))
        std::cout << "The graph contains a cycle.\n";
    else
        std::cout << "The graph is acyclic.\n";

    return 0;
}
