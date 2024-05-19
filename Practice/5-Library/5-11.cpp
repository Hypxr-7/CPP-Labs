#include <iostream>
#include <vector>
#include <algorithm>

void transform_quadratic(std::vector<int>& v, double a, double b, double c){
    std::transform(v.begin(), v.end(), v.begin(), [&a, &b, &c](int x){
        return a*x*x + b*x + c;
    });
}

int main(){
    std::vector<int> v {-2, -1, 0, 1, 2, 3, 4, 5, 6};

    std::cout << "x: ";
    for (const int& x : v)
        std::cout << x << ' ';
    std::cout << '\n';

    transform_quadratic(v, 1, -4, 4);
    std::cout << "y = x^2 - 4x + 4: ";
    for (const int& y : v)
        std::cout << y << ' ';
    std::cout << '\n';

    return 0;
}