#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>
#include "stopwatch.hpp"

/******************************************************************************
 *  Hoare's Original Quicksort
 ******************************************************************************/
// partitionH the sub-array arr[low..high] so that arr[low..j-1] <= arr[j] <= arr[j+1..high]
// and return the index j.
template<typename T>
int partitionH(std::vector<T>& arr, int low, int high);
template<typename T>
void quicksortH(std::vector<T>& arr, int low, int high);
template<typename T>
void quicksortH(std::vector<T>& arr);

void testQuicksortH();

/******************************************************************************
 *  Default Quicksort
 ******************************************************************************/
template<typename T>
int partition(std::vector<T>& arr, int low, int high);
template<typename T>
void quicksort(std::vector<T>& arr, int low, int high);
template<typename T>
void quicksort(std::vector<T>& arr);

/******************************************************************************
 *  Main Function
 ******************************************************************************/

int main() {
    std::vector<int> arr1(1'000'000);
    std::generate(arr1.begin(), arr1.end(), std::mt19937(std::random_device{}()));
    auto arr2 = arr1;

    Stopwatch sw;

    sw.reset();
    quicksort(arr1);
    std::cout << "Default: " << sw.elapsedTime() << " seconds\n";

    sw.reset();
    quicksortH(arr2);
    std::cout << "Hoare's: " << sw.elapsedTime() << " seconds\n";

    // testQuicksortH(); // for testing Hoare's quicksort

    return 0;
}

/******************************************************************************
 *  Function Declarations
 ******************************************************************************/

template <typename T>
int partitionH(std::vector<T>& arr, int low, int high) {
    int i = low - 1;
    int j = high + 1;
    T pivot = arr[low];

    while (true) {
        do {
            // Move i to the right, finding elements that should be on the right side
            ++i;
        } while(arr[i] < pivot);

        do {
            // Move j to the left, finding elements that should be on the left side
            --j;
        } while(pivot < arr[j]);

        // If pointers have crossed, return j as the partition index
        if (i >= j) return j;

        std::swap(arr[i], arr[j]);
        // the pivot doesn't end up at a[j], but it does still partitionH
        // the array into keys <= pivot and keys >= pivot
    }
}

template <typename T>
void quicksortH(std::vector<T>& arr, int low, int high) {
    if (high <= low) return;
    int j = partitionH(arr, low, high);
    quicksortH(arr, low, j);
    quicksortH(arr, j + 1, high);
}

template <typename T>
void quicksortH(std::vector<T>& arr) {
    std::shuffle(arr.begin(), arr.end(), std::default_random_engine(std::random_device{}()));
    quicksortH(arr, 0, arr.size() - 1);
}

void testQuicksortH() {
    // Test case 1: Empty array
    std::vector<int> arr1 = {};
    quicksortH(arr1);
    assert((arr1 == std::vector<int>{}));

    // Test case 2: Single element array
    std::vector<int> arr2 = {1};
    quicksortH(arr2);
    assert((arr2 == std::vector<int>{1}));

    // Test case 3: Already sorted array
    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    quicksortH(arr3);
    assert((arr3 == std::vector<int>{1, 2, 3, 4, 5}));

    // Test case 4: Reverse sorted array
    std::vector<int> arr4 = {5, 4, 3, 2, 1};
    quicksortH(arr4);
    assert((arr4 == std::vector<int>{1, 2, 3, 4, 5}));

    // Test case 5: Random unsorted array
    std::vector<int> arr5 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    quicksortH(arr5);
    assert((arr5 == std::vector<int>{1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9}));

    // Test case 6: Array with duplicate elements
    std::vector<int> arr6 = {4, 2, 4, 2, 4, 2};
    quicksortH(arr6);
    assert((arr6 == std::vector<int>{2, 2, 2, 4, 4, 4}));

    // Test case 7: Large array
    std::vector<int> arr7(10000);
    std::iota(arr7.begin(), arr7.end(), 0);
    std::shuffle(arr7.begin(), arr7.end(), std::mt19937{std::random_device{}()});
    quicksortH(arr7);
    assert(std::is_sorted(arr7.begin(), arr7.end()));

    std::cout << "All test cases passed!" << std::endl;
}


template<typename T>
int partition(std::vector<T>& arr, int low, int high) {
    int i = low, j = high+1;
    while (true) {

        while (arr[++i] < arr[low])
            if (i == high) break;

        while (arr[low] < arr[--j])
            if (j == low) break;
       
        if (i >= j) break;
        std::swap(arr[i], arr[j]);
   }

   std::swap(arr[low], arr[j]);
   return j;
} 

template<typename T>
void quicksort(std::vector<T>& arr, int low, int high) {
      if (high <= low) return;
      int j = partition(arr, low, high);
      quicksort(arr, low, j-1);
      quicksort(arr, j+1, high);
}

template<typename T>
void quicksort(std::vector<T>& arr) {
      std::shuffle(arr.begin(), arr.end(), std::default_random_engine(std::random_device{}()));
      quicksort(arr, 0, arr.size() - 1);
}
