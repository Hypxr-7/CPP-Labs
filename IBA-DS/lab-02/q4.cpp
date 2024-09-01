#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <algorithm>


constexpr int N = 10000;

void myFunc();

int main() {
    clock_t start = clock();
    myFunc();
    clock_t end = clock();

    double time = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time Taken: " << time << " seconds\n";

    return 0;
}

void myFunc() {
    std::mt19937 mt(std::random_device{}());
    std::uniform_int_distribution<int> dist(-50, 50);

    // O(n)
    // initializes the array  
    std::vector<int> vec;
    for (int i = 0; i < N; ++i) 
        vec.push_back(dist(mt));

    // O(n²)
    // makes a list of all possible pair permutations
    std::set<std::pair<int, int>> pairs;
    for (int i = 0; i < N; ++i) { 
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            pairs.insert(std::pair<int, int>(vec[i], vec[j])); 
        }
    }

    // O(n·log(n))
    // sorting the array 
    // complexity verified by https://en.cppreference.com/w/cpp/algorithm/sort#Complexity
    std::sort(vec.begin(), vec.end());
}