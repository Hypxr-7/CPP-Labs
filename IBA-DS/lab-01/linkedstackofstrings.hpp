#pragma once

#include <iostream>
#include <string>

using std::string;

class LinkedStackOfStrings {
private:
    struct Node {
        string item;
        Node* next;
    };

    Node* first;

public:
    LinkedStackOfStrings() : first(nullptr) { }

    ~LinkedStackOfStrings() {
        while (first != nullptr) {
            Node* second = first->next;
            delete first;
            first = second;
        }
    }

    void push(const string& item) {
        Node *oldfirst = first;          // save pointer to current first node
        first = new Node;                // create new node
        first->item = item;              // set data of new node
        first->next = oldfirst;          // set next of new node to old first node
        // first = new Node {item, oldfirst}; // equivalently in C++11
    }

    string pop() {
        string item = first->item;     // store data from first node
        Node* second = first->next;    // store pointer to current second node
        //auto [data, second] = *first;  // equivalently in C++17
        delete first;                 // delete first node
        first = second;               // second becomes the first node
        return item;                  // return data
    }

    bool empty() { 
        return first == nullptr;
    }

    string top() {
        return first->item;
    }

};
