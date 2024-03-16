#include <iostream>
#include <stdexcept>
#include <ctime>

class CurveBall : public std::exception {};

void process(){
    int num = std::rand() % 100;
    if (num < 25)
        throw CurveBall();
    // if (std::rand() % 4 == 0)
    //     throw CurveBall();
}

int main(){
    std::srand(std::time(0));
    int count = 0;
    for (int i = 0; i < 1000; i++){
        try {
            process();
        }
        catch (CurveBall &e){
            count++;
            // std::cout << "CurveBall exception" << std::endl;
        }
    }
    std::cout << "CurveBall exceptions: " << count << std::endl;
}