#include <iostream>

using namespace std;

template <typename T>
class Complex{
private:
    T real;
    T imag;
public:
    Complex(T r, T i): real(r), imag(i){}
    
    void print(){
        cout << real << " + i" << imag << endl;
    }
};

int main(){
    Complex<int> c1(3, 4);
    Complex<double> c2(1.2, 3.4);
    c1.print();
    c2.print();
    return 0;
}