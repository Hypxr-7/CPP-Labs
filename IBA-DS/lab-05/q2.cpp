#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>
#include "stopwatch.hpp"

/*************************************************************
 * Dual Pivot Quicksort
**************************************************************/
template<typename T>
void quicksortDP(std::vector<T>& arr, int low, int high);
template<typename T>
void quicksortDP(std::vector<T>& arr);

void testQuicksortDP();

/*************************************************************
 * Default Quicksort
**************************************************************/
template<typename T>
int partition(std::vector<T>& arr, int low, int high);
template<typename T>
void quicksort(std::vector<T>& arr, int low, int high);
template<typename T>
void quicksort(std::vector<T>& arr);

/*************************************************************
 * Main for testing
**************************************************************/

int main() {
    std::vector<int> arr1(1'000'000);
    std::generate(arr1.begin(), arr1.end(), std::mt19937(std::random_device{}()));
    auto arr2 = arr1;

    Stopwatch sw;

    sw.reset();
    quicksort(arr1);
    std::cout << "Default: " << sw.elapsedTime() << " seconds\n";

    sw.reset();
    quicksortDP(arr2);
    std::cout << "Dual Pivot: " << sw.elapsedTime() << " seconds\n";

    // testQuicksortDP(); // for testing dual pivot quicksort

    return 0;
}

/*************************************************************
 * Function Definitions
**************************************************************/

template<typename T>
void quicksortDP(std::vector<T>& arr, int low, int high) {
    if (high <= low) return;

    // make sure arr[low] <= arr[high]
    if (arr[high] < arr[low]) std::swap(arr[high], arr[low]);

    int lt = low + 1, gt = high - 1;
    int i = low + 1;
    while (i <= gt) {
        if (arr[i] < arr[low]) std::swap(arr[lt++], arr[i++]);
        else if (arr[high] < arr[i]) std::swap(arr[i], arr[gt--]);
        else ++i;
    }
    std::swap(arr[low], arr[--lt]);
    std::swap(arr[high], arr[++gt]);

    // recursively sort three sub-arrays
    quicksort(arr, low, lt - 1);
    if (arr[lt] < arr[gt]) quicksort(arr, lt + 1, gt - 1);
    quicksort(arr, gt + 1, high);
}


template<typename T>
void quicksortDP(std::vector<T>& arr) {
    std::shuffle(arr.begin(), arr.end(), std::mt19937(std::random_device{}()));
    quicksortDP(arr, 0, arr.size() - 1);
}

void testQuicksortDP() {
    // Test case 1: Empty array
    std::vector<int> arr1 = {};
    quicksortDP(arr1);
    assert((arr1 == std::vector<int>{}));

    // Test case 2: Single element array
    std::vector<int> arr2 = {1};
    quicksortDP(arr2);
    assert((arr2 == std::vector<int>{1}));

    // Test case 3: Already sorted array
    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    quicksortDP(arr3);
    assert((arr3 == std::vector<int>{1, 2, 3, 4, 5}));

    // Test case 4: Reverse sorted array
    std::vector<int> arr4 = {5, 4, 3, 2, 1};
    quicksortDP(arr4);
    assert((arr4 == std::vector<int>{1, 2, 3, 4, 5}));

    // Test case 5: Random unsorted array
    std::vector<int> arr5 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    quicksortDP(arr5);
    assert((arr5 == std::vector<int>{1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9}));

    // Test case 6: Array with duplicate elements
    std::vector<int> arr6 = {4, 2, 4, 2, 4, 2};
    quicksortDP(arr6);
    assert((arr6 == std::vector<int>{2, 2, 2, 4, 4, 4}));

    // Test case 7: Large array
    std::vector<int> arr7(10000);
    std::iota(arr7.begin(), arr7.end(), 0);
    std::shuffle(arr7.begin(), arr7.end(), std::mt19937{std::random_device{}()});
    quicksortDP(arr7);
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
