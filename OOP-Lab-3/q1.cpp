#include <iostream>
#include <string>

using std::string, std::cout, std::endl, std::cin;

class LLStack {
private:
    struct Node {
        char data;
        Node* next;
    };

    Node *first = nullptr;
    int N = 0;

public:
    LLStack() = default;

    ~LLStack() {
        while (first != nullptr) {
            Node* second = first->next;
            delete first;
            first = second;
        }
    }

    void push(char item) {
        Node* second = first;            // first node will be second node
        first = new Node {item, second}; // create new first node
        N++;                             // increment size
    }

    char pop() {
        Node* second = first->next; // store pointer to second node
        char d = first->data;     // store data from first node
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
    LLStack s;
    string brackets;
    cout << "Enter: ";
    cin >> brackets;

    for (char c: brackets){
        if (c == '[' || c == '{' || c == '(')
            s.push(c);
        if (c == ']' || c == '}' || c == ')') {
            if (s.empty()) break;
            char cur_c = s.pop();
            if (c == ']' && cur_c == '[')
                break;
            else if (c == '}' && cur_c == '{')
                break;
            else if (c == ')' && cur_c == '(')
                break;
        }
    }

    if (s.empty())
        cout << "Brackets are wrong" << endl;
    else
        cout << "Brackets are right" << endl;

    return 0;
}