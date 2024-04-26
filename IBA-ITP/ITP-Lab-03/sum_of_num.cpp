#include <iostream>

int main() 
{
    std::cout << "Enter Number: ";
    int n;
    std::cin >> n;
    int sum = 0;
    
    while (n != 0)
    {
        sum = sum + n;
        n = n - 1;
    }
    
    std::cout << "Sum of all numbers is " << sum;
}