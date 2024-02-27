#include <iostream>
#include <cstdlib>

int main() 
{
    srand(time(0));
    int num = rand() % 6 + 1;
    std::cout << "Dice is " << num;
}