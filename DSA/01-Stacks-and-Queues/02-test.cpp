#include <iostream>
#include "02-RAStack.hpp"

void testRAStack() {
    RAStack<int> stack;

    // Test isEmpty on a new stack
    if (stack.isEmpty()) {
        std::cout << "Test 1 Passed: Stack is empty on initialization." << std::endl;
    } else {
        std::cout << "Test 1 Failed: Stack is not empty on initialization." << std::endl;
    }

    // Test push and size
    stack.push(10);
    stack.push(20);
    if (stack.size() == 2) {
        std::cout << "Test 2 Passed: Stack size is correct after two pushes." << std::endl;
    } else {
        std::cout << "Test 2 Failed: Stack size is incorrect after two pushes." << std::endl;
    }

    // Test pop
    int poppedValue = stack.pop();
    if (poppedValue == 20) {
        std::cout << "Test 3 Passed: Popped value is correct." << std::endl;
    } else {
        std::cout << "Test 3 Failed: Popped value is incorrect." << std::endl;
    }

    // Test size after pop
    if (stack.size() == 1) {
        std::cout << "Test 4 Passed: Stack size is correct after one pop." << std::endl;
    } else {
        std::cout << "Test 4 Failed: Stack size is incorrect after one pop." << std::endl;
    }

    // Test isEmpty after pop
    stack.pop();
    if (stack.isEmpty()) {
        std::cout << "Test 5 Passed: Stack is empty after popping all elements." << std::endl;
    } else {
        std::cout << "Test 5 Failed: Stack is not empty after popping all elements." << std::endl;
    }

    // Test exception on pop from empty stack
    try {
        stack.pop();
        std::cout << "Test 6 Failed: No exception thrown on pop from empty stack." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Test 6 Passed: Exception thrown on pop from empty stack." << std::endl;
    }
}

int main() {
    testRAStack();
    return 0;
}