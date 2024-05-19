#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<std::pair<double, double>> v {{1.1, 2.1},
                                              {3.45, 9.87},
                                              {4.5, 7.68},
                                              {3.21, 7.13}};

    std::sort(v.begin(), v.end(), [](auto a, auto b){ return (a.first * a.second) < (b.first * b.second); });

    for (auto pair : v)
        std::cout << pair.first * pair.second << ' ';
    std::cout << '\n';

    return 0;
}