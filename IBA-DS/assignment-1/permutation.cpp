/***************************************************************************************************
 * @file permutation.cpp
 * @brief This program reads words from standard input, stores them in a randomized queue, 
 *        and prints a specified number of randomly dequeued words.
 *
 * Usage:
 * 1. Compile the program:
 *    g++ -o permutation permutation.cpp
 *
 * 2. Run the program with a single command line argument specifying the number of words to dequeue:
 *    ./permutation number_of_words < text_file_to_read_from
 *
 * Example:
 *    ./permutation 3 < distinct.txt
 ***************************************************************************************************/


#include <iostream>
#include <sstream>
#include <string>
#include "randomizedQueue.hpp"

int main(int argc, char** argv) {
    srand(time(nullptr));

    if (argc != 2) {
        std::cerr << "Invalid number of command line arguments\n";
        return 1;
    }
    
    int k = std::stoi(argv[1]);

    RandomizedQueue<std::string> rq;
    std::string text;

    while(std::getline(std::cin, text)) {
        std::stringstream ss(text); 
        std::string word;
        while(ss >> word)
            rq.enqueue(word);
    }


    if ( k < 0 || k > rq.size()) {
        std::cerr << "Command line argument out of range\n";
        return 1;
    }

    for (int i = 0; i < k; ++i) 
        std::cout << rq.dequeue() << '\n';

    return 0;
}