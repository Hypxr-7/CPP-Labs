#include <iostream>

int main() 
{
    std::cout << "Enter Multiplication Table: ";
    int n;
    std::cin >> n;
    int i = 1;
    
    while (i < 11)
    {
        std:: cout << n << " * " << i << " = " << n*i << std::endl;
        i = i + 1;
    }
}