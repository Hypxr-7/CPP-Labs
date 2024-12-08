#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

#include "digraph.hpp"

bool hasPath(const Digraph& graph, const int source, const int target) {
    if (source == target) return true;

    std::vector visited(graph.V(), false);
    std::queue<int> queue;

    visited[source] = true;
    queue.push(source);

    while (!queue.empty()) {
        const int current = queue.front();
        queue.pop();

        for (int neighbor : graph.adj(current)) {
            if (!visited[neighbor]) {
                if (neighbor == target) return true;
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }

    return false;
}

int main() {
    // Example graph input: 5 vertices, 4 edges: 0->1, 0->2, 1->3, 3->4
    std::istringstream input(
        "5 4\n"
        "0 1\n"
        "0 2\n"
        "1 3\n"
        "3 4");

    Digraph graph(input);

    if (constexpr int source = 0, target = 4; hasPath(graph, source, target))
        std::cout << "Path exists from " << source << " to " << target << ".\n";
    else
        std::cout << "No path from " << source << " to " << target << ".\n";

    return 0;
}
