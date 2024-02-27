#include <iostream>

int main()
{
    std::cout << "Enter: Length: ";
    float length;
    std::cin >> length;
    
    std::cout << "Enter Width: ";
    float width;
    std::cin >> width;
    
    std::cout << length * width;
}