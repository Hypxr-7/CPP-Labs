/****************************************************************************
 *
 *  Runs breadth first search algorithm from source s on a graph G.
 *  After preprocessing the graph, can process shortest path queries
 *  from s to any vertex t.
 *
 *  Data files:   https://introcs.cs.princeton.edu/java/45graph/routes.txt
 *                https://introcs.cs.princeton.edu/java/45graph/movies.txt
 *
 *  Example run (first argument is data file, second is delimiter, third is source): 
 *  % shortest_path routes.txt " " JFK
 *  LAX
 *     JFK
 *     ORD
 *     PHX
 *     LAX
 *  distance 3
 *  MCO
 *     JFK
 *     MCO
 *  distance 1
 *  DFW
 *     JFK
 *     ORD
 *     DFW
 *  distance 2
 *
 ******************************************************************************/

#include "path_finder.hpp"

int main(int argc, char* argv[]) {
    if(argc < 4) {
        cerr << "Usage: " << argv[0] << " <filename> <delimiter> <source>\n";
        return 1;
    }

    string filename  = argv[1];
    char delimiter = argv[2][0];
    Graph G(filename, delimiter);
    string s = argv[3];
    PathFinder pf(G, s);

    string t;
    while (std::getline(std::cin, t)) {
        std::vector<string> path = pf.pathTo(t);
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            cout << "   " <<  *it << "\n";
        }
        cout << "distance " << pf.distanceTo(t) << "\n";
    }
}


