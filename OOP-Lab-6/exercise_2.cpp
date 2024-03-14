#include <iostream>

using std::cout, std::endl;

class SafeArray{
protected:
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

class SafeVector : public SafeArray{
public:
    SafeVector(int size) : SafeArray(size) {
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }

    ~SafeVector() {
        delete[] arr;
    }

    void push_back(int value) {
        int* temp = new int[size_ + 1];
        for (int i = 0; i < size_; i++)
            temp[i] = arr[i];
        temp[size_] = value;
        delete[] arr;
        arr = temp;
        size_++;
    }

    void pop_back() {
        if (size_ == 0) {
            throw std::underflow_error("Vector is empty");
        }

        int* temp = new int[size_ - 1];
        for (int i = 0; i < size_ - 1; i++)
            temp[i] = arr[i];
        delete[] arr;
        arr = temp;
        size_--;
    }

    int back() {
        return arr[size_ - 1];
    }


};

int main() {
    SafeVector a(5);

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;

    a.print();
    cout << "Size: " << a.size() << endl;

    SafeVector b = a;
    b.print();
    cout << "Size: " << b.size() << endl;

    b[0] = 10;
    b.print();
    cout << "Size: " << b.size() << endl;

    try {
        b[5] = 10;
    } catch (std::out_of_range& e) {
        cout << e.what() << endl;
    }

    b.push_back(6);
    b.print();
    cout << "Size: " << b.size() << endl;
    
    b.pop_back();
    b.print();
    cout << "Size: " << b.size() << endl;


    b.print();
    cout << "Size: " << b.size() << endl;
    cout << "Back: " << b.back() << endl;

    return 0;
}