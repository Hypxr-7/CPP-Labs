#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include "RightLeaningRedBlackBST.hpp"

// Make sure to uncomment the assert(check()) in RightLeaningRedBlackBST.hpp at line 142 and line 177 when running tests
// Comment it again for general use to prevent slow execution

std::pair<std::string, std::string> parseLine(const std::string& line);

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <DictionaryFile>\n";
        return 1;
    }

    std::ifstream fileHandle(argv[1]);
    std::string line;
    RightLeaningRedBlackBST<std::string, std::string> dict;

    if (!fileHandle.is_open()) {
        std::cerr << "File not found\n";
        return 1;
    }

    while (std::getline(fileHandle, line)) {
        auto [word, meaning] = parseLine(line);
        dict.put(std::move(word), std::move(meaning));
    }
    fileHandle.close();

    std::cout << '\n'
              << "Enter * to exit\n";

    while (true) {
        std::cout << "Enter Word: ";
        std::string word;
        std::getline(std::cin >> std::ws, word);

        if (word == "*") break;

        try {
            std::cout << "Meaning: " << dict.get(word) << "\n\n";
        } catch (const std::out_of_range& e) {
            std::cout << "Word not found\n\n";
        }
    }

    return 0;
}

std::pair<std::string, std::string> parseLine(const std::string& line) {
    size_t delimiterPos = line.find(',');
    std::string word = line.substr(0, delimiterPos);
    std::string meaning = line.substr(delimiterPos + 1);
    return {std::move(word), std::move(meaning)};
}
