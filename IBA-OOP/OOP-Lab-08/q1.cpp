#include <iostream>
#include <ctime>

int main() {
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
        std::cout << []{return rand() % 100 + 1;}() << std::endl;
}
