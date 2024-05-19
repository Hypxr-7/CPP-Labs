#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <string>
#include <iterator>

template<typename T1, typename T2, typename T3>
void merge(T1 input1, T2 input2, T3& output){
    std::copy(input1.begin(), input1.end(), std::inserter(output, output.end()));
    std::copy(input2.begin(), input2.end(), std::inserter(output, output.end()));
}

template<typename T>
std::ostream& output(std::ostream& os, const T& container){
    for (const auto& element : container)
        os << element << ' ';
    return os;
}

int main(){
    const std::vector<std::string> c1{"delta", "beta", "alpha"};
    const std::list<std::string> c2{"delta", "beta", "alpha"};
    const std::set<std::string> c3{"one", "two", "four"};

    std::vector<std::string> d1;
    merge(c1, c2, d1);
    output(std::cout, d1) << "\n";

    std::list<std::string> d2;
    merge(c2, c3, d2);
    output(std::cout, d2) << "\n";

    std::set<std::string> d3;
    merge(c3, c1, d3);
    output(std::cout, d3) << "\n";

    return 0;
}