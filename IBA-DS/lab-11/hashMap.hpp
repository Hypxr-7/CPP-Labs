#pragma once

#include <string>
#include <vector>
#include <list>
#include <algorithm>

class hashMap {
private:
    std::vector<std::list<std::string>> table;
    int size;
    int capacity;

    int hash(const std::string& key, int prevHash = 0, char newChar = '\0') const {
        if (prevHash == 0) {
            // Compute the hash value from scratch
            int hashValue = 0;
            for (char ch : key) {
                hashValue = (hashValue * 31 + ch) % capacity;
            }
            return hashValue;
        } else {
            // Compute the hash value incrementally
            return (prevHash * 31 + newChar) % capacity;
        }
    }

public:
    hashMap(int capacity) : capacity(capacity), size(0) {
        table.resize(capacity);
    }

    void put(const std::string& word) {
        int prevHash = 0;
        // Insert all prefixes of the word into the hash table
        for (size_t i = 1; i <= word.length(); ++i) {
            std::string prefix = word.substr(0, i);
            prevHash = hash(prefix, prevHash, prefix.back());
            int index = prevHash;
            // If the prefix is not already in the hash table, add it
            if (std::find(table[index].begin(), table[index].end(), prefix) == table[index].end())
                table[index].push_back(prefix);
        }
        // Insert the word with a marker into the hash table
        std::string wordWithMarker = word + '*'; // Marker indicates the end of the string
        prevHash = hash(wordWithMarker, prevHash, '*');
        int index = prevHash;
        // If the word with marker is not already in the hash table, add it
        if (std::find(table[index].begin(), table[index].end(), wordWithMarker) == table[index].end())
            table[index].push_back(wordWithMarker);
    }

    bool contains(const std::string& word) const {
        int index = hash(word);
        return std::find(table[index].begin(), table[index].end(), word) != table[index].end();
    }

    bool isWord(const std::string& word) const {
        std::string wordWithMarker = word + '*';
        return contains(wordWithMarker);
    }

    // Function to check if a prefix is in the hash table
    bool isPrefix(const std::string& prefix) const {
        return contains(prefix);
    }
};