#include <iostream>
#include <vector>
#include <algorithm>

class Compare{
public:
    bool operator()(const double& a, const double& b){
        return a > b;
    }
};

void print(const std::vector<double>& v){
    for (const auto& i : v)
        std::cout << i << ' ';
    std::cout << '\n';
}

int main(){
    std::vector<double> vec;
    double num;
    while(std::cin >> num)
        vec.push_back(num);

    // CTRL+D for end of input
    // CTRL+Z on unix

    print(vec);

    std::sort(vec.begin(), vec.end(), Compare());

    print(vec);

    return 0;
}