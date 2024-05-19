#include <iostream>
#include <complex>

int main() {

    auto multiply = [](const auto& x, const auto& y){ return x*y; };

    using namespace std::literals;
    std::cout
            << multiply(2, 3) << " "
            << multiply(0.5, 2.0) << " "
            << multiply(2, 0.25) << " "
            << multiply(1.0 + 1.0i, 1.0 - 1.0i) << "\n";

    return 0;
}