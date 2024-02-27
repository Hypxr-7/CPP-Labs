#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Polynomial{
private:
    int a;
    int b;
    int c;
public:
    Polynomial() : a(1), b(1), c(1){
    }

    Polynomial(int n1, int n2, int n3) : a(n1), b(n2), c(n3){
    }

    string format(){
        string s = to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c);
        return s;
    }

    int eval(int x){
        return (a*x*x + b*x + c);
    }

    Polynomial operator+(const Polynomial& obj){
        Polynomial poly;
        poly.a = a + obj.a;
        poly.b = b + obj.b;
        poly.c = c + obj.c;
        return poly;
    }

    int& operator[](int index){
        switch (index) {
            case 0:
                return a;
                break;
            case 1:
                return b;
                break;
            case 3:
                return c;
                break;
            default:
                exit(1);
        }

    }

    bool operator==(const Polynomial& obj){
        return (a == obj.a && b == obj.b && c == obj.c);
    }

};

int main(){
    Polynomial p1(1, 2, 5);
    Polynomial p2(2, 3, 7);
    cout << "Polynomial 1:" << p1.format() << endl;
    cout << "Polynomial 2:" << p2.format() << endl;
    cout << "P1 when x is 2: " << p1.eval(2) << endl;
    cout << "Sum of both: " << (p1 + p2).format() << endl;
    p1[0] = 3;
    cout << "a of P1 is changed to 3: " << p1.format() << endl;
    cout << "P1 = P2? " << boolalpha << (p1 == p2) << endl;
    Polynomial p3(3, 2, 5);
    cout << "P1 = P3? (p3 is a copy of p1) " << boolalpha << (p1 == p3) << endl;


    return 0;
}