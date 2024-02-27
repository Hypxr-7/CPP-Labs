#include <iostream>
#include <cmath>

int main() 
{
    std::cout << "For ax²+bx+c," << std::endl;
    int a, b, c;
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >>c;
    
    int disc = b*b - 4*a*c;
    if (disc > 0)
    {
        double r1 = ((-b + sqrt(disc))) / (2*a);
        double r2 = ((-b - sqrt(disc))) / (2*a);
        std::cout << "Root 1: " << r1 << std::endl;
        std::cout << "Root 2: " << r2 << std::endl;
    }
    if (disc == 0)
    {
        double r = ((-b) / (2*a));
        std::cout << "The Single Root is " << r;
    }
    if (disc < 0)
    {
        std::cout << "No Real Roots";
    }
}