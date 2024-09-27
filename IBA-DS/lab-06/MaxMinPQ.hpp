#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <algorithm>

template <typename Item>
class MaxMinPQ {
private:
    std::vector<Item> pqMin;  // Min-heap
    std::vector<Item> pqMax;  // Max-heap
    std::unordered_map<Item, int> minIndexMap;  // Map to store indices in min-heap
    std::unordered_map<Item, int> maxIndexMap;  // Map to store indices in max-heap
    int n;  // Number of items in the priority queue
    int cap;  // Capacity of the priority queue

    void resize(int capacity) {
        pqMin.resize(capacity + 1);
        pqMax.resize(capacity + 1);
        cap = capacity;
    }

    void swimMin(int k) {
        while (k > 1 && pqMin[k] < pqMin[k / 2]) {
            std::swap(pqMin[k], pqMin[k / 2]);
            minIndexMap[pqMin[k]] = k;
            minIndexMap[pqMin[k / 2]] = k / 2;
            k = k / 2;
        }
    }

    void sinkMin(int k) {
        while (2 * k <= n) {
            int j = 2 * k;
            if (j < n && pqMin[j] > pqMin[j + 1]) j++;
            if (pqMin[k] <= pqMin[j]) break;
            std::swap(pqMin[k], pqMin[j]);
            minIndexMap[pqMin[k]] = k;
            minIndexMap[pqMin[j]] = j;
            k = j;
        }
    }

    void swimMax(int k) {
        while (k > 1 && pqMax[k] > pqMax[k / 2]) {
            std::swap(pqMax[k], pqMax[k / 2]);
            maxIndexMap[pqMax[k]] = k;
            maxIndexMap[pqMax[k / 2]] = k / 2;
            k = k / 2;
        }
    }

    void sinkMax(int k) {
        while (2 * k <= n) {
            int j = 2 * k;
            if (j < n && pqMax[j] < pqMax[j + 1]) j++;
            if (pqMax[k] >= pqMax[j]) break;
            std::swap(pqMax[k], pqMax[j]);
            maxIndexMap[pqMax[k]] = k;
            maxIndexMap[pqMax[j]] = j;
            k = j;
        }
    }

public:
    MaxMinPQ(int capacity = 8) : pqMin(capacity + 1), pqMax(capacity + 1), n(0), cap(capacity) {}

    bool isEmpty() const {
        return n == 0;
    }

    int size() const {
        return n;
    }

    Item min() const {
        if (isEmpty()) throw std::runtime_error("Priority queue underflow");
        return pqMin[1];
    }

    Item max() const {
        if (isEmpty()) throw std::runtime_error("Priority queue underflow");
        return pqMax[1];
    }

    void insert(const Item& x) {
        if (n == cap) resize(2 * cap);
        pqMin[++n] = x;
        pqMax[n] = x;
        minIndexMap[x] = n;
        maxIndexMap[x] = n;
        swimMin(n);
        swimMax(n);
    }

    Item delMin() {
        if (isEmpty()) throw std::runtime_error("Priority queue underflow");
        Item minItem = pqMin[1];
        std::swap(pqMin[1], pqMin[n]);
        minIndexMap[pqMin[1]] = 1; // update index
        minIndexMap.erase(minItem);
        n--;
        sinkMin(1);

        int maxIndex = maxIndexMap[minItem]; // find index of max item
        std::swap(pqMax[maxIndex], pqMax[n + 1]); // swap to end
        maxIndexMap[pqMax[maxIndex]] = maxIndex; // update index
        maxIndexMap.erase(minItem); //remove item
        sinkMax(maxIndex);

        if (n > 0 && n == (cap - 1) / 4) resize(cap / 2);
        return minItem;
    }

    Item delMax() {
        if (isEmpty()) throw std::runtime_error("Priority queue underflow");
        Item maxItem = pqMax[1];
        std::swap(pqMax[1], pqMax[n]);
        maxIndexMap[pqMax[1]] = 1;
        maxIndexMap.erase(maxItem);
        n--;
        sinkMax(1);

        int minIndex = minIndexMap[maxItem]; 
        std::swap(pqMin[minIndex], pqMin[n + 1]); 
        minIndexMap[pqMin[minIndex]] = minIndex;
        minIndexMap.erase(maxItem);
        sinkMin(minIndex);

        if (n > 0 && n == (cap - 1) / 4) resize(cap / 2);
        return maxItem;
    }
};