/*
 * Removes the j > 0 in the inner loop by fixing the first element
 */

#include <cassert>
#include <iostream>
#include <vector>

template<typename T>
void insertionSort(std::vector<T>& arr);

void testInsertionSort();

int main() {
    testInsertionSort();

    return 0;
}


template<typename T>
void insertionSort(std::vector<T>& arr) {
    int n = arr.size();

    // put smallest element in position to serve as sentinel
    int exchanges = 0;
    for (int i = n - 1; i > 0; --i) {
        if (arr[i] < arr[i - 1]) {
            std::swap(arr[i], arr[i - 1]);
            ++exchanges;
        }
    }
    if (exchanges == 0) return;


    // insertion sort with half-exchanges
    for (int i = 2; i < n; ++i) {
        T v = arr[i];
        int j = i;
        while (v < arr[j-1]) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = v;
    }
}

void testInsertionSort() {
    // Test case 1: Empty array
    std::vector<int> arr1 = {};
    insertionSort(arr1);
    assert(arr1.empty());

    // Test case 2: Single element array
    std::vector<int> arr2 = {1};
    insertionSort(arr2);
    assert(arr2 == std::vector<int>({1}));

    // Test case 3: Already sorted array
    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    insertionSort(arr3);
    assert(arr3 == std::vector<int>({1, 2, 3, 4, 5}));

    // Test case 4: Reverse sorted array
    std::vector<int> arr4 = {5, 4, 3, 2, 1};
    insertionSort(arr4);
    assert(arr4 == std::vector<int>({1, 2, 3, 4, 5}));

    // Test case 5: Random order array
    std::vector<int> arr5 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    insertionSort(arr5);
    assert(arr5 == std::vector<int>({1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9}));

    // Test case 6: Array with duplicate elements
    std::vector<int> arr6 = {2, 3, 2, 3, 1, 1};
    insertionSort(arr6);
    assert(arr6 == std::vector<int>({1, 1, 2, 2, 3, 3}));

    std::cout << "All test cases passed!" << std::endl;
}