#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> v {1, 3, 8, 6, 4, 5, 7, 2, 0, 9};

    std::sort(v.begin(), v.end(), [](int a, int b){ return a > b; });

    for (auto i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}