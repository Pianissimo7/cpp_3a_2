#include "Fraction.hpp"

using namespace ariel;

Fraction::Fraction(int a, int b) {}
Fraction::Fraction(const Fraction &other) {
    this-> a = other.getNumerator();
    this->b = other.getDenominator();
}
int Fraction::getNumerator() const {
    return this->a;
}

int Fraction::getDenominator() const {
    return this->b;
}
Fraction::~Fraction() {}

// Arithmetic operators
Fraction Fraction::operator+(const Fraction& other) const {
    return *this;
};
Fraction Fraction::operator-(const Fraction& other) const {
    return *this;
};
Fraction Fraction::operator*(const Fraction& other) const {
    return *this;
}
Fraction Fraction::operator/(const Fraction& other) const {
    return *this;
}

// Arithmetic operators double and fraction        
Fraction Fraction::operator+(double d) const {
    return *this;
}
Fraction Fraction::operator-(double d) const {
    return *this;
}
Fraction Fraction::operator*(double d) const {
    return *this;
}
Fraction Fraction::operator/(double d) const {
    return *this;
}

// Comparison operators
bool Fraction::operator==(const Fraction& other) const {
    return false;
}
bool Fraction::operator<=(const Fraction& other) const {
    return false;
}
bool Fraction::operator>=(const Fraction& other) const {
    return false;
}
bool Fraction::operator<(const Fraction& other) const {
    return false;
}
bool Fraction::operator>(const Fraction& other) const {
    return false;
}

// Comparison operators for double and fraction
bool Fraction::operator==(double d) const {
    return false;
}
bool Fraction::operator!=(double d) const {
    return false;
}
bool Fraction::operator<(double d) const {
    return false;
}
bool Fraction::operator<=(double d) const {
    return false;
}
bool Fraction::operator>(double d) const {
    return false;
}
bool Fraction::operator>=(double d) const {
    return false;
}

// Input/output operators
std::ostream& ariel::operator<<(std::ostream& os, const Fraction& fraction) {
    return os;
}
std::istream& ariel::operator>>(std::istream& is, Fraction& fraction) {
    return is;
}

// double & fraction operators
double ariel::operator+(double d, const Fraction& other) {
    return d;
}
double ariel::operator-(double d, const Fraction& other) {
    return d;
}
double ariel::operator*(double d, const Fraction& other) {
    return d;
}
double ariel::operator/(double d, const Fraction& other) {
    return d;
}

// Increment/decrement operators
Fraction& Fraction::operator++() {
    return *this;
}
Fraction Fraction::operator++(int) {
    return *this;
}
Fraction& Fraction::operator--() {
    return *this;
}
Fraction Fraction::operator--(int) {
    return *this;
}
