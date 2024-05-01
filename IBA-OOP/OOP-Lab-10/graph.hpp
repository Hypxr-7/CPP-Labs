#pragma once

/******************************************************************************
 *  Undirected graph data type implemented using a symbol table
 *  whose keys are vertices (std::string) and whose values are sets
 *  of neighbors (std::set of strings).
 *
 *  Remarks
 *  -------
 *   - Parallel edges are not allowed
 *   - Self-loop are allowed
 *
 *  Example: tinyGraph.txt
 *  A B C G H
 *  B A C H
 *  C A B G
 *  G A C
 *  H A B
 ******************************************************************************/

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <exception>

using std::string, std::getline, std::ifstream, std::cout, std::cerr;


class Graph {
    // vmap: key = string vertex, value = set of neighboring vertices
    using vmap=std::unordered_map<string, std::unordered_set<string>>;
    using vmap_iterator=vmap::iterator;

    vmap st;

    // number of edges
    int edges_count = 0;

    // throw an exception if v is not a vertex
    void validateVertex(string v) {
        if (!hasVertex(v)) throw std::invalid_argument(v + " is not a vertex");
    }

public:
    // Initializes an empty graph with no vertices or edges. 
    Graph() = default;

     // Initializes a graph from the specified file, using the specified delimiter.
    Graph(string filename, char delimiter) {
        ifstream file(filename);
        if(!file.is_open()) {
            cerr << "Unable to open file " << filename << "\n";
            return;
        }
        string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            string v;
            getline(iss, v, delimiter); 
            //cerr << "Adding vertex [" << v << "]\n";
            addVertex(v);
            string w;
            while (getline(iss, w, delimiter)) { // while there are more tokens 
                //cerr << "\tAdding edge [" << v << " - " << w << "]\n";
                addVertex(w);
                addEdge(v, w);
            }
        }
        file.close();
    }

    // Returns the number of vertices in this graph.
    int V() {
        return st.size();
    }

    // Returns the number of edges in this graph.
    int E() {
        return edges_count;
    }

    // Returns the degree of vertex v in this graph.
     int degree(string v) {
        validateVertex(v);
        return st[v].size();
    }

     // Adds the edge v-w to this graph (if it is not already an edge).
    void addEdge(string v, string w) {
        if (!hasVertex(v)) addVertex(v);
        if (!hasVertex(w)) addVertex(w);
        if (!hasEdge(v, w)) { 
            edges_count++;
            st[v].insert(w);
            st[w].insert(v);
        }
    }

    // Adds vertex v to this graph (if it is not already a vertex).
    void addVertex(string v) {
        if (!hasVertex(v)) st.insert({v,std::unordered_set<string>()});
    }

    // Returns true if v is a vertex in this graph.
    bool hasVertex(string v) {
        return st.find(v) != st.end();
    }

    // Returns true if v-w is an edge in this graph.
    bool hasEdge(string v, string w) {
        validateVertex(v);
        validateVertex(w);
        return st[v].find(w) != st[v].end();
    }

     // Returns a string representation of this graph.
    string toString() {
        string s;
        for (auto v : st) {
            s += v.first + ": ";
            for (auto w : v.second) {
                s += w + " ";
            }
            s += "\n";
        }
        return s;
    }

    const std::unordered_set<string>& adjacentTo(string v) {
        validateVertex(v);
        return st[v];
    }

    class vertex_iterator : public vmap_iterator {
    public:
        vertex_iterator(vmap_iterator it) : vmap_iterator(it) {}

        string operator*() {
            return vmap_iterator::operator*().first;
        }
        string* operator->() {
            return (string*) &(vmap_iterator::operator*().first);
        }
    };

    vertex_iterator vbegin() {
        return vertex_iterator(st.begin());
    }

    vertex_iterator vend() {
        return vertex_iterator(st.end());
    }

};
