#include <iostream>

using std::cout;

struct vector2D{
    double x;
    double y; 
};

void print(const vector2D& v);
vector2D add(const vector2D& v1, const vector2D& v2);
vector2D operator+(const vector2D& v1, const vector2D& v2);
vector2D operator*(const vector2D& v, double s);
void operator*=(vector2D& v, double s);
double dot(const vector2D& v1, const vector2D& v2);

int main(){
    vector2D v1 {1.2, 3.4};
    vector2D v2 {5.6, 7.8};
    print(v1);
    cout << "\n";
    print(v2); 
    cout << "\n";
    vector2D v3 = add(v1, v2);
    print(v3); 
    cout << "\n";
    vector2D v4 = v1 + v2;
    print(v4); 
    cout << "\n";
    vector2D v5 = v1 * 2.0;
    print(v5); 
    cout << "\n";
    v1 *= 2.0;
    print(v1); 
    cout << "\n";
    double d = dot(v1, v2);
    cout << d << "\n";

    return 0;
}

void print(const vector2D& v){
    cout << "(" << v.x << ", " << v.y << ")";
}

vector2D add(const vector2D& v1, const vector2D& v2){
    vector2D v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    return (v3);
}

vector2D operator+(const vector2D& v1, const vector2D& v2){
    vector2D v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    return (v3);
}

vector2D operator*(const vector2D& v, double s){
    vector2D v1;
    v1.x = v.x * s;
    v1.y = v.y * s;
    return v1;
}

void operator*=(vector2D& v, double s){
    vector2D v1;
    v.x = v.x * s;
    v.y = v.y * s;
}

double dot(const vector2D& v1, const vector2D& v2){
     return (v1.x*v2.x+v1.y*v2.y);
}