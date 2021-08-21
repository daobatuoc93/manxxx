#ifndef FRAC_H
#define FRAC_H
#include "class_op.hpp"

class Fraction
{
private:
    /* data */
    int ps{};
    int ms{};

public:
    Fraction(int ps, int ms) : ps(ps), ms(ms)
    {
        gcd(ps,ms);
    }

    int gcd(int a, int b)
    {
        return (b == 0) ? std::abs(a) : gcd(b, a % b);
    }

    Fraction() = default;
    void print()
    {
        cout << ps << "/" << ms << endl;
    }
    friend Fraction operator*(int x, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, int x);
    friend Fraction operator/(const Fraction &f1, const Fraction &f2);
    friend istream &operator>>(istream &f1, Fraction &p);
    friend ostream &operator<<(ostream &f1, const Fraction &p);

    //comparation

    friend bool operator==(const Fraction &f1, const Fraction &f2);
    friend bool operator!=(const Fraction &f1, const Fraction &f2);
    friend bool operator>(const Fraction &f1, const Fraction &f2);
    friend bool operator<(const Fraction &f1, const Fraction &f2);
    friend bool operator<=(const Fraction &f1, const Fraction &f2);
    friend bool operator>=(const Fraction &f1, const Fraction &f2);

    ~Fraction() {}
};

#endif
