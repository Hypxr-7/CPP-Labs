#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include "graph.hpp"
#include "path_finder.hpp"


#define FILENAME 1
#define START 2
#define END 3


using namespace std;


set<string> InitWordList(string fileName);                                 
// Returns a set of words from the argument file name


set<string> GetValidWordsList(set<string> &wordList, string sourceWord);    
// Returns valid words from the argument set
// Also removes the current word from main set


bool ValidWord(string w1, string w2);                                      
// Returns true if the difference is that a single letter is different


void AddToGraph(Graph &graph, set<string> edges, string word);
// Add the set of edges to the vertex word


// Command Line Arguments: <filename> <start> <end>
int main(int argc, char *argv[]) {
    // Validation
    if (argc != 4){
        cerr << "Missing arguments";
        return 1;
    }
    if (argv[2] == argv[3]){
        cerr << "Beta baaz ajao";
        return 2;
    }

    Graph graph;
    set<string> wordList = InitWordList(argv[FILENAME]);


    // Sets up the graph
    while (!wordList.empty()) {
        auto word = *wordList.begin();
        set<string> validList = GetValidWordsList(wordList, word);
        AddToGraph(graph, validList, word);
    }


    // cout << "Edges: " << graph.E() << "\n";
    // cout << "Verices: " << graph.V() << "\n";
    // Final vertices count will be less than the initial words in text file as some words do not have a matching word with single letter change
    // These words are not added 
    
    // Finds path
    PathFinder pf(graph, argv[START]);

    if (pf.hasPathTo(argv[END])){
        std::vector<string> path = pf.pathTo(argv[END]);
        for (auto it = path.rbegin(); it != path.rend() - 1; ++it) {
            cout <<  *it << " --> ";
        }
        cout << path.front() << '\n'; 
    }
    else{
        cout << "Path does not exist\n"; 
    }

    
    return 0;
}


set<string> InitWordList(string fileName) {
    ifstream handle(fileName);
    if (!handle.is_open()){
        cerr << "File not found";
    }

    string line;
    set<string> wordList;
    while (getline(handle, line)){
        wordList.insert(line);
    }
    handle.close();

    return wordList;
}


set<string> GetValidWordsList(set<string> &wordList, string sourceWord) {
    set<string> newWordList;
    for (string currentWord : wordList){
        if (currentWord == sourceWord){
            continue;
        }
        if (ValidWord(currentWord, sourceWord)) {
            newWordList.insert(currentWord);
        }
    }

    wordList.erase(sourceWord);

    return newWordList;
}


bool ValidWord(string w1, string w2) {
    int different = 0;
    for (int i = 0; i < w1.size(); ++i){
        if (w1[i] != w2[i]){
            different++;
        }
    }
    return different == 1;
}


void AddToGraph(Graph &graph, set<string> edges, string word) {
    for (string item : edges){
        graph.addEdge(word, item);
    }
}