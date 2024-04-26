#include <iostream>

using std::cout, std::endl;

class SafeArray{
private:
    int* arr;
    int size_;
public:
    SafeArray(int size) : size_(size) {
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    SafeArray(const SafeArray& other) : size_(other.size_) {
        arr = new int[size_];
        for (int i = 0; i < size_; i++) {
            arr[i] = other.arr[i];
        }
    }

    ~SafeArray() {
        delete[] arr;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    int size() {
        return size_;
    }

    void print() {
        for (int i = 0; i < size_; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    SafeArray a(5);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    a.print();
    cout << "Size: " << a.size() << endl;
    SafeArray b = a;
    b.print();
    cout << "Size: " << b.size() << endl;
    b[0] = 10;
    b.print();
    cout << "Size: " << b.size() << endl;
    try {
        b[5] = 10;
    }
    catch (std::out_of_range& e) {
        cout << "Caught an exception of type: " << e.what() << endl;
    }
}