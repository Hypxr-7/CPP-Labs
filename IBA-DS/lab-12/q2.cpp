// q2.exe < input.txt

#include <iostream>

#include "Graph.hpp"

int main() {
    int n;
    std::cin >> n;

    Graph graph(n);

    int v1, v2;
    while (std::cin >> v1 >> v2)
        graph.addEdge(v1, v2);

    graph.print();

    return 0;
}