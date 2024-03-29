#pragma once

#include <string>
#include <iostream>
#include <numeric>

class Fraction {
private:
    void Reduce();
    int numerator;
    int denominator;
public:
    // Constructors
    Fraction();
    Fraction(int numerator, int denominator = 1);
    Fraction(double value);
    Fraction(std::string value);

    // Copy Constructos
    Fraction(const Fraction& other);
    Fraction operator=(const Fraction& other);

    // Binary operators
    Fraction operator+(const Fraction& other);
    Fraction operator-(const Fraction& other);
    Fraction operator*(const Fraction& other);
    Fraction operator/(const Fraction& other);

    // Unary operators
    Fraction operator--();
    Fraction operator++();

    // Compound assignment operators
    Fraction operator +=(const Fraction& other);
    Fraction operator -=(const Fraction& other);
    Fraction operator *=(const Fraction& other);
    Fraction operator /=(const Fraction& other);

    // Comparison operators
    bool operator==(const Fraction& other);
    bool operator!=(const Fraction& other);
    bool operator<(const Fraction& other);
    bool operator>(const Fraction& other);
    bool operator<=(const Fraction& other);
    bool operator>=(const Fraction& other);

    // iostream operators
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
};