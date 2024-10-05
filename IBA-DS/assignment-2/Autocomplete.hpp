#pragma once 

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cassert>
#include <fstream>
#include "Term.hpp"  // Assumes Term class is implemented in Term.hpp
#include "BinarySearchDeluxe.hpp"  // Assumes BinarySearchDeluxe is implemented

class Autocomplete {
private:
    std::vector<Term> terms;

    template <typename T, typename Comparator>
    static int partition(std::vector<T>& arr, int low, int high, Comparator comp) {
        int i = low, j = high + 1;
        T v = arr[low];
        while (true) {

            // find item on low to swap
            while (comp(arr[++i], v))
                if (i == high) break;

            // find item on high to swap
            while (comp(v, arr[--j]))
                if (j == low) break;

            // check if pointers cross
            if (i >= j) break;

            std::swap(arr[i], arr[j]);
        }

        // put partitioning item v at arr[j]
        std::swap(arr[low], arr[j]);

        // now, arr[low .. j-1] <= arr[j] <= arr[j+1 .. high]
        return j; 
    }

    template <typename T, typename Comparator>
    static void quicksort(std::vector<T>& arr, int low, int high, Comparator comp) {
        if (high <= low) return;
        int j = partition(arr, low, high, comp);
        quicksort(arr, low, j - 1, comp);
        quicksort(arr, j + 1, high, comp);
    }

    template <typename T, typename Comparator = std::less<T>>
    static void quicksort(std::vector<T>& arr, Comparator comp = std::less<T>()) {
        std::shuffle(arr.begin(), arr.end(), std::mt19937{std::random_device{}()});
        quicksort(arr, 0, arr.size() - 1, comp);
    }

public:
    // Initializes the data structure from the given array of terms.
    Autocomplete(const std::vector<Term>& terms) {
        if (terms.empty()) throw std::invalid_argument("Empty array");

        // time complexity O(n)
        for (const auto& term : terms) {
            if (term.query.empty()) throw std::invalid_argument("Empty entry in array");
            this->terms.push_back(term);
        }

        // time complexity O(n.log n)
        quicksort(this->terms);

        // final time complexity O(n.log n)
    }

    // Returns all terms that start with the given prefix, in descending order of weight.
    std::vector<Term> allMatches(const std::string& prefix) {
        int r = prefix.length();
        auto comparator = Term::byPrefixOrder(prefix.length());

        // time complexity O(log n)
        int firstIndex = BinarySearchDeluxe::firstIndexOf<Term>(terms, Term{prefix, 0}, comparator);
        int lastIndex = BinarySearchDeluxe::lastIndexOf<Term>(terms, Term{prefix, 0}, comparator);

        if (firstIndex == -1) return std::vector<Term>(); // no match was found

        // time complexity O(m)
        std::vector<Term> matches;
        for (int i = firstIndex, j = 0; i <= lastIndex; ++i, ++j)
            matches.push_back(terms[i]);

        // time complexity O(m.log m)
        quicksort(matches, Term::byReverseWeightOrder());

        // final time complexity O(m.log m + log n)
        return std::move(matches);
    }

    // Returns the number of terms that start with the given prefix.
    int numberOfMatches(const std::string& prefix) {
        int countMatches = 0;
        auto comparator = Term::byPrefixOrder(prefix.length());

        // time complexity O(log n)
        int firstIndex = BinarySearchDeluxe::firstIndexOf<Term>(terms, Term{prefix, 0}, comparator);
        int lastIndex = BinarySearchDeluxe::lastIndexOf<Term>(terms, Term{prefix, 0}, comparator);
        
        if (lastIndex == -1) return 0;
        
        // final time complexity O(log n)
        return lastIndex - firstIndex + 1;
    }

    // Unit testing (required)
    static void test() {
        std::vector<Term> terms = {Term("apple", 500),
                               Term("app", 700),
                               Term("application", 300),
                               Term("ape", 200),
                               Term("apex", 100)};

        Autocomplete autocomplete(terms);

        // Test 1: All terms that start with "app"
        std::vector<Term> results = autocomplete.allMatches("app");
        assert(results.size() == 3);
        assert(results[0].toString() == "       700\tapp");
        assert(results[1].toString() == "       500\tapple");
        assert(results[2].toString() == "       300\tapplication");

        // Test 2: Number of terms that start with "ap"
        int numMatches = autocomplete.numberOfMatches("ap");
        assert(numMatches == 5);

        // Test 3: All terms that start with "a"
        results = autocomplete.allMatches("a");
        assert(results.size() == 5);
        assert(results[0].toString() == "       700\tapp");
        assert(results[1].toString() == "       500\tapple");
        assert(results[2].toString() == "       300\tapplication");
        assert(results[3].toString() == "       200\tape");
        assert(results[4].toString() == "       100\tapex");

        // Test 4: Number of terms that start with "app"
        numMatches = autocomplete.numberOfMatches("app");
        assert(numMatches == 3);

        // Test 5: All terms that start with "appl"
        results = autocomplete.allMatches("appl");
        assert(results.size() == 2);
        assert(results[0].toString() == "       500\tapple");
        assert(results[1].toString() == "       300\tapplication");

        // Test 6: Number of terms that start with "appl"
        numMatches = autocomplete.numberOfMatches("appl");
        assert(numMatches == 2);

        // Test 7: All terms that start with "z" (no matches)
        results = autocomplete.allMatches("z");
        assert(results.size() == 0);

        // Test 8: Number of terms that start with "z" (no matches)
        numMatches = autocomplete.numberOfMatches("z");
        assert(numMatches == 0);

        std::cout << "Autocomplete: All tests passed!" << std::endl;
    }
};
