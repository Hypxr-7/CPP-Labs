#include <iostream>
#include <vector>
#include <chrono>
#include "Seq.h"

using namespace std;
using namespace std::chrono;

int main() {
    int size = 1000000;
    Seq<int> s;
    vector<int> v;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        s.add(i);
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by Seq: " << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        v.push_back(i);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by Vector: " << duration.count() << " microseconds" << endl;

    return 0;
}