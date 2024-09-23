/******************************************************************
 * @file randomizedQueue-test.cpp
 * @brief This file contains the main function to run unit tests for the RandomizedQueue class.
 *
 * The RandomizedQueue class supports the following operations with their respective time complexities:
 * - Constructor: O(1) 
 * - Destructor: O(1) 
 * - enqueue(item): O(1) amortized - Adds an item to the queue.
 * - dequeue(): O(1) amortized - Removes and returns a random item from the queue.
 * - sample(): O(1) - Returns (but does not remove) a random item from the queue.
 * - isEmpty(): O(1) - Checks if the queue is empty.
 * - size(): O(1) - Returns the number of items in the queue.
 ******************************************************************/


/******************************************************************
 * Each item takes no extra space as the item is stored in an array
 * Therefore the condition in exercise 2 is upheld 
******************************************************************/


#include <iostream>
#include "randomizedQueue.hpp"

int main() {
    RandomizedQueue<int>::unit_test();
    std::cout << "All unit tests passed!" << std::endl;

    return 0;
}