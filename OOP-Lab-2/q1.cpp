#include <iostream>
#include <string>
#include <cctype>
#include <numeric>

using namespace std;

class Rational{
private:
    int n;
    int d;
public:
    Rational(string s){
        string n_string = "";
        string d_string = "";
        for (int i = 0; i < s.size(); i++){
            if (isdigit(s[i])){
                n_string += s[i];
            }
            else{
                d_string = s.substr(i+1, s.size()-i);
                break;
            }
        }
        n = stoi(n_string);
        d = stoi(d_string);
    }
    Rational(double num){
        double eps = 1e-3;
        int denum = 1;
        while(abs(num-int(num)) > eps){
            num *= 10;
            denum *= 10;
        }
        n = int(num);
        d = denum;
        int temp = gcd(n, d);
        n /= temp;
        d /= temp;
    }
    Rational(int a, int b): n{a}, d{b} {}

    int get_num() const {return n;}
    int get_den() const {return d;}

    void set_num(int num){n = num;}
    void set_den(int den){d = den;}

    string toString() const {
        string s = to_string(n) + '/' + to_string(d);
        return s;
    }

    void reduce(){
        int temp = gcd(n, d);
        n /= temp;
        d /= temp;
    }

    Rational operator+(const Rational& r)const{
        Rational new_obj{n*r.d + r.n*d, d*r.d};
        new_obj.reduce();
        return new_obj;
    }

    Rational operator-(const Rational& r)const{
        Rational new_obj{n*r.d - r.n*d, d*r.d};
        new_obj.reduce();
        return new_obj;
    }

    Rational operator*(const Rational& r)const{
        Rational new_obj{n*r.n, d*r.d};
        new_obj.reduce();
        return new_obj;
    }

    Rational operator/(const Rational& r)const{
        Rational new_obj{n*r.d, d*r.n};
        new_obj.reduce();
        return new_obj;
    }

    bool operator==(const Rational& r)const{
        int temp = gcd(n, d);
        int temp_n = n / temp;
        int temp_d = d / temp;
        temp = gcd(r.n, r.d);
        int temp_rn = r.n / temp;
        int temp_rd = r.d / temp;
        return (temp_n==temp_rn && temp_d==temp_rd);
    }

    bool operator!=(const Rational& r)const{
        int temp = gcd(n, d);
        int temp_n = n / temp;
        int temp_d = d / temp;
        temp = gcd(r.n, r.d);
        int temp_rn = r.n / temp;
        int temp_rd = r.d / temp;
        return (temp_n!=temp_rn || temp_d!=temp_rd);
    }


};

int main(){
    Rational r1(0.75);
    Rational r2("3/4");
    Rational r3(0.3);
    cout << "r1 is " << r1.toString() << endl;
    cout << "r2 is " << r2.toString() << endl;
    cout << "r3 is " << r3.toString() << endl;
    cout << (r1+r2).toString() << endl;
    cout << (r1-r2).toString() << endl;
    cout << (r1*r2).toString() << endl;
    cout << (r1/r2).toString() << endl;
    cout << boolalpha << (r1==r2) << endl;
    cout << boolalpha << (r1==r3) << endl;

    return 0;
}