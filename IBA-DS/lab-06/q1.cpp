#include "MaxMinPQ.hpp"
#include <iostream>
#include <cassert>

void testInsert() {
    MaxMinPQ<int> pq;
    pq.insert(10);
    pq.insert(20);
    pq.insert(5);
    assert(pq.max() == 20);
    assert(pq.min() == 5);
    std::cout << "testInsert passed!" << std::endl;
}

void testDelMax() {
    MaxMinPQ<int> pq;
    pq.insert(10);
    pq.insert(20);
    pq.insert(5);
    assert(pq.delMax() == 20);
    assert(pq.max() == 10);
    assert(pq.min() == 5);
    std::cout << "testDelMax passed!" << std::endl;
}

void testDelMin() {
    MaxMinPQ<int> pq;
    pq.insert(10);
    pq.insert(20);
    pq.insert(5);
    assert(pq.delMin() == 5);
    assert(pq.max() == 20);
    assert(pq.min() == 10);
    std::cout << "testDelMin passed!" << std::endl;
}

void testIsEmpty() {
    MaxMinPQ<int> pq;
    assert(pq.isEmpty());
    pq.insert(10);
    assert(!pq.isEmpty());
    pq.delMax();
    assert(pq.isEmpty());
    std::cout << "testIsEmpty passed!" << std::endl;
}

void testSize() {
    MaxMinPQ<int> pq;
    assert(pq.size() == 0);
    pq.insert(10);
    pq.insert(20);
    assert(pq.size() == 2);
    pq.delMax();
    assert(pq.size() == 1);
    pq.delMin();
    assert(pq.size() == 0);
    std::cout << "testSize passed!" << std::endl;
}

int main() {
    testInsert();
    testDelMax();
    testDelMin();
    testIsEmpty();
    testSize();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
