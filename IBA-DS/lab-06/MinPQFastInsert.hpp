#include <algorithm>
#include <stdexcept>
#include <vector>

template <typename Item>
class MinPQ {
private:
    std::vector<Item> pq;  // store items at indices 1 to n
    int n;                 // number of items on priority queue

    void resize(int capacity) {
        pq.resize(capacity);
    }

    void swim(int k) {
        // find correct position to insert
        Item item = pq[k];
        int lo = 1, hi = k;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (pq[mid] < item) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        // swap to correct postion
        for (int i = k; i > lo; i--) {
            pq[i] = pq[i - 1];
        }
        pq[lo] = item;
    }

    void sink(int k) {
        while (2 * k <= n) {
            int j = 2 * k;
            if (j < n && pq[j] > pq[j + 1]) j++;
            if (pq[k] <= pq[j]) break;
            std::swap(pq[k], pq[j]);
            k = j;
        }
    }

public:
    MinPQ(int capacity = 8) : pq(capacity + 1), n(0) {}

    bool isEmpty() const {
        return n == 0;
    }

    int size() const {
        return n;
    }

    Item min() const {
        if (isEmpty()) throw std::runtime_error("Priority queue underflow");
        return pq[1];
    }

    void insert(const Item& x) {
        if (n == pq.size() - 1) resize(2 * pq.size());
        pq[++n] = x;
        swim(n);
    }

    Item delMin() {
        if (isEmpty()) throw std::runtime_error("Priority queue underflow");
        Item min = pq[1];
        std::swap(pq[1], pq[n--]);
        sink(1);
        pq.pop_back();
        if ((n > 0) && (n == (pq.size() - 1) / 4)) resize(pq.size() / 2);
        return min;
    }
};
