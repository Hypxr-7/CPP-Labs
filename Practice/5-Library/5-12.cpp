#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(const std::vector<double>& v, int& num_compares){
    return std::is_sorted(v.begin(), v.end(), [&num_compares](int a, int b){
        ++num_compares;
        return a < b;
    });
}

int main(){
    std::vector<double> v1 {1.2, 2.3, 3.4, 4.5, 5.6};
    std::vector<double> v2 {3.2, 1.5, 4.7, 2.3, 5.0};

    int compares = 0;
    std::cout << "v1 is " << (is_sorted(v1, compares) ? "sorted\n" : "not sorted\n");
    std::cout << "Compares: " << compares << '\n';

    compares = 0;
    std::cout << "v1 is " << (is_sorted(v2, compares) ? "sorted\n" : "not sorted\n");
    std::cout << "Compares: " << compares << '\n';

    return 0;
}