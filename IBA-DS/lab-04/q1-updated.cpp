#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>
#include "stopwatch.hpp"

/********************************************************************************** 
 * Improved Merge Sort
***********************************************************************************/

constexpr int CUTOFF = 10;

template<typename T>
void mergeX(std::vector<T>& src, std::vector<T>& dst, int low, int mid, int high);
template<typename T>
void mergesortX(std::vector<T>& src, std::vector<T>& dst, int low, int high);
template<typename T>
void mergesortXWrapper(std::vector<T>& arr);

template<typename T>
void insertionSort(std::vector<T>& arr, int low, int high);

void testMergesortWrapper();

/********************************************************************************** 
 * Old Merge Sort
***********************************************************************************/

template<typename T>
void merge(std::vector<T>& arr, std::vector<T>& aux, int low, int mid, int high);
template<typename T>
void mergesort(std::vector<T>& arr, std::vector<T>& aux, int low, int high);
template<typename T>
void mergesortWrapper(std::vector<T>& arr);

/********************************************************************************** 
 * Main 
***********************************************************************************/

int main() {
    std::vector<int> arr1(1'000'000);
    std::generate(arr1.begin(), arr1.end(), std::rand);
    std::vector<int> arr2 = arr1; // Copy for the second sort

    Stopwatch sw;

    // Test old mergesort
    sw.reset();
    mergesortWrapper(arr1);
    std::cout << "Old mergesort time: " << sw.elapsedTime() << " seconds" << std::endl;

    // Test improved mergesort
    sw.reset();
    mergesortXWrapper(arr2);
    std::cout << "Improved mergesort time: " << sw.elapsedTime() << " seconds" << std::endl;

    return 0;

}

/********************************************************************************** 
 * Function Declarations
***********************************************************************************/

template<typename T>
void mergeX(std::vector<T>& src, std::vector<T>& dst, int low, int mid, int high) {

    // improvement 3: removed the need to copy the array 

    int i = low, j = mid + 1;
    for (int k = low; k <= high; ++k) {
        if      (i > mid)          dst[k] = src[j++];
        else if (j > high)         dst[k] = src[i++];
        else if (src[j] < src[i])  dst[k] = src[j++];   
        else                       dst[k] = src[i++];
    }
}

template<typename T>
void mergesortX(std::vector<T>& src, std::vector<T>& dst, int low, int high) {
    // improvement 1: adds cutoff and uses insertion sort for smaller sub-arrays
    if (high <= low + CUTOFF) {
        insertionSort(dst, low, high);
        return;
    }

    int mid = low + (high - low) / 2;
    mergesortX(dst, src, low, mid);
    mergesortX(dst, src, mid + 1, high);

    // improvement 2: skips recursive call if already sorted
    if (src[mid + 1] >= src[mid]) {
        std::copy(src.begin() + low, src.begin() + high + 1, dst.begin() + low);
        return;
    }

    mergeX(src, dst, low, mid, high);
}

template<typename T>
void mergesortXWrapper(std::vector<T>& arr) {
    std::vector<T> aux(arr);
    mergesortX(aux, arr, 0, arr.size() - 1);
}

template<typename T>
void insertionSort(std::vector<T>& arr, int low, int high) {
    for (int i = low; i <= high; ++i) {
        for (int j = i; j > low && arr[j] < arr[j - 1]; --j) {
            std::swap(arr[j], arr[j - 1]);
        }
    }
}

template<typename T>
void merge(std::vector<T>& arr, std::vector<T>& aux, int low, int mid, int high) {
    // copy to aux
    for (int k = low; k <= high; ++k)
        aux[k] = arr[k];

    // merge int arr
    int i = low, j = mid + 1;
    for (int k = low; k <= high; ++k) {
        if      (i > mid)         arr[k] = aux[j++];
        else if (j > high)        arr[k] = aux[i++];
        else if (aux[j] < aux[i]) arr[k] = aux[j++];
        else                      arr[k] = aux[i++];
    }
}

template<typename T>
void mergesort(std::vector<T>& arr, std::vector<T>& aux, int low, int high) {
    if (high <= low) return;

    int mid = low + (high - low) / 2;
    mergesort(arr, aux, low, mid);
    mergesort(arr, aux, mid + 1, high);
    merge(arr, aux, low, mid, high);
}

template<typename T>
void mergesortWrapper(std::vector<T>& arr) {
    std::vector<T> aux(arr.size());
    mergesort(arr, aux, 0, arr.size() - 1);
}