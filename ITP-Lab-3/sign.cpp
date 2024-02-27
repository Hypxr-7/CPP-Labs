#include <iostream>

int main() {
    std::cout << "Enter Num: ";
    int num;
    std::cin >> num;
    if (num > 0)
        std::cout << "Positive";
    if (num == 0)
        std::cout << "Zero";
    if (num < 0)
        std::cout << "Negative";
}