#include <iostream>
#include "PercolationsStats.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <grid size> <trials>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]);
    int trials = std::stoi(argv[2]);

    PercolationStats::test(n, trials);

    return 0;
}