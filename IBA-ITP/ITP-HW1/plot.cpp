#include<iostream>
#include<iomanip>

int main() {
    std::cout << std::fixed << std::setprecision(3);

    double price;
    while(std::cin >> price) {
        for (int i = 0 ; i < int(price); i++){
            std::cout << "*" ;
        }
        std::cout << std::endl;
    }
    return 0;
}