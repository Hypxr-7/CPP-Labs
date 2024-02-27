#include <iostream>

int main() {
    std::cout << "Enter Month: ";
    int month;
    std::cin >> month;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month ==12)
        std::cout << "31 days";
    if (month == 4 || month == 6 || month == 9 || month == 11)
        std::cout << "30 days";
    if (month == 2)
    {
        std::cout << "Enter Year: ";
        int year;
        std::cin >> year;
        if (year%4 == 0 && year%100 != 0)
            std::cout << "29 days";
        else if (year%400 == 0)
            std::cout << "29 days";
        else
            std::cout << "28 days";
    }
}