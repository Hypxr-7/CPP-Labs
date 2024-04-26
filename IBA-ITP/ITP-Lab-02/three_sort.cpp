#include <iostream>
#include <cmath>

int main()
{
    int num1, num2, num3;
    std::cout << "Enter Num 1: ";
    std::cin >> num1;
    std::cout << "Enter Num 2: ";
    std::cin >> num2;
    std::cout << "Enter Num 3: ";
    std::cin >> num3;

    int max = fmax(fmax(num1, num2), num3);
    int min = fmin(fmin(num1, num2), num3);
    int mid = num1 + num2 + num3 - max - min;

    std::cout << min << std::endl;
    std::cout << mid << std::endl;
    std::cout << max << std::endl;
}