#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> v = {1, 3, 8, 6, 4, 5, 7, 2, 0, 9};
    int count = 0;

    std::sort(v.begin(), v.end(), [&count](int a, int b){
        count++;
        return a < b;
    });

    cout << "Comparisons: " << count;


    return 0;
}