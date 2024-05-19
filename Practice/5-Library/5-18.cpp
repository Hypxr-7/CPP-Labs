#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> v {5, 10, 6, 4, 3, 2, 6, 7, 9, 3, 9};

//    int n;
//    while (std::cin >> n)
//        v.push_back(n);

    size_t mid = v.size() / 2;
    std::nth_element(v.begin(), v.begin() + mid, v.end());

    double median;
    if (v.size() % 2 == 0) {
        std::nth_element(v.begin(), v.begin() + mid - 1, v.end());
        median = (v[mid] + v[mid - 1]) / 2.0;
    } else {
        median = v[mid];
    }

    std::cout << "Median: " << median << '\n';

    return 0;
}