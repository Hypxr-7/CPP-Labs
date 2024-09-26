#include "MaxPQ.hpp"
#include "MinPQ.hpp"
#include <limits>

template <class T>
class MedianPQ {
private:
    // Values greater than the median sorted so that smallest is on top
    MinPQ<T> upper;
    // Values smaller than the median sorted so that greatest is on top
    MaxPQ<T> lower;

public:
    MedianPQ() {
        // Seed the queues
        upper.insert(std::numeric_limits<T>::max());
        lower.insert(std::numeric_limits<T>::min());
    }

    void push(T val) {
        // If number is greater than the least upper number, it is an upper number
        if (val >= upper.min())
            upper.insert(val);
        else // Otherwise it is a lower number
            lower.insert(val);

        // Rebalance
        // If the queues sizes differ by 2, they need to be rebalanced so that they
        // differ by 1.
        if (upper.size() - lower.size() == 2) { // Upper queue is larger
            lower.insert(upper.delMin()); // Move value from upper to lower
        }
        else if (lower.size() - upper.size() == 2) { // Lower queue is larger
            upper.insert(lower.delMax()); // Move value from lower to upper
        }
    }

    T getMedian() const {
        if (upper.size() == lower.size())                  // Upper and lower are same size
            return (upper.min() + lower.max()) / ((T)2.0); // so median is average of least upper and greatest lower
        else if (upper.size() > lower.size())              // Upper size greater
            return upper.min();
        else                                               // Lower size greater
            return lower.max();
    }
    
    void removeMedian() {
        if (upper.size() == lower.size()) {
            // If both heaps are of the same size, remove the top element from the upper heap
            upper.delMin();
        } else if (upper.size() > lower.size()) {
            // If the upper heap is larger, remove the top element from the upper heap
            upper.delMin();
        } else {
            // If the lower heap is larger, remove the top element from the lower heap
            lower.delMax();
        }
    }
};
