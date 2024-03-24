#include <iostream>

using  namespace std;

class LLQueue {
private:
    struct Node {
        int data;
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
    void enqueue(int item) {
        if(first == nullptr) {
            first = new Node {item, nullptr};
            N++;
            return;
        }
        Node* current = first;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node {item, nullptr};
        N++;
    }


    int dequeue() {
        Node* second = first->next; // store pointer to second node
        int d = first->data;     // store data from first node
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

int main (){
    int m ,n;
    cout << "Enter n and m: ";
    cin >> n >> m;
    LLQueue q;

    for (int i = 0; i < n; i++)
        q.enqueue(i);

    while (q.size() != 1){
        for (int i = 0; i < m-1; i++){
            int temp = q.dequeue();
            q.enqueue(temp);
        }
        cout << q.dequeue() << " ";
    }

    cout << endl << "Safe Spot: " << q.dequeue() << endl;

    return 0;
}