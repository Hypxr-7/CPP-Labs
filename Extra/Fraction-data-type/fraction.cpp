#include "fraction.hpp"

void Fraction::Reduce() {
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    this->numerator = numerator;
    this->denominator = denominator;
    Reduce();
}

Fraction::Fraction(double value) {
    int sign = 1;
    if (value < 0) {
        sign = -1;
        value = -value;
    }
    int whole = value;
    value -= whole;
    int gcd = 1;
    int digit;
    while (value != 0) {
        value *= 10;
        digit = value;
        gcd *= 10;
        value -= digit;
    }
    numerator = sign * (whole * gcd + digit);
    denominator = gcd;
    Reduce();
}

Fraction::Fraction(std::string value) {
    if (value.find('/') == std::string::npos) {
        throw std::invalid_argument("Invalid fraction format");
    }
    numerator = stoi(value.substr(0, value.find('/')));
    denominator = stoi(value.substr(value.find('/') + 1));
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    Reduce();
}

Fraction::Fraction(const Fraction& other) {
    numerator = other.numerator;
    denominator = other.denominator;
}

Fraction Fraction::operator=(const Fraction& other) {
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

Fraction Fraction::operator+(const Fraction& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator = denominator * other.denominator;
    Reduce();
    return *this;
}

Fraction Fraction::operator-(const Fraction& other) {
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator = denominator * other.denominator;
    Reduce();
    return *this;
}

Fraction Fraction::operator*(const Fraction& other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
    Reduce();
    return *this;
}

Fraction Fraction::operator/(const Fraction& other) {
    numerator *= other.denominator;
    denominator *= other.numerator;
    Reduce();
    return *this;
}

Fraction Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator+=(const Fraction& other) {
    *this = *this + other;
    return *this;
}

Fraction Fraction::operator-=(const Fraction& other) {
    *this = *this - other;
    return *this;
}

Fraction Fraction::operator*=(const Fraction& other) {
    *this = *this * other;
    return *this;
}

Fraction Fraction::operator/=(const Fraction& other) {
    *this = *this / other;
    return *this;
}

bool Fraction::operator==(const Fraction& other) {
    return numerator == other.numerator && denominator == other.denominator;
}

bool Fraction::operator!=(const Fraction& other) {
    return numerator != other.numerator || denominator != other.denominator;
}

bool Fraction::operator<(const Fraction& other) {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Fraction::operator>(const Fraction& other) {
    return numerator * other.denominator > other.numerator * denominator;
}

bool Fraction::operator<=(const Fraction& other) {
    return numerator * other.denominator <= other.numerator * denominator;
}

bool Fraction::operator>=(const Fraction& other) {
    return numerator * other.denominator >= other.numerator * denominator;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    if (fraction.denominator == 1) {
        out << fraction.numerator;
        return out;
    }
    if (fraction.numerator == 0) {
        out << 0;
        return out;
    }
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& fraction) {
    std::string value;
    in >> value;
    fraction = Fraction(value);
    return in;
}

