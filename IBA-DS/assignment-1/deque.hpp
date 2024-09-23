#pragma once

#include <cassert>
#include <stdexcept>

template <typename Item>
class Deque {
private:
    struct Node {
        Item item;
        Node* next;
        Node* prev;

        Node(Item d) : item(d), next(nullptr), prev(nullptr) {}
    };

    Node* front;
    Node* rear;
    int n;

public:
    // Construct an empty deque
    Deque() : front(nullptr), rear(nullptr), n(0) {}

    // Deallocate memory
    ~Deque() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Is the deque empty?
    bool empty() const {
        return n == 0;
    }

    // Return the number of items on the deque
    int size() const {
        return n;
    }

    // Add the item to the front
    void push_front(const Item& item) {
        Node* newNode = new Node(item);
        if (front == nullptr) {
            rear = newNode;
            front = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        ++n;
    }

    // Add the item to the back
    void push_back(const Item& item) {
        Node* newNode = new Node(item);
        if (rear == nullptr) {
            rear = newNode;
            front = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        ++n;
    }

    // Remove and return the item from the front
    Item pop_front() {
        if (front == nullptr) throw std::runtime_error("Deque is empty");
    
        Node* temp = front;
        Item item = temp->item;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        else
            front->prev = nullptr;
        
        --n;
        delete temp;
        return item;
    }
    Item pop_back() {
        if (rear == nullptr) throw std::runtime_error("Deque is empty");
    
        Node* temp = rear;
        Item item = temp->item;
        rear = rear->prev;
        if(rear == nullptr)
            front = nullptr;
        else
            rear->next = nullptr;
        
        --n;
        delete temp;
        return item;
    }   

    // unit testing
    static void unit_test() {
        Deque<int> deque;

        // Test empty deque
        assert(deque.empty());
        assert(deque.size() == 0);

        // Test push_front
        deque.push_front(1);
        assert(!deque.empty());
        assert(deque.size() == 1);

        deque.push_front(2);
        assert(deque.size() == 2);

        // Test push_back
        deque.push_back(3);
        assert(deque.size() == 3);

        deque.push_back(4);
        assert(deque.size() == 4);

        // Test pop_front
        assert(deque.pop_front() == 2);
        assert(deque.size() == 3);

        assert(deque.pop_front() == 1);
        assert(deque.size() == 2);

        // Test pop_back
        assert(deque.pop_back() == 4);
        assert(deque.size() == 1);

        assert(deque.pop_back() == 3);
        assert(deque.size() == 0);

        // Test empty after pops
        assert(deque.empty());

        // Test exception handling
        try {
            deque.pop_front();
            assert(false); // Should not reach here
        } catch (const std::runtime_error&) {
            assert(true); // Exception caught
        }

        try {
            deque.pop_back();
            assert(false); // Should not reach here
        } catch (const std::runtime_error&) {
            assert(true); // Exception caught
        }
    }
};
