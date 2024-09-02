#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

constexpr int N = 400;

void linear(std::vector<int>& vec);
void linearLog(std::vector<int>& vec);
void cube(std::vector<int>& vec);
void callAllFunctions(std::vector<int>& vec);

int main() {
    std::vector<int> vec;

    callAllFunctions(vec);

    return 0;
}

void linear(std::vector<int>& vec) {
    // O(n)
    // initializes the array  

    std::mt19937 mt(std::random_device{}());
    std::uniform_int_distribution<int> dist(-50, 50);

    auto start = clock();
    for (int i = 0; i < N; ++i) 
        vec.push_back(dist(mt));
    auto end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time Taken By Linear: " << time << " seconds\n";
}

void linearLog(std::vector<int>& vec) {
    // O(n·log(n))
    // sorting the array 
    // complexity verified by https://en.cppreference.com/w/cpp/algorithm/sort#Complexity
    auto start = clock();
    std::sort(vec.begin(), vec.end());
    auto end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time Taken By Linear-Log: " << time << " seconds\n";
}

void cube(std::vector<int>& vec) {
    // O(n³)
    auto start = clock();
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                if (vec[i] == vec[j] && vec[j] == vec[k]); // TODO: do something
    auto end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time Taken By Cubic: " << time << " seconds\n";
}

void callAllFunctions(std::vector<int>& vec) {
    auto start = clock();
    linear(vec);
    linearLog(vec);
    cube(vec);
    auto end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time Taken By All: " << time << " seconds\n";
}
