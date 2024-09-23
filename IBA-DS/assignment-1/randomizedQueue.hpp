#pragma once

#include <cassert>
#include <stdexcept>

template<typename Item>
class RandomizedQueue {
private:
    Item* queue;
    int n;
    int first;
    int last;
    int capacity;
    int randIndex;

    void resize(int new_capacity) {
        Item* temp = new Item[new_capacity];
        for (int i = 0; i < n; i++) {
            temp[i] = queue[(first + i) % capacity];
        }
        delete[] queue;
        queue = temp;
        first = 0;
        last = n;
        capacity = new_capacity;
    }

    void setRandIndex() {
        if (n == 0) {
            randIndex = -1; // No valid index if the queue is empty
        } else {
            randIndex = first + rand() % n;
            if (randIndex >= capacity) {
            randIndex -= capacity; // Wrap around if necessary
            }
        }
    }

public:
    // construct an empty randomized queue
    RandomizedQueue() : n(0), first(0), last(0), capacity(8), randIndex(-1) {
        queue = new Item[capacity];
    }

    // deallocate memory
    ~RandomizedQueue() {
        delete[] queue;
    }

    // is the randomized queue empty?
    bool empty() const {
        return n == 0;
    }

    // return the number of items on the randomized queue
    int size() const {
        return n;
    }

    // add the item
    void enqueue(const Item& item) {
        if (n == capacity) resize(2 * capacity);

        queue[last++] = item;
        if (last == capacity) last = 0; // wrap around
        ++n;
    }

    // remove and return a random item
    Item dequeue() {        
        if (empty()) throw std::runtime_error("Randomized Queue is empty");

        if (randIndex == -1) setRandIndex();

        Item item = queue[randIndex];
        queue[randIndex] = queue[first];
        queue[first] = item;
        item = queue[first];

        if (last == 0)
            last = capacity - 1;
        else
            --last;

        queue[first] = queue[last];
        if (last < 0) last = capacity - 1;
        --n;

        setRandIndex();

        return item;
    }

    // return a random item (but do not remove it)
    Item sample() {
        if (empty()) throw std::runtime_error("Randomized Queue is empty");

        if (randIndex == -1) setRandIndex();

        return queue[randIndex];
        
    }

    // unit testing (required)
    static void unit_test() {
        RandomizedQueue<int> rq;

        // Test enqueue and size
        rq.enqueue(1);
        rq.enqueue(2);
        rq.enqueue(3);
        assert(rq.size() == 3);

        // Test sample (should not change the size)
        int sample = rq.sample();
        assert(rq.size() == 3);

        // Test dequeue and size
        int item1 = rq.dequeue();
        assert(rq.size() == 2);

        int item2 = rq.dequeue();
        assert(rq.size() == 1);

        int item3 = rq.dequeue();
        assert(rq.size() == 0);

        // Test empty
        assert(rq.empty());

        // Test exception on dequeue from empty queue
        try {
            rq.dequeue();
            assert(false); // Should not reach here
        } catch (const std::runtime_error&) {
            assert(true); // Exception should be thrown
        }

        // Test exception on sample from empty queue
        try {
            rq.sample();
            assert(false); // Should not reach here
        } catch (const std::runtime_error&) {
            assert(true); // Exception should be thrown
        }

        // Test for wrap around

        // Fill the queue to its initial capacity to force a wrap around
        for (int i = 0; i < 8; ++i) {
            rq.enqueue(i);
        }

        // Dequeue a few elements to create space at the beginning
        for (int i = 0; i < 3; ++i) {
            rq.dequeue();
        }

        // Enqueue more elements to wrap around to the beginning of the array
        rq.enqueue(8);
        rq.enqueue(9);
        rq.enqueue(10);

        // Check the size after wrap around
        assert(rq.size() == 8);

        // Dequeue all elements and check if they are correct
        for (int i = 3; i < 11; ++i) {
            int item = rq.dequeue();
            assert(item >= 0 && item < 11);
        }

        // Check if the queue is empty after all dequeues
        assert(rq.empty());

    }
};