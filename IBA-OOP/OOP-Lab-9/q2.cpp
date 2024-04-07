#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <unordered_set>
#include <format>

using namespace std;

int uniqueSubStrCount(const string& str, int L){
    unordered_set<string> subStrings;
    for (int i = 0; i < str.length() - L; ++i){
        subStrings.insert(str.substr(i, L));
    }

    return subStrings.size();
}

int main(){
//    ifstream fileHandle("pi-1million.txt");
//    ifstream fileHandle("pi-10million.txt");

//    assert(fileHandle.is_open());


    string str;

//    getline(fileHandle, str);

    cout << "Enter: ";
    cin >> str;

    int L;
    cout << "Enter L: ";
    cin >> L;

    int count = uniqueSubStrCount(str, L);

    cout << format("Substrings of length {0} : {1}", L, count) << endl;

    return 0;
}