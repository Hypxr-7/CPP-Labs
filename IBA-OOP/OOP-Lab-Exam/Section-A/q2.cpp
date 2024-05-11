#include <iostream>

template <typename T>
class SmartPointer {
private:
    T* ptr;
    int* refCount;

public:
    SmartPointer(T* p = nullptr) : ptr(p), refCount(new int(1)) {}

    SmartPointer(const SmartPointer& sp) : ptr(sp.ptr), refCount(sp.refCount) {
        (*refCount)++;
    }

    SmartPointer& operator=(const SmartPointer& sp) {
        if (this != &sp) {
            if (--(*refCount) == 0) {
                delete ptr;
                delete refCount;
            }
            ptr = sp.ptr;
            refCount = sp.refCount;
            (*refCount)++;
        }
        return *this;
    }

    ~SmartPointer() {
        if (--(*refCount) == 0) {
            delete ptr;
            delete refCount;
        }
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* get() const {
        return ptr;
    }
};

int main() {
    SmartPointer<int> ptr1(new int(42));

    {
        SmartPointer<int> ptr2 = ptr1;
        std::cout << "Value pointed by ptr2: " << *ptr2 << std::endl;
        *ptr2 = 100;
        std::cout << "Modified value pointed by ptr2: " << *ptr2 << std::endl;
    }

    std::cout << "Value pointed by ptr1: " << *ptr1 << std::endl;

    SmartPointer<double> ptr3(new double(3.14));

    return 0;
}
