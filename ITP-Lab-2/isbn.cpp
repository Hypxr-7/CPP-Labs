#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Enter the 9-digit ISBN Number: ";
    int isbn;
    std::cin >> isbn;

    int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10;
    d2 = isbn % 10;
    d3 = (isbn % 100) / 10;
    d4 = (isbn % 1000) / 100;
    d5 = (isbn % 10000) / 1000;
    d6 = (isbn % 100000) / 10000;
    d7 = (isbn % 1000000) / 100000;
    d8 = (isbn % 10000000) / 1000000;
    d9 = (isbn % 100000000) / 10000000;
    d10 = (isbn % 1000000000) / 100000000;

    int sum;
    sum = (d2*2 + d3*3 + d4*4 + d5*5 + d6*6 + d7*7 + d8*8 + d9*9 + d10*10);
    d1 = 11 - (sum % 11);


    std::cout << "The first digit is " << d1;
}