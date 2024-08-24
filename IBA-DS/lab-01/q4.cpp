#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } 
        else { // insert at last Node and point it to head
            Node* temp = head;
            while (temp->next != head) { 
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void eliminate(int m) {
        if (head == nullptr) return;

        Node* current = head;
        Node* prev = nullptr;
        while (current->next != current) {
            // get to m-th Node
            for (int count = 1; count < m; ++count) {
                prev = current;
                current = current->next;
            }

            std::cout << current->value << " ";

            prev->next = current->next;
            delete current;
            current = prev->next;
        }

        std::cout << current->value << std::endl;

        delete current;
    }

};

void josephusProblem(int n, int m) {
    CircularLinkedList cll;
    for (int i = 0; i < n; ++i) {
        cll.append(i);
    }
    cll.eliminate(m);
}

int main() {
    int n = 5, m = 2;
    // int n = 7, m = 3;

    josephusProblem(n, m);

    return 0;
}
