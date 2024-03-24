#include <iostream>
#include <string>
#include <cassert>

using std::string, std::cout, std::cin;

class RAStack {
    private:
    string *arr = nullptr;
    int sz; // denotes the number of elements in the stack
    int cap; // denotes the capacity of the stack

    public:
    RAStack() : sz {0}, cap {2}, arr {new string[cap]} {
    }

    ~RAStack() {
        delete[] arr;
    }

    void push(string s) {
        if(sz == cap) resize(2*cap); // double the capacity if the stack is full
        arr[sz++] = s;  // same as a[N] = s; N++;
    }

    string pop() {
        assert(sz > 0); // stack must not be empty
        if(sz > 0 && sz == cap/4) resize(cap/2); // halve the capacity if the stack is 1/4 full
        return arr[--sz];  // same as N--; return a[N];
    }   

    bool empty() { return sz == 0; }   

    int size()   {   return sz;    }   

    private:
    void resize(int newcap) {
        assert(newcap >= sz); // new capacity must be greater than or equal to the number of elements in the stack
        string* newarr = new string[newcap];
        for(int i=0; i<sz; ++i) 
            newarr[i] = arr[i];
        delete[] arr;
        arr = newarr;
        cap = newcap;       
    }

};

int main() {
    RAStack stack;

    cout << "Enter a sequence of words ('-' means pop otherwise push): ";
    for(string s; cin >> s; ) {
        if (s == "-") 
            cout << stack.pop() << " ";
        else 
            stack.push(s);
    }

    cout << "(" << stack.size() << " left on stack)\n";
}