#include <iostream>
#include <chrono>
#include <vector>

int calcSum1(const std::vector<int>& v){
    int sum = 0;
    for (auto i = v.begin(); i != v.end(); ++i)
        sum += *i;
    return sum;
}

int calcSum2(const std::vector<int>& v){
    int sum = 0;
    for (int i = 0; i < v.size(); ++i)
        sum += v[i];
    return sum;
}

void timeTaken(int (*func)(const std::vector<int>&), const std::vector<int>& v){
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    func(v);
    auto end = high_resolution_clock::now();

    duration<double> duration = end - start;

    std::cout << "Execution Time: " << duration.count() << '\n';
}

std::vector<int> getRandomIntVector(int size) {
    std::vector<int> result(size);
    for (int i = 0; i < size; ++i)
        result[i] = i;
    return result;
}

int main(){
    std::vector<int> v = getRandomIntVector(16'777'216);

    timeTaken(&calcSum1, v);
    timeTaken(&calcSum2, v);

    return 0;
}