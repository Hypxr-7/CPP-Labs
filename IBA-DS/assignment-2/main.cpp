#include <fstream>
#include <iostream>
#include <vector>
#include "Autocomplete.hpp"
#include "BinarySearchDeluxe.hpp"
#include "Term.hpp"

// #define TESTING_ACTIVE   // uncomment this line to run tests

// compile with g++ -o autocomplete main.cpp
// make sure all the header files and text files are in the same directory
// run with ./autocomplete file.txt n
// file.txt is the name of the file
// n is the max suggestions to display
// then type the starting letters of the word in the terminal anf press enter
// the words will be displayed in descending order of rank
// repeat for any word
// press CTRL+C to exit

int main(int argc, char* argv[]) {
#ifdef TESTING_ACTIVE
    
    BinarySearchDeluxe::test();
    Term::test();
    Autocomplete::test();

#endif
#ifndef TESTING_ACTIVE

    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <FileName> <MaxSuggestions>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream infile(filename);

    int n;
    infile >> n; // number of items in the text file

    std::vector<Term> terms;
    for (int i = 0; i < n; i++) {
        long weight;
        std::string query;
        infile >> weight >> std::ws;
        std::getline(infile, query);
        terms.emplace_back(query, weight);
    }

    Autocomplete autocomplete(terms);

    std::string prefix;
    while (std::getline(std::cin, prefix)) {
        std::vector<Term> results = autocomplete.allMatches(prefix);
        std::cout << results.size() << " matches\n";
        for (size_t i = 0; i < std::min(results.size(), static_cast<size_t>(std::stoi(argv[2]))); i++) {
            std::cout << results[i].toString() << "\n";
        }
        std::cout << '\n';
    }

#endif

    return 0;
}