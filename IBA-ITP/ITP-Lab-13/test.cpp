#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> minimalOperations(vector<string> words) {
    vector<int> return_vec;
    for (int i = 0; i < words.size(); i++){
        int changes = 0;
        for (int j = 1; words[i].length()-1; i++){
            if (words[i][j] == words[i][j-1]){
                changes++;
                words[i][j] = 'A';
            }
        }
        return_vec.push_back(changes);
    }
    return return_vec;
}

int main() {
    vector<string> words = {"add", "boook", "break"};
    vector<int> substitutions = minimalOperations(words);
    
    cout << "Minimum substitutions: ";
    for (int i = 0; i < substitutions.size(); ++i) {
        cout << substitutions[i] << " ";
    }
    
    return 0;
}