/******************************************************************  
 * @file palindrome.cpp
 * @brief This program checks if a given DNA sequence is a Watson-Crick 
 *        complemented palindrome. A Watson-Crick complemented palindrome 
 *        is a sequence that reads the same forward and backward when 
 *        considering the complementary bases (A-T and C-G).
 * 
 * Usage:
 * 1. Compile the program using a C++ compiler.
 * 2. Run the executable.
 * 3. Enter the DNA sequence (e.g., ACGT) when prompted and press enter.
 * 4. Press the end of input key (CTRL+D on Unix or CTRL+Z on Windows).
 * 5. The program will output whether the sequence is a Watson-Crick 
 *    complemented palindrome.
 * 
 * Example:
 * Enter DNA sequence: 
 * ACGT
 * The given dna sequence is a Watson-Crick complemented palindrome
 ******************************************************************/


#include <iostream>
#include "deque.hpp"

bool isWatsonCrick(Deque<char>& dq);
char getComplement(char base);

int main() {
    std::cout << "Enter DNA sequence: \n";
    char ch;
    Deque<char> dq;
    while (std::cin >> ch)
        dq.push_back(ch);

    if (isWatsonCrick(dq))
        std::cout << "The given dna sequence is a Watson-Crick complemented palindrome\n";
    else
        std::cout << "The given dna sequence is not a Watson-Crick complemented palindrome\n";


    return 0;
}

bool isWatsonCrick(Deque<char> &dq) {
    while (!dq.empty() && dq.size() != 1)
        if (dq.pop_back() != getComplement(dq.pop_front()))
            return false;
    return true;
}

char getComplement(char base) {
    switch(base) {
        case 'A': return 'T';
        case 'T': return 'A';
        case 'C': return 'G';
        case 'G': return 'C';
        default: return '\0'; // Invalid base case
    }
}
