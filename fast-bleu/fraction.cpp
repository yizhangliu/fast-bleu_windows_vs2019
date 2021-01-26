#include "pch.h"

#include "fraction.h"

long long Fraction::gcd(long long a, long long b)
{
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(long long n, long long d)
{
    // cout << "Fraction__1__" << "__" << n << "__" << d << "_scores!" << endl;
    if (d == 0)
    {
        // cout << "Fraction__2__" << "__" << n << "__" << d << "_scores!" << endl;
        cout << "Denominator may not be 0." << endl;
        exit(0);
    }    
    else if (n == 0)
    {
        // cout << "Fraction__3__" << "__" << n << "__" << d << "_scores!" << endl;
        numerator = 0;
        denominator = d;
    }
    else
    {
        // cout << "Fraction__4__" << "__" << n << "__" << d << "_scores!" << endl;
        int sign = 1;
        if (n < 0)
        {
            sign *= -1;
            n *= -1;
        }
        if (d < 0)
        {
            sign *= -1;
            d *= -1;
        }
        // cout << "Fraction__5__" << "__" << n << "__" << d << "_scores!" << endl;
        long long tmp = gcd(n, d);
        // cout << "Fraction__6__" << "__" << sign << "__" << tmp << "_scores!" << endl;
        numerator = n / tmp * sign;
        // cout << "Fraction__7__" << "__" << n << "__" << d << "_scores!" << endl;        
        denominator = d / tmp;
        // cout << "Fraction__8__" << "__" << n << "__" << d << "_scores!" << endl;
    }
}

Fraction::operator int() { return (numerator) / denominator; }
Fraction::operator float() { return ((float)numerator) / denominator; }
Fraction::operator double() { return ((double)numerator) / denominator; }

Fraction operator+(const Fraction &lhs, const Fraction &rhs)
{
    Fraction tmp(lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator,
                 lhs.denominator * rhs.denominator);
    return tmp;
}

Fraction operator+=(Fraction &lhs, const Fraction &rhs)
{
    Fraction tmp(lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator,
                 lhs.denominator * rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator-(const Fraction &lhs, const Fraction &rhs)
{
    Fraction tmp(lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator,
                 lhs.denominator * rhs.denominator);
    return tmp;
}

Fraction operator-=(Fraction &lhs, const Fraction &rhs)
{
    Fraction tmp(lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator,
                 lhs.denominator * rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(const Fraction &lhs, const Fraction &rhs)
{
    Fraction tmp(lhs.numerator * rhs.numerator,
                 lhs.denominator * rhs.denominator);
    return tmp;
}

Fraction operator*=(Fraction &lhs, const Fraction &rhs)
{
    Fraction tmp(lhs.numerator * rhs.numerator,
                 lhs.denominator * rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(int lhs, const Fraction &rhs)
{
    Fraction tmp(lhs * rhs.numerator, rhs.denominator);
    return tmp;
}

Fraction operator*(const Fraction &rhs, int lhs)
{
    Fraction tmp(lhs * rhs.numerator, rhs.denominator);
    return tmp;
}

Fraction operator/(const Fraction &lhs, const Fraction &rhs)
{
    Fraction tmp(lhs.numerator * rhs.denominator,
                 lhs.denominator * rhs.numerator);
    return tmp;
}

std::ostream &operator<<(std::ostream &strm, const Fraction &a)
{
    if (a.denominator == 1)
    {
        strm << a.numerator;
    }
    else
    {
        strm << a.numerator << "/" << a.denominator;
    }
    return strm;
}