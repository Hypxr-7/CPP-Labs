#include <iostream>

int main() 
{
    std::cout << "Enter Wind Speed: ";
    int wind_speed;
    std::cin >> wind_speed;
    
    if (wind_speed <= 73)
        std::cout << "Not a hurricane";
    if (wind_speed >= 74 && wind_speed <= 95)
        std::cout << "Category 1 Hurricane";
    if (wind_speed >= 96 && wind_speed <= 110)
        std::cout << "Category 2 Hurricane";
    if (wind_speed >= 111 && wind_speed <= 130)
        std::cout << "Category 3 Hurricane";
    if (wind_speed >= 131 && wind_speed <= 155)
        std::cout << "Category 4 Hurricane";
    if (wind_speed >= 156)
        std::cout << "Category 5 Hurricane";
}