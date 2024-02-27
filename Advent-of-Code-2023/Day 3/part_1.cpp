#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool isSymbol(char c) {
    return c != '.' && !isdigit(c);
}

bool checkAroundNum(vector<string>& vs, int i, int j){
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int k = 0; k < 8; k++){
        int ni = i + dx[k], nj = j + dy[k];
        if(ni >= 0 && ni < vs.size() && nj >= 0 && nj < vs[0].size() && isSymbol(vs[ni][nj])){
            return true;
        }
    }
    return false;
}

int main() {
    ifstream ifs("input.txt");
    string line;
    vector<string> lines;
    while (getline(ifs, line)) {
        lines.push_back(line);
    }
    int sum = 0;
    for (int i = 0; i < lines.size(); i++){
        for(int j = 0; j < lines[i].size(); j++){
            if(isdigit(lines[i][j])){
                int start = j;
                while(j < lines[i].size() && isdigit(lines[i][j])) j++;
                if(checkAroundNum(lines, i, start) || checkAroundNum(lines, i, j - 1)){
                    sum += stoi(lines[i].substr(start, j - start));
                }
            }
        }
    }
    cout << "Sum of all part numbers: " << sum << endl;
    return 0;
}