#include <iostream>
#include <numeric>

class Rational {
   public:
    Rational(int numerator = 0, int denominator = 1) {
        int gcd = std::gcd(numerator, denominator);
        numerator_ = numerator / gcd;
        denominator_ = denominator / gcd;
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
    }

    int Numerator() const { return numerator_; }

    int Denominator() const { return denominator_; }

   private:
    int numerator_;
    int denominator_;
};

// Операторы сложения, вычитания, умножения и деления
Rational operator+(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
                    lhs.Denominator() * rhs.Denominator());
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
                    lhs.Denominator() * rhs.Denominator());
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

// Унарные плюс и минус
Rational operator+(const Rational& rational) { return rational; }

Rational operator-(const Rational& rational) {
    return Rational(-rational.Numerator(), rational.Denominator());
}

// Операторы +=, -=, *= и /=
Rational& operator+=(Rational& lhs, const Rational& rhs) {
    lhs = lhs + rhs;
    return lhs;
}

Rational& operator-=(Rational& lhs, const Rational& rhs) {
    lhs = lhs - rhs;
    return lhs;
}

Rational& operator*=(Rational& lhs, const Rational& rhs) {
    lhs = lhs * rhs;
    return lhs;
}

Rational& operator/=(Rational& lhs, const Rational& rhs) {
    lhs = lhs / rhs;
    return lhs;
}

// Операторы == и !=
bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

bool operator!=(const Rational& lhs, const Rational& rhs) { return !(lhs == rhs); }