#include <iostream>

template<typename T, int N>
class Array{
private:
    T elements[N];
public:
    Array(std::initializer_list<T> init_list){
        int i = 0;
        for (T item : init_list){
            if (i >= N) throw std::out_of_range("Values more than siz of array");
            elements[i++] = item;
        }

        for (; i < N; i++) elements[i] = T{};
    }

    Array(const Array& other){
        std::copy(std::begin(other.elements), std::end(other.elements), elements);
    }

    Array& operator=(const Array& other){
        if (this != &other)
            std::copy(std::begin(other.elements), std::end(other.elements), elements);
        return *this;
    }

    T& operator[](int index){
        if (index < 0 || index >= N) throw std::out_of_range("Index out of range");
        return elements[index];
    }

    [[nodiscard]] constexpr int size() const {
        return N;
    }

    void fill(T value){
        for (int i = 0; i < N; i++)
            elements[i] = value;
    }

    friend std::ostream& operator<<(std::ostream& os, const Array& arr){
        for (int i = 0; i < N; i++)
            os << arr.elements[i] << ' ';
        return os;
    }

    using Value = T;
};

int main() {
    Array<int, 5> arr = {1, 2, 3, 4, 5};
    std::cout << "Array: " << arr << '\n';

    const auto& arr2 = arr;
    std::cout << "Array: " << arr2 << '\n';

    std::cout << typeid(Array<double, 5>::Value).name();

    return 0;
}
