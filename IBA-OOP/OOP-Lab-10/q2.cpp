#include <iostream>
#include <string>
#include <fstream>
#include "graph.hpp"
#include "path_finder.hpp"

#define START 1
#define END 2

using namespace std;

// .\q1.exe "Vera, Billy" "Landis, Pete"
// Above prompt gives bacon no. of 4

int main(int argc, char *argv[]){
    if (argc != 3){
        cerr << "Missing command line arguments";
        return 1;
    }

    string fileName = "cast.06.txt";
    char delim = '/';

    Graph graph(fileName, delim);

    try{
        PathFinder pf(graph, argv[START]);
        if (pf.hasPathTo(argv[END])){

            vector<string> path = pf.pathTo(argv[END]);

            for (auto it = path.rbegin(); it != path.rend(); ++it){
                cout << *it << '\n';
            }

            cout << "Bacon Number: " << (path.size() - 1) / 2;
        }
    }
    catch (invalid_argument){
        cerr << argv[START] << " not in file";
    }

    return 0;
}