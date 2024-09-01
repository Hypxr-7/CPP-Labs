#include <iostream>

constexpr int MAX_SIZE = 5000;
constexpr int ITERATIONS = 1'000;

int calculateLinearSearchComparisons(int* arr, int value);
int calculateBinarySearchComparisons(int* arr, int value);

int main() {
    srand(time(nullptr));

    int lsCmpMax = 0;
    int bsCmpMax = 0;

    int arr[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; ++i)
        arr[i] = i;

    for (int i = 0; i < ITERATIONS; ++i) {
        int value = rand() & MAX_SIZE;

        lsCmpMax = std::max(lsCmpMax, calculateLinearSearchComparisons(arr, value));
        bsCmpMax = std::max(bsCmpMax, calculateBinarySearchComparisons(arr, value));
    }

    std::cout << "Linear Search Comparisons: " << lsCmpMax << '\n';
    std::cout << "Binary Search Comparisons: " << bsCmpMax << '\n';

    return 0;
}

int calculateLinearSearchComparisons(int* arr, int value) {
    int count = 0;

    for (int i = 0; i < MAX_SIZE; ++i){
        if (arr[i] == value)
            break;
        ++count;
    }

    return count;
}

int calculateBinarySearchComparisons(int* arr, int value) {
    int count = 0;
    int start = 0;
    int end = MAX_SIZE - 1;
    int mid = start + (end - start) / 2;

    while(start < end) {
        ++count;
        if (arr[mid] == value)
            break;
        else if (arr[mid] > value)
            end = mid - 1;
        else
            start = mid + 1;
        
        mid = start + (end - start) / 2;
    }

    return count;
}