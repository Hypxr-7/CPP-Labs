#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

class LLStack {
    private:
    struct Node {
        string data;
        Node* next;
    };

    Node *first = nullptr;
    int N = 0;

public:
    LLStack() = default;

    LLStack(const LLStack& other);

    ~LLStack() {
        while (first != nullptr) {
            Node* second = first->next;
            delete first;
            first = second;
        }
    }

    void push(string item) {
        Node* second = first;            // first node will be second node
        first = new Node {item, second}; // create new first node
        N++;                             // increment size
    }

    string pop() {
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

LLStack::LLStack(const LLStack& other) {
    Node* temp = other.first;
    while (temp != nullptr) {
        push(temp->data);
        temp = temp->next;
    }
}

int main() {
    LLStack s;
    s.push("hello");
    s.push("world");
    s.push("how");
    s.push("are");
    s.push("you");
    
    LLStack t {s};
    t.pop();
    t.pop();
    t.push("test");

    cout << "s: ";
    while (!s.empty()) {
        cout << s.pop() << " ";
    }
    cout << endl;

    cout << "t: ";
    while (!t.empty()) {
        cout << t.pop() << " ";
    }

    return 0;
}