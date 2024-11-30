#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#include "DepthFirstPaths.hpp"
#include "Graph.hpp"

int main() {
    int vertices, edges;
    std::cin >> vertices >> edges;

    Graph graph(vertices);

    int v1, v2;
    while (std::cin >> v1 >> v2)
        graph.addEdge(v1, v2);

    std::vector<bool> visited(vertices, false);
    std::set<std::vector<int>> uniqueComponents;

    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            DepthFirstPaths dfsPaths(graph, i);
            std::vector<int> component;

            for (int j = 0; j < vertices; ++j) {
                if (dfsPaths.hasPathTo(j) && !visited[j]) {
                    component.push_back(j);
                    visited[j] = true;
                }
            }

            std::sort(component.begin(), component.end());
            uniqueComponents.insert(component);
        }
    }

    std::cout << "Number of connected components: " << uniqueComponents.size() << '\n';

    for (const auto& component : uniqueComponents) {
        static int i = 1;
        std::cout << "Components " << i << ": ";
        for (const int vertex : component)
            std::cout << vertex << " ";
        ++i;
        std::cout << "\n";
    }

    return 0;
}
