#include <algorithm>
#include <stdexcept>

template <typename Item>
class MaxMinPQ {
private:
    Item* pqMax;
    Item* pqMin;
    int n;
    int cap;

    void resize(int newCap) {
        cap = newCap;
        Item* tempMax = new Item[newCap + 1];
        Item* tempMin = new Item[newCap + 1];
        for (int i = 0; i <= n; ++i) {
            tempMax[i] = pqMax[i];
            tempMin[i] = pqMin[i]; 
        }

        delete[] pqMax;
        delete[] pqMin;

        pqMax = tempMax;
        pqMin = tempMin;
    }

    void sinkMax(int k) {
        while (2 * k <= n) {
            int j = 2 * k;
            if (j < n && pqMax[j] < pqMax[j + 1]) ++j;
            if (pqMax[k] >= pqMax[j]) break;
            std::swap(pqMax[k], pqMax[j]);
            k = j;
        }
    }

    void sinkMin(int k) {
        while (2 * k <= n) {
            int j = 2 * k;
            if (j < n && pqMin[j] > pqMin[j + 1]) ++j;
            if (pqMin[k] <= pqMin[j]) break;
            std::swap(pqMin[k], pqMin[j]);
            k = j;
        }
    }
    
    void swimMax(int k) {
        while (k > 1 && pqMax[k / 2] < pqMax[k]) {
            std::swap(pqMax[k / 2], pqMax[k]);
            k = k / 2;
        }
    }
    
    void swimMin(int k) {
        while (k > 1 && pqMin[k / 2] > pqMin[k]) {
            std::swap(pqMin[k / 2], pqMin[k]);
            k = k / 2;
        }
    }

public:
    MaxMinPQ(int capacity=8) : pqMax(new Item[cap + 1]), pqMin(new Item[cap + 1]), n(0), cap(capacity) {}

    ~MaxMinPQ() {
        delete[] pqMax;
        delete[] pqMin;
    }

    void insert(const Item& x) {
        if (n == cap) resize(2 * cap);
        
        pqMax[++n] = x;
        pqMin[n] = x;

        swimMax(n);
        swimMin(n);
    }

    Item max() {
        if (isEmpty()) throw std::runtime_error("Priority queue underflow");
        return pqMax[1];
    }

    Item min() {
        if (isEmpty()) throw std::runtime_error("Priority queue underflow");
        return pqMin[1];
    }

    Item delMax() {
        Item maxItem = pqMax[1];
        std::swap(pqMax[1], pqMax[n--]);
        sinkMax(1);

        for (int i = 1; i <= n + 1; ++i) {
            if (pqMin[i] == maxItem) {
                std::swap(pqMin[i], pqMin[n + 1]);
                break;
            }
        }
        sinkMin(1);

        if (n > 0 && n == (cap - 1) / 4) resize(cap / 2);
        return maxItem;
    }

    Item delMin() {
        Item minItem = pqMin[1];
        std::swap(pqMin[1], pqMin[n--]);
        sinkMin(1);

        for (int i = 1; i <= n + 1; ++i) {
            if (pqMax[i] == minItem) {
                std::swap(pqMax[i], pqMax[n + 1]);
                break;
            }
        }
        sinkMax(1);

        if (n > 0 && n == (cap - 1) / 4) resize(cap / 2);
        return minItem;
    }

    bool isEmpty() { return n == 0; }

    int size() { return n; }
};