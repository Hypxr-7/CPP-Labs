#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

string formatStr(string str){
    string newStr;
    for (char c : str){
        if (!ispunct(c)){
            newStr += tolower(c);
        }
    }

    return newStr;
}

map<string, vector<int>> createIndex(string fileName){
    map<string, vector<int>> index;
    string line;
    int lineNumber = 1;
    ifstream file(fileName);

    while (getline(file, line)){
        stringstream ss(line);
        string word;

        while (ss >> word){
            word = formatStr(word);
            index[word].push_back(lineNumber);
        }
        lineNumber++;
    }

    file.close();
    return index;
}

void printIndex(const map<string, vector<int>>& index){
    for (auto entry : index){
        cout << entry.first << ": ";
        for (int i = 0; i < entry.second.size(); ++i){
            cout << entry.second[i];
            if (i != entry.second.size()-1){
                cout << "-";
            }
        }
        cout << endl;
    }
}

int main(){
    string fileName;
    cin >> fileName;
    auto index = createIndex(fileName);
    printIndex(index);

    return 0;
}
