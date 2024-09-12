#pragma once

template<typename T>
class RAStack {
private:
    T* stk;
    int n;
    int cap;

    void resize() {
        cap *= 2;
        T* copy =  new T[cap];

        for (int i = 0; i < n; ++i) {
            copy[i] = stk[i];
        }

        delete[] stk;
        stk = copy;

    }

public:
    RAStack() : stk(new T[2]), n(0), cap(2) {} 
    
    ~RAStack() {
        delete[] stk;
    }

    void push(T item) {
        if (cap == n) {
            resize();
        }
        stk[n++] = item;
    }

    T pop() {
        if (isEmpty()) throw std::out_of_range("stack is empty");
        return stk[--n];
    }

    bool isEmpty() {
        return n == 0;
    }

    int size() {
        return n;
    }
};