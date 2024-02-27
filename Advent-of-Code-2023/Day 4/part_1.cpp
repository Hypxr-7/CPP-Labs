#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int compareMatches(const vector<string>& v, int i){
    int wnumPosn[10] = {stoi(v[i].substr(10, 2)), 
                        stoi(v[i].substr(13, 2)), 
                        stoi(v[i].substr(16, 2)), 
                        stoi(v[i].substr(19, 2)), 
                        stoi(v[i].substr(22, 2)), 
                        stoi(v[i].substr(25, 2)),
                        stoi(v[i].substr(28, 2)),
                        stoi(v[i].substr(31, 2)),
                        stoi(v[i].substr(34, 2)),
                        stoi(v[i].substr(37, 2))};
    int match = 0;
    for (int k = 42; k < 115; k+= 3){
        int num = stoi(v[i].substr(k, 2));
        for (int j = 0; j < 10; j++){
            if (num == wnumPosn[j]){
                match++;
            }
        }
    }
    return match;
}

int main(){
    ifstream ifs("input.txt");
    string lines;
    vector<string> input;
    while (getline(ifs, lines)){
        input.push_back(lines);
    }
    int sum = 0;
    for (int i = 0; i < input.size(); i++){
        int matches = compareMatches(input, i);
        if (matches != 0){
            sum += pow(2, matches-1);
        }
    }
    cout << sum << endl;

    return 0;
}
