#include <iostream>
#include <string>

using std::string;

constexpr int MAX = 1'000'000;

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

class ResizingArrayStackOfStrings {
    private:
    int N; // denotes the number of elements in the stack
    int capacity; // denotes the capacity of the stack
    string *s;

    public:
    ResizingArrayStackOfStrings() : N {0}, capacity {1}, s {new string[capacity]} {
    }

    ~ResizingArrayStackOfStrings() {
        delete[] s;
    }

    void push(const string& item) {
        if(N == capacity) resize(2*capacity); // double the capacity if the stack is full
        s[N++] = item;  // same as a[N] = item; N++;
    }

    string pop() {
        if(N<=0) throw std::out_of_range("Stack is empty"); // stack must not be empty
        if(N > 0 && N <= capacity/4) resize(capacity/2); // halve the capacity if the stack is 1/4 full
        return s[--N];  // same as N--; return a[N];
    }   

    bool empty() { return N == 0; }   

    int size()   {   return N;    }   

    private:
    void resize(int newcap) {
        string* copy = new string[newcap];
        for(int i=0; i<N && i<newcap; ++i) 
            copy[i] = std::move(s[i]);
        delete[] s;
        s = copy;
        capacity = newcap;       
    }

};

template<typename T>
void calculateAverageExecutionTime(T stack);

template<typename T>
void calculateWorstExecutionTime(T stack);

int main() {
    calculateAverageExecutionTime(LinkedStackOfStrings{});
    calculateAverageExecutionTime(ResizingArrayStackOfStrings{});

    calculateWorstExecutionTime(LinkedStackOfStrings{});
    calculateWorstExecutionTime(ResizingArrayStackOfStrings{});

    return 0;
}

template<typename T>
void calculateAverageExecutionTime(T stack) {
    clock_t start, end;

    start = clock();

    for (int i = 0; i < MAX; ++i) {
        stack.push("foo");
    }

    end = clock();

    double timeTaken = double(end - start) / double(CLOCKS_PER_SEC);
    
    std::cout << "Average Time Taken: " << timeTaken / MAX << " seconds\n";
}

template<typename T>
void calculateWorstExecutionTime(T stack) {
    clock_t start, end;
    double worstTime = -1;

    for (int i = 0; i < MAX; ++i) {
        start = clock();
        stack.push("foo");
        end = clock();

        double timeTaken = double(end - start) / double(CLOCKS_PER_SEC);
        worstTime = std::max<double>(worstTime, timeTaken);
    }

    std::cout << "Most Time Taken: " << worstTime << " seconds\n";
}
