/******************************************************************
 * @file deque-test.cpp
 * @brief This file contains the unit test for the Deque class.
 *
 * The Deque class is a double-ended queue that allows insertion and deletion 
 * of elements from both ends. The following are the time complexities for 
 * each operation of the Deque:
 *
 * - Construction of deque: O(1)
 * - Destruction of deque: O(n)
 * - Insertion at the front: O(1)
 * - Insertion at the back: O(1)
 * - Deletion from the front: O(1)
 * - Deletion from the back: O(1)
 * - Checking if the deque is empty: O(1)
 * - Getting the size of the deque: O(1)
 ******************************************************************/


/******************************************************************
 * The size of each pointer is 8 bytes
 * If we disregard the size of the item, each item will use 16 bytes
 * 8 bytes for the front and rear pointer
 * This upholds the condition specified in exercise 1
 ******************************************************************/


#include <iostream>
#include "deque.hpp"



int main() {
    Deque<int>::unit_test();
    std::cout << "All tests passed\n";

    return 0;
}