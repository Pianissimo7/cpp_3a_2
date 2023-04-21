#pragma once
#include <iostream>

namespace ariel {

    class Fraction {
        public:
            Fraction(int a, int b);
            Fraction(const Fraction &other);
            int getNumerator() const;
            int getDenominator() const;
            ~Fraction();
            
            // Arithmetic operators
            Fraction operator+(const Fraction& other) const;
            Fraction operator-(const Fraction& other) const;
            Fraction operator*(const Fraction& other) const;
            Fraction operator/(const Fraction& other) const;

            // Arithmetic operators double and fraction        
            Fraction operator+(double d) const;
            Fraction operator-(double d) const;
            Fraction operator*(double d) const;
            Fraction operator/(double d) const;

            // Comparison operators
            bool operator==(const Fraction& other) const;
            bool operator!=(const Fraction& other) const;
            bool operator<=(const Fraction& other) const;
            bool operator>=(const Fraction& other) const;
            bool operator<(const Fraction& other) const;
            bool operator>(const Fraction& other) const;

            // Comparison operators for double and fraction
            bool operator==(double d) const;
            bool operator!=(double d) const;
            bool operator<(double d) const;
            bool operator<=(double d) const;
            bool operator>(double d) const;
            bool operator>=(double d) const;

            // Input/output operators
            friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
            friend std::istream& operator>>(std::istream& is, Fraction& fraction);
            
            friend double operator+(double d, const Fraction& other);
            friend double operator-(double d, const Fraction& other);
            friend double operator*(double d, const Fraction& other);
            friend double operator/(double d, const Fraction& other);

            // Increment/decrement operators
            Fraction& operator++(); // prefix increment
            Fraction operator++(int); // postfix increment
            Fraction& operator--(); // prefix decrement
            Fraction operator--(int); // postfix decrement

        private:
            int a;
            int b;
    };
    double operator+(double d, const Fraction& frac);
    double operator-(double d, const Fraction& frac);
    double operator*(double d, const Fraction& frac);
    double operator/(double d, const Fraction& frac);

    bool operator==(double d, const Fraction& frac);
    bool operator!=(double d, const Fraction& frac);
    bool operator<(double d, const Fraction& frac);
    bool operator<=(double d, const Fraction& frac);
    bool operator>(double d, const Fraction& frac);
    bool operator>=(double d, const Fraction& frac);
}