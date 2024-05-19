#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main(){
    std::vector<int> vec {1, 3, 8, 6, 4, 5, 7, 2, 0, 9};
    std::set<int> infinities {3, 2};

    auto compare = [&infinities](int a, int b){
        if (infinities.contains(a)) return false;
        if (infinities.contains(b)) return true;
        return a < b;
    };

    std::stable_sort(vec.begin(), vec.end(), compare);

    for (auto i : vec)
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}