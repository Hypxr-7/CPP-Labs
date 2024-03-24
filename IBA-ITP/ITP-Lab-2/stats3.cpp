#include <iostream>
#include <cstdlib>
#include <cmath>

int main()
{
    srand(time(0));
    int num1 = rand();
    int num2 = rand();
    int num3 = rand();
    
    int max, min;

    max = fmax(num1, num2);
    max = fmax(max, num3);
    
    min = fmin(num1, num2);
    min = fmin(min, num3);

    double avg = (num1 + num2 + num3) / 3.0;

    std::cout << "Num 1: " << num1 << std::endl;
    std::cout << "Num 2: " << num2 << std::endl;
    std::cout << "Num 3: " << num3 << std::endl << std::endl;

    std::cout << "Max is " << max << std::endl;
    std::cout << "Min is " << min << std::endl;
    std::cout << "Avg is " << avg;
}