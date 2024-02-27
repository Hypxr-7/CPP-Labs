#include <iostream>

int main()
{
    std::cout << "Enter temperature in farenheit: ";
    float temp_f;
    std::cin >> temp_f;
    
    float temp_c;
    temp_c = (temp_f - 32) * 5/9;
    
    std::cout << "Temperature: " << temp_c << " °C";
}