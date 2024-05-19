#include <iostream>

template <typename T>
class Complex {
private:
    T real;
    T imaginary;
public:
    Complex(T real_, T imaginary_) : real(real_), imaginary(imaginary_) {}

    void Print(){
        std::cout << real << '+' << imaginary << "i\n";
    }
};

int main(){
    Complex c1(1, 2);
    Complex c2(-1.0, -3.5);

    c1.Print();
    c2.Print();

    return 0;
}