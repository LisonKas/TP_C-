#pragma once
#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    Fraction& operator+=(Fraction const& f){
        numerator = numerator * f.denominator + f.numerator * denominator;
        denominator = denominator * f.denominator;
        return *this;
    }

    Fraction& operator-=(Fraction const& f){
        numerator = numerator * f.denominator - f.numerator * denominator;
        denominator = denominator * f.denominator;
        return *this;
    }

    Fraction& operator*=(Fraction const& f){
        numerator = numerator * f.numerator;
        denominator = denominator * f.denominator;
        return *this;
    }

    Fraction& operator/=(Fraction const& f){
        numerator = numerator * f.denominator;
        denominator = denominator * f.numerator;
        return *this;
    }

    //exo 6 ...
    float to_float() const;

    operator float() const;
};

std::ostream& operator<<(std::ostream& os, Fraction const& p);
Fraction operator+(Fraction f1, Fraction const& f2);
Fraction operator-(Fraction f1, Fraction const& f2);
Fraction operator*(Fraction f1, Fraction const& f2);
Fraction operator/(Fraction f1, Fraction const& f2);

bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);
bool operator<(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);