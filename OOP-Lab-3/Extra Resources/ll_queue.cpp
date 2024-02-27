#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

class LLQueue {
    private:
    struct Node {
        string data;
        Node* next;
    };

    Node *first = nullptr;
    int N = 0;

public:
    LLQueue() = default;

    ~LLQueue() {
        while (first != nullptr) {
            Node* second = first->next;
            delete first;
            first = second;
        }
    }

    // linear time 
    void enqueue(string item) {
        if(first == nullptr) {
            first = new Node {item, nullptr};
            return;
        }
        Node* current = first;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node {item, nullptr};
    }


    string dequeue() {
        Node* second = first->next; // store pointer to second node
        string d = first->data;     // store data from first node
        delete first;               // delete first node
        first = second;             // second becomes the fist node
        N--;                        // decrement size
        return d;                   // return data
    }
    bool empty() { 
        return first == nullptr;
        //return N == 0; // Equivalently
    }

    int size() {
        return N;
    }

};

int main() {
    LLQueue q;
    q.enqueue("hello");
    q.enqueue("world");
    q.enqueue("how");
    q.enqueue("are");
    q.enqueue("you");
    while (!q.empty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;

}