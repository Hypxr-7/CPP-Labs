#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>

using namespace std;

int main(){
    unordered_set<string> visited;
    string line;
    while (getline(cin, line)){
        if (visited.find(line) != visited.end()) {
            cout << "purple\n";
        }
        else {
            visited.insert(line);
            cout << "blue\n";
        }
    }

    return 0;
}
