#include <iostream>
#include <fstream>
#include <set>
#include <string>

using std::cout, std::cin, std::endl, std::ifstream, std::string, std::set;

int main() {
    ifstream ifs("words.txt");
    string line;

    set<string> words;
    while(getline(ifs, line)) {
        words.insert(line);
    }  

    string line_2;
    cout << "Enter word: ";
    cin >> line_2;

    if (words.find(line_2) == words.end()){
        cout << "Word not found";
    }
    else{
        cout << "Word found";
    }
return 0;
}