#include <iostream>

template <char... Digits>
constexpr long long operator"" _4() {
    constexpr char digits[] = {Digits...};
    long long result = 0;
    for (char digit : digits) {
        result = result * 4 + (digit - '0');
    }
    return result;
}

int main() {
    // Output 1 4 16
    std::cout << 1_4 << " " << 10_4 << " " << 100_4 << "\n";
    // Output -1 -4 -16
    std::cout << -1_4 << " " << -10_4 << " " << -100_4 << "\n";
    // Output 228 27
    std::cout << 3210_4 << " " << 0123_4 << "\n";
    // Output -228 -27
    std::cout << -3210_4 << " " << -0123_4 << "\n";

    return 0;
}

