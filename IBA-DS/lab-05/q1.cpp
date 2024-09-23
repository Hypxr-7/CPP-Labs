#include <cassert>
#include <iostream>
#include <vector>

void stablePartition(std::vector<int>& arr, const int pivot);
void testStablePartition();

int main() {
    testStablePartition();

    return 0;
}

void stablePartition(std::vector<int> &arr, const int pivot) {
    std::vector<int> lesser;
    std::vector<int> greater;
    std::vector<int> equal;

    for (const auto& i : arr) {
        if (i < pivot) lesser.push_back(i);
        else if (i > pivot) greater.push_back(i);
        else equal.push_back(i);
    }

    arr.clear();
    arr.insert(arr.end(), lesser.begin(), lesser.end());
    arr.insert(arr.end(), equal.begin(), equal.end());
    arr.insert(arr.end(), greater.begin(), greater.end());
}

void testStablePartition() {
    {
        std::vector<int> arr = {1, 4, 3, 2, 5};
        stablePartition(arr, 3);
        std::vector<int> expected = {1, 2, 3, 4, 5};
        assert(arr == expected);
    }

    {
        std::vector<int> arr = {10, 20, 30, 40, 50};
        stablePartition(arr, 30);
        std::vector<int> expected = {10, 20, 30, 40, 50};
        assert(arr == expected);
    }

    {
        std::vector<int> arr = {5, 1, 4, 2, 3};
        stablePartition(arr, 3);
        std::vector<int> expected = {1, 2, 3, 5, 4};
        assert(arr == expected);
    }

    {
        std::vector<int> arr = {3, 3, 3, 3, 3};
        stablePartition(arr, 3);
        std::vector<int> expected = {3, 3, 3, 3, 3};
        assert(arr == expected);
    }

    {
        std::vector<int> arr = {7, 8, 9, 1, 2, 3};
        stablePartition(arr, 5);
        std::vector<int> expected = {1, 2, 3, 7, 8, 9};
        assert(arr == expected);
    }

    std::cout << "All tests passed!" << std::endl;
}
