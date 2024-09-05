#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <vector>

constexpr int N = 100; // number of words
constexpr int L = 5; // number of letters per word

std::string random_word(int L) {
    std::string s;
    for (int i = 0; i < L; ++i) {
        s.push_back('a' + std::random_device()() % 26);
    }
    return s;
}

std::pair<int, int> findAnagram(std::vector<std::string> list, int& begin);
bool isAnagram(std::string w1, std::string w2);

int main() {
    std::vector<std::string> wordList;
    for (int i = 0; i < N / 2; ++i) {
        std::string word = random_word(L);
        wordList.push_back(word);
        std::shuffle(word.begin(), word.end(), std::mt19937(std::random_device{}()));
        wordList.push_back(word);
    }

    std::shuffle(wordList.begin(), wordList.end(), std::mt19937(std::random_device{}()));
    
    std::pair<int, int> indices;
    int i = 0;
    while (indices.first != -1 && indices.second != -1) {
        indices = findAnagram(wordList, i);
        if (indices.first != -1) {
            std::cout << wordList[indices.first] << ' ' << wordList[indices.second] << '\n';
            ++i;
        }
    }

    return 0;
}

std::pair<int, int> findAnagram(std::vector<std::string> list, int& begin) {
    for (int i = begin; i < N; ++i)
        for (int j = i + 1; j < N; ++j) 
            if (isAnagram(list[i], list[j])) return std::pair<int, int>(i, j);
    return std::pair<int, int>(-1, -1);
}

// ! as required in part (b)
// bool isAnagram(std::string w1, std::string w2) {
//     return std::all_of(w1.begin(), w1.end(), [w2](auto c){ 
//         return w2.find(c) != std::string::npos;
//         });
// }

// ! as required in part (c)
bool isAnagram(std::string w1, std::string w2) {
    std::sort(w1.begin(), w1.end());
    std::sort(w2.begin(), w2.end());
    return w1 == w2;
}
