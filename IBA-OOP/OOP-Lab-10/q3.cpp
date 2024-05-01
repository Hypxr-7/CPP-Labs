#include <iostream>
#include <string>
#include <fstream>
#include <format>
#include "graph.hpp"
#include "path_finder.hpp"


using namespace std;

int main(){
    string fileName = "movies.txt";
    char delim = '/';
    Graph graph(fileName, delim);

    cout << "Vertices: " << graph.V() << '\n';
    cout << "Edges: " << graph.E() << '\n';

    string start = "Bacon, Kevin";
    PathFinder pf(graph, start);

    const int maxSize = 100;
    int histogram[maxSize + 1]= {};
    for (auto it = graph.vbegin(); it != graph.vend(); ++it){
        auto actor = *it;
        if (pf.distanceTo(actor) % 2 != 0){
            continue;   // skip movies
        } 

        int baconNumber = min(pf.distanceTo(actor) / 2, maxSize);
        histogram[baconNumber]++;
    }

    for (int i = 0; i < maxSize; i++){
        if (histogram[i] == 0){
            break;
        }
        // {:^10} is used in std::format() to set 10 character spaces for the variable and then center it
        cout << format("{:^10} : {:^10}", i, histogram[i]) << '\n';
        // cout << i << '\t' << histogram[i] << '\n';
    }
    cout << format("{:^10} : {:^10}", "Inf", histogram[maxSize]) << '\n';
    // cout << "Inf" << '\t' << histogram[maxSize] << '\n';

    return 0;
}