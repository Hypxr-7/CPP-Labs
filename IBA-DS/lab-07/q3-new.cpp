#include <iostream>
#include <vector>
#include <stdexcept>

class MinPriorityQueue {
private:
    std::vector<std::pair<int, std::pair<int, int>>> array; // (value, (array index, element index))

public:
    void insert(int value, int arrayIndex, int elementIndex) {
        array.push_back({value, {arrayIndex, elementIndex}});
    }

    std::pair<int, std::pair<int, int>> delMin() {
        if (array.empty()) {
            throw std::runtime_error("Array is empty");
        }

        // Find the minimum element
        int minIndex = 0;
        for (int i = 1; i < array.size(); ++i) {
            if (array[i].first < array[minIndex].first) {
                minIndex = i;
            }
        }

        std::pair<int, std::pair<int, int>> minElement = array[minIndex];
        array.erase(array.begin() + minIndex);
        return minElement;
    }

    bool isEmpty() {
        return array.empty();
    }
};

std::vector<int> mergeKSortedArrays(const std::vector<std::vector<int>>& arrays) {
    MinPriorityQueue pq;
    std::vector<int> mergedArray;

    // Insert the first element of each array into the priority queue
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            pq.insert(arrays[i][0], i, 0);
        }
    }

    // Merge arrays
    while (!pq.isEmpty()) {
        auto minElement = pq.delMin();
        int value = minElement.first;
        int arrayIndex = minElement.second.first;
        int elementIndex = minElement.second.second;

        mergedArray.push_back(value);

        // Insert the next element from the same array into the priority queue
        if (elementIndex + 1 < arrays[arrayIndex].size()) {
            pq.insert(arrays[arrayIndex][elementIndex + 1], arrayIndex, elementIndex + 1);
        }
    }

    return mergedArray;
}

int main() {
    std::vector<std::vector<int>> arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    std::vector<int> mergedArray = mergeKSortedArrays(arrays);

    for (int value : mergedArray) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
