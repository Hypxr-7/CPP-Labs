#include <iostream>
#include <chrono>
#include <vector>

std::vector<int> getVector1(int n){
    std::vector<int> result;
    for (int i = 0; i < n; ++i)
        result.push_back(i);
    return result;
}

std::vector<int> getVector2(int n){
    std::vector<int> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i)
        result.push_back(i);
    return result;
}

void timeTaken(std::vector<int> (*func)(int), int n){
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    func(n);
    auto end = high_resolution_clock::now();

    duration<double> duration = end - start;

    std::cout << "Execution Time: " << duration.count() << '\n';
}


int main(){
    timeTaken(&getVector1, 16'777'216);
    timeTaken(&getVector2, 16'777'216);


    return 0;
}