#include <cassert>

#include "LRU_cache.hpp"

void testAccess() {
    LRU cache;
    cache.access(1);
    cache.access(2);
    cache.access(3);
    assert(cache.contains(1));
    assert(cache.contains(2));
    assert(cache.contains(3));
    assert(cache.size() == 3);
}

void testRemove() {
    LRU cache;
    cache.access(1);
    cache.access(2);
    cache.access(3);
    int removedItem = cache.remove();
    assert(removedItem == 1);
    assert(!cache.contains(1));
    assert(cache.size() == 2);
}

void testContains() {
    LRU cache;
    cache.access(1);
    cache.access(2);
    assert(cache.contains(1));
    assert(cache.contains(2));
    assert(!cache.contains(3));
}

void testSize() {
    LRU cache;
    assert(cache.size() == 0);
    cache.access(1);
    assert(cache.size() == 1);
    cache.access(2);
    assert(cache.size() == 2);
    cache.remove();
    assert(cache.size() == 1);
}

void testEmpty() {
    LRU cache;
    assert(cache.empty());
    cache.access(1);
    assert(!cache.empty());
    cache.remove();
    assert(cache.empty());
}

void testPrint() {
    LRU cache;
    cache.access(1);
    cache.access(2);
    cache.access(3);
    cache.print();  // Expected output: 3 2 1
}

int main() {
    testAccess();
    testRemove();
    testContains();
    testSize();
    testEmpty();
    testPrint();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}