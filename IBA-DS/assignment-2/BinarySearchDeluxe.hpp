#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <cassert>

class BinarySearchDeluxe {
public:
    // Returns the index of the first key in the sorted array that is equal to the search key.
    template <typename Key>
    static int firstIndexOf(const std::vector<Key>& a, const Key& key, std::function<bool(const Key&, const Key&)> comparator) {
        int low = 0;
        int high = a.size() - 1;
        int result = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (comparator(a[mid], key)) { // key in upper half
                low = mid + 1;
            } else if (comparator(key, a[mid])) { // key in lower half
                high = mid - 1;
            } else {
                result = mid;
                high = mid - 1; // Continue searching in the left half
            }
        }

    // time complexity O(log n)
    return result;
}

    // Returns the index of the last key in the sorted array that is equal to the search key.
    template <typename Key>
    static int lastIndexOf(const std::vector<Key>& a, const Key& key, std::function<bool(const Key&, const Key&)> comparator) {
        int low = 0;
        int high = a.size() - 1;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (comparator(a[mid], key)) { // key in upper half
                low = mid + 1;
            } else if (comparator(key, a[mid])) { // key in lower half
                high = mid - 1;
            } else {
                result = mid;
                low = mid + 1; // Continue searching in the right half
            }
        }

        // time complexity O(log n)
        return result;
    }

    // Unit testing (required)
    static void test() {
        std::vector<int> sortedArray = {1, 2, 2, 2, 3, 4, 5};
        int key = 2;

        auto comparator = [](const int& a, const int& b) -> bool {
            return a < b;
        };

        int firstIndex = firstIndexOf<int>(sortedArray, key, comparator);
        int lastIndex = lastIndexOf<int>(sortedArray, key, comparator);

        assert(firstIndex == 1);
        assert(lastIndex == 3);

        std::cout << "BinarySearchDeluxe: All tests passed!" << std::endl;
    }
};
