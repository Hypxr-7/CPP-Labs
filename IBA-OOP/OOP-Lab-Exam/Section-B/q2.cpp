#include <iostream>

template <typename T>
class Container {
private:
    T* values;
    int capacity;
    int counter;

public:
    Container(int capacity) : capacity(capacity), counter(0) {
        values = new T[capacity];
    }

    ~Container() {
        delete[] values;
    }

    bool isFull() const {
        return counter == capacity;
    }

    void insert(const T& value) {
        if (!isFull())
            values[counter++] = value;
        else
            std::cout << "Container is full. Cannot insert more elements." << std::endl;
    }

    bool search(const T& value) const {
        for (int i = 0; i < counter; ++i)
            if (values[i] == value)
                return true;
        return false;
    }

    void remove(const T& value) {
        for (int i = 0; i < counter; ++i) {
            if (values[i] == value) {
                for (int j = i; j < counter - 1; ++j)
                    values[j] = values[j + 1];
                counter--;
                return;
            }
        }
        std::cout << "Value not found. Cannot remove." << std::endl;
    }

    void print() const {
        for (int i = 0; i < counter; ++i)
            std::cout << values[i] << " ";
        std::cout << std::endl;
    }
};


void testContainer() {
    Container<int> intContainer(5);
    std::cout << "Inserting integers into the container:" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        intContainer.insert(i * 10);
    }
    std::cout << "Container content: ";
    intContainer.print();
    std::cout << "Searching for value 30: " << (intContainer.search(30) ? "Found" : "Not found") << std::endl;
    std::cout << "Removing value 30..." << std::endl;
    intContainer.remove(30);
    std::cout << "Container content after removal: ";
    intContainer.print();
    std::cout << std::endl;

    Container<double> doubleContainer(4);
    std::cout << "Inserting doubles into the container:" << std::endl;
    for (double d = 1.11; d <= 4.44; d += 1.11) {
        doubleContainer.insert(d);
    }
    std::cout << "Container content: ";
    doubleContainer.print();
    std::cout << "Searching for value 3.33: " << (doubleContainer.search(3.33) ? "Found" : "Not found") << std::endl;
    std::cout << "Removing value 3.33..." << std::endl;
    doubleContainer.remove(3.33);
    std::cout << "Container content after removal: ";
    doubleContainer.print();
    std::cout << std::endl;
}

int main() {
    testContainer();
    return 0;
}
