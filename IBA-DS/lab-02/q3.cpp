// * as shown in q3.pdf, this algorithm is not O(n²log(n)) but O(n³) 

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <functional>

constexpr int N = 1000;

std::vector<int> initVector();
int threeSum(const std::vector<int>& v);
double calculateTime(const std::vector<int>& v, std::function<int(std::vector<int>)>);

int main() {
    std::cout << "Time Taken: " << calculateTime(initVector(), threeSum) << " seconds\n";

    return 0;
}

std::vector<int> initVector() {
    std::mt19937 mt(std::random_device{}());
    std:: uniform_int_distribution<int> dist(-10, 10);
    
    std::vector<int> v;
    for (int i = 0; i < N; ++i)
        v.push_back(dist(mt));

    return v;
}

int threeSum(const std::vector<int>& v) {
    int n = v.size();
    int count = 0;

    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) 
            for (int k = j + 1; k < n; k++) 
                if (v[i] + v[j] + v[k] == 0) 
                    count++;
                
    return count;
}

double calculateTime(const std::vector<int>& v, std::function<int(std::vector<int>)> func) {
    clock_t start = clock();
    func(v);
    clock_t end = clock();

    double time = double(end - start) / double(CLOCKS_PER_SEC);

    return time;
}
