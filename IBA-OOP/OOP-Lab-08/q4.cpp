#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void sortStudents(vector<vector<int>>& score, int k) {
    sort(score.begin(), score.end(), ([&k](const vector<int>& v1, const vector<int>& v2) {return v1[k] > v2[k];}));
}


int main(){
    // part a
    cout << "Enter: ";
    int k;
    cin >> k;
//
//    vector<int> v1 = {1, 3, 8, 6, 4, 5, 7, 2, 0, 9};
//    vector<int> v2 = {1, 3, 5, 9};
//
//    auto comp =  ([&k](const vector<int>& v1, const vector<int>& v2) {return v1[k] == v2[k];});
//
//    cout << boolalpha <<  comp(v1, v2);


    //part b
    int m = 5;
    int n = 5;

    vector<vector<int>> score = {{10, 6, 9, 1},
                                 {7, 5, 11, 2},
                                 {4, 8, 3, 15}};

    sortStudents(score, k);

    for (auto r : score) {
        for (auto c: r) {
            cout << c << " ";
        }
        cout << endl;
    }


    return 0;
}