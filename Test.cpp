#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace ariel;

TEST_CASE("constructor test") {
    SUBCASE("normal constructor") {
        CHECK_NOTHROW(Fraction(1, 2));
    }
    SUBCASE("copy constructor") {
        Fraction a = Fraction(5, 7);
        Fraction b = Fraction(a);
        CHECK(a.getNumerator() == 5);
        CHECK(a.getDenominator() == 7);
    }
    SUBCASE("constructor with 0 as the denominator") {
        CHECK_THROWS(Fraction(1, 0));   
        CHECK_THROWS(Fraction(0, 0));   
        CHECK_THROWS(Fraction(52, 0));   
    }
    SUBCASE("check constructor simplifies expression") {
        Fraction a = Fraction(2, 4);
        CHECK(a.getNumerator() == 1);
        CHECK(a.getDenominator() == 2);

        Fraction b = Fraction(9, 3);
        CHECK(b.getNumerator() == 3);
        CHECK(b.getDenominator() == 1);
    }
}
TEST_CASE("+") {
    SUBCASE("normal addition") {
        Fraction a1 = Fraction(2, 3);
        Fraction b1 = Fraction(5, 3);
        CHECK_NOTHROW(a1 + b1);
        Fraction c1 = a1 + b1;
        CHECK(c1.getNumerator() == 7);
        CHECK(c1.getDenominator() == 3);
        
        Fraction a2 = Fraction(2, 5);
        Fraction b2 = Fraction(6, 5);
        Fraction c2 = a2 + b2;
        CHECK(c2.getNumerator() == 8);
        CHECK(c2.getDenominator() == 5);
    }
    SUBCASE("addition should simplify if possible") {
        Fraction a1 = Fraction(2, 3);
        Fraction b1 = Fraction(4, 3);
        Fraction c1 = a1 + b1;
        CHECK(c1.getNumerator() == 2);
        CHECK(c1.getDenominator() == 1);
        
        Fraction a2 = Fraction(4, 6);
        Fraction b2 = Fraction(5, 6);
        Fraction c2 = a2 + b2;
        CHECK(c2.getNumerator() == 3);
        CHECK(c2.getDenominator() == 2);
    }
}
TEST_CASE("-") {
    SUBCASE("normal subtraction") {
        Fraction a1 = Fraction(6, 3);
        Fraction b1 = Fraction(2, 3);
        CHECK_NOTHROW(a1 - b1);
        Fraction c1 = a1 - b1;
        CHECK(c1.getNumerator() == 4);
        CHECK(c1.getDenominator() == 3);
        
        Fraction a2 = Fraction(6, 5);
        Fraction b2 = Fraction(2, 5);
        Fraction c2 = a2 - b2;
        CHECK(c2.getNumerator() == 4);
        CHECK(c2.getDenominator() == 5);
    }
    SUBCASE("subtraction should simplify if possible") {
        Fraction a1 = Fraction(8, 3);
        Fraction b1 = Fraction(2, 3);
        Fraction c1 = a1 - b1;
        CHECK(c1.getNumerator() == 2);
        CHECK(c1.getDenominator() == 1);
        
        Fraction a2 = Fraction(5, 6);
        Fraction b2 = Fraction(3, 6);
        Fraction c2 = a2 - b2;
        CHECK(c2.getNumerator() == 1);
        CHECK(c2.getDenominator() == 3);
    }
}
TEST_CASE("*") {
    SUBCASE("normal multiplication") {
        Fraction a1 = Fraction(7, 5);
        Fraction b1 = Fraction(2, 11);
        CHECK_NOTHROW(a1 * b1);
        Fraction c1 = a1 * b1;
        CHECK(c1.getNumerator() == 14);
        CHECK(c1.getDenominator() == 55);
        
        Fraction a2 = Fraction(17, 35);
        Fraction b2 = Fraction(2, 3);
        Fraction c2 = a2 * b2;
        CHECK(c2.getNumerator() == 34);
        CHECK(c2.getDenominator() == 105);
    }
    SUBCASE("multiplication should simplify if possible") {
        Fraction a1 = Fraction(8, 5);
        Fraction b1 = Fraction(5, 3);
        Fraction c1 = a1 * b1;
        CHECK(c1.getNumerator() == 8);
        CHECK(c1.getDenominator() == 3);
        
        Fraction a2 = Fraction(5, 10);
        Fraction b2 = Fraction(2, 5);
        Fraction c2 = a2 * b2;
        CHECK(c2.getNumerator() == 1);
        CHECK(c2.getDenominator() == 5);
    }
}
TEST_CASE("/") {
    SUBCASE("normal division") {
        Fraction a1 = Fraction(7, 5);
        Fraction b1 = Fraction(11, 2);
        CHECK_NOTHROW(a1 / b1);
        Fraction c1 = a1 / b1;
        CHECK(c1.getNumerator() == 14);
        CHECK(c1.getDenominator() == 55);
        
        Fraction a2 = Fraction(35, 17);
        Fraction b2 = Fraction(2, 3);
        Fraction c2 = a2 / b2;
        CHECK(c2.getNumerator() == 105);
        CHECK(c2.getDenominator() == 34);
    }
    SUBCASE("division should simplify if possible") {
        Fraction a1 = Fraction(8, 5);
        Fraction b1 = Fraction(3, 5);
        Fraction c1 = a1 / b1;
        CHECK(c1.getNumerator() == 8);
        CHECK(c1.getDenominator() == 3);
        
        Fraction a2 = Fraction(10, 5);
        Fraction b2 = Fraction(2, 5);
        Fraction c2 = a2 / b2;
        CHECK(c2.getNumerator() == 5);
        CHECK(c2.getDenominator() == 1);
    }
}
TEST_CASE("compatibility with double") {
    SUBCASE("double + fraction") {
        double d = 0.25;
        Fraction a = Fraction(2, 4);
        CHECK_NOTHROW(d + a);
        double b = d + a;
        CHECK(b == 0.75);
    }
    SUBCASE("fraction + double") {
        Fraction a = Fraction(10, 5);
        double d = 0.8;
        CHECK_NOTHROW(a + d);
        Fraction c = a + d;
        CHECK(c.getNumerator() == 14);
        CHECK(c.getDenominator() == 5);
    }
    SUBCASE("double - fraction") {
        double d = 0.75;
        Fraction a = Fraction(2, 4);
        CHECK_NOTHROW(d - a);
        double b = d - a;
        CHECK(b == 0.25);
    }
    SUBCASE("fraction - double") {
        Fraction a = Fraction(10, 5);
        double d = 0.8;
        CHECK_NOTHROW(a - d);
        Fraction c = a - d;
        CHECK(c.getNumerator() == 6);
        CHECK(c.getDenominator() == 5);
    }
    SUBCASE("double * fraction") {
        double d = 0.5;
        Fraction a = Fraction(2, 4);
        CHECK_NOTHROW(d * a);
        double b = d * a;
        CHECK(b == 0.25);
    }
    SUBCASE("fraction * double") {
        Fraction a = Fraction(10, 5);
        double d = 0.8;
        CHECK_NOTHROW(a * d);
        Fraction c = a * d;
        CHECK(c.getNumerator() == 8);
        CHECK(c.getDenominator() == 5);
    }
    SUBCASE("double / fraction") {
        double d = 0.75;
        Fraction a = Fraction(2, 4);
        CHECK_NOTHROW(d / a);
        double b = d / a;
        CHECK(d == 1.5);
    }
    SUBCASE("fraction / double") {
        Fraction a = Fraction(10, 5);
        double d = 0.8;
        CHECK_NOTHROW(a / d);
        Fraction c = a / d;
        CHECK(c.getNumerator() == 5);
        CHECK(c.getDenominator() == 2);
    }
}
TEST_CASE("++, -- prefix and postfix") {
    SUBCASE("++ postfix") {
        Fraction a = Fraction(1, 2);
        CHECK_NOTHROW(a++);
        a = Fraction(1, 2);
        Fraction b = a++;
        CHECK(b.getNumerator() == 1);
        CHECK(b.getDenominator() == 2);
        CHECK(a.getNumerator() == 3);
        CHECK(a.getDenominator() == 2);
    }
    SUBCASE("++ prefix") {
        Fraction a = Fraction(1, 2);
        CHECK_NOTHROW(++a);
        a = Fraction(1, 2);
        Fraction b = ++a;
        CHECK(b.getNumerator() == 3);
        CHECK(b.getDenominator() == 2);
        CHECK(a.getNumerator() == 3);
        CHECK(a.getDenominator() == 2);
    }
    SUBCASE("-- postfix") {
        Fraction a = Fraction(3, 2);
        CHECK_NOTHROW(a--);
        a = Fraction(3, 2);
        Fraction b = a--;
        CHECK(b.getNumerator() == 3);
        CHECK(b.getDenominator() == 2);
        CHECK(b.getNumerator() == 1);
        CHECK(b.getDenominator() == 2);
    }
    SUBCASE("-- prefix") {
        Fraction a = Fraction(3, 2);
        CHECK_NOTHROW(--a);
        a = Fraction(3, 2);
        Fraction b = --a;
        CHECK(b.getNumerator() == 1);
        CHECK(b.getDenominator() == 2);
        CHECK(b.getNumerator() == 1);
        CHECK(b.getDenominator() == 2);
    }
}
TEST_CASE("comparision operators") {
    SUBCASE("==") {
        Fraction a = Fraction(3, 2);
        Fraction b = Fraction(6, 4);
        CHECK_NOTHROW(bool temp = a == b);
        CHECK((a == b) == true);
        Fraction c = Fraction(4, 2);
        Fraction d = Fraction(7, 4);
        CHECK((c == d) == false);

        double e = 1.5;
        CHECK_NOTHROW(bool temp = a == e);
        CHECK_NOTHROW(bool temp = e == a);
        CHECK((a == e) == true);
        CHECK((e == a) == true);
        double f = 1.75;
        CHECK((a == f) == false);
        CHECK((f == a) == false);

    }
    SUBCASE("!=") {
        Fraction a = Fraction(3, 2);
        Fraction b = Fraction(6, 4);
        CHECK_NOTHROW(bool temp = a != b);
        CHECK((a != b) == false);
        Fraction c = Fraction(4, 2);
        Fraction d = Fraction(7, 4);
        CHECK((c != d) == true);

        double e = 1.5;
        CHECK_NOTHROW(bool temp = a != e);
        CHECK_NOTHROW(bool temp = e != a);
        CHECK((a != e) == false);
        CHECK((e != a) == false);
        double f = 1.75;
        CHECK((a != f) == true);
        CHECK((f != a) == true);
    }
    SUBCASE("<=") {
        Fraction a = Fraction(3, 2);
        Fraction b = Fraction(6, 4);
        CHECK_NOTHROW(bool temp = a <= b);
        CHECK((a <= b) == true);
        Fraction c = Fraction(4, 2);
        Fraction d = Fraction(7, 4);
        CHECK((c <= d) == false);
        CHECK((d <= c) == true);

        double e = 1.5;
        CHECK_NOTHROW(bool temp = a <= e);
        CHECK_NOTHROW(bool temp = e <= a);
        CHECK((a <= e) == true);
        CHECK((e <= a) == true);
        double f = 1.75;
        CHECK((a <= f) == true);
        CHECK((f <= a) == false);
    }
    SUBCASE(">=") {
        Fraction a = Fraction(3, 2);
        Fraction b = Fraction(6, 4);
        CHECK_NOTHROW(bool temp = a >= b);
        CHECK((a >= b) == true);
        Fraction c = Fraction(4, 2);
        Fraction d = Fraction(7, 4);
        CHECK((c >= d) == true);
        CHECK((d >= c) == false);

        double e = 1.5;
        CHECK_NOTHROW(bool temp = a >= e);
        CHECK_NOTHROW(bool temp = e >= a);
        CHECK((a >= e) == true);
        CHECK((e >= a) == true);
        double f = 1.75;
        CHECK((a >= f) == false);
        CHECK((f >= a) == true);
    }
    SUBCASE("<") {
        Fraction a = Fraction(3, 2);
        Fraction b = Fraction(6, 4);
        CHECK_NOTHROW(bool temp = a < b);
        CHECK((a < b) == false);
        Fraction c = Fraction(4, 2);
        Fraction d = Fraction(7, 4);
        CHECK((c < d) == false);
        CHECK((d < c) == true);

        double e = 1.5;
        CHECK_NOTHROW(bool temp = a < e);
        CHECK_NOTHROW(bool temp = e < a);
        CHECK((a < e) == false);
        CHECK((e < a) == false);
        double f = 1.75;
        CHECK((a < f) == true);
        CHECK((f < a) == false);
    }
    SUBCASE(">") {
        Fraction a = Fraction(3, 2);
        Fraction b = Fraction(6, 4);
        CHECK_NOTHROW(bool temp = a > b);
        CHECK((a > b) == false);
        Fraction c = Fraction(4, 2);
        Fraction d = Fraction(7, 4);
        CHECK((c > d) == true);
        CHECK((d > c) == false);

        double e = 1.5;
        CHECK_NOTHROW(bool temp = a > e);
        CHECK_NOTHROW(bool temp = e > a);
        CHECK((a > e) == false);
        CHECK((e > a) == false);
        double f = 1.75;
        CHECK((a > f) == false);
        CHECK((f > a) == true);
    }
}