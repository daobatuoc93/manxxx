#include "class_op.hpp"
#include "Fraction.hpp"

Fraction operator*(int x, const Fraction &f2)
{
    return Fraction{x * f2.ms, f2.ms};
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    return Fraction{f1.ps * f2.ps, f1.ms * f2.ms};
}

Fraction operator*(const Fraction &f2, int x)
{
    return Fraction{x * f2.ps, f2.ms};
}

istream &operator>>(istream &f1, Fraction &p)
{
    f1 >> p.ps;
    f1.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    f1 >> p.ms;
    return f1;
}

ostream &operator<<(ostream &f1, const Fraction &p)
{
    f1 << p.ps << "/" << p.ms;
    return f1;
}

bool operator==(const Fraction &f1, const Fraction &f2)
{
    Fraction value = f1 / f2;
    return {value.ms == value.ps};
}

bool operator!=(const Fraction &f1, const Fraction &f2)
{
    return !(operator==(f1, f2));
}

bool operator>(const Fraction &f1, const Fraction &f2)
{
    Fraction f3 = f1 / f2;
    return {f3.ps > f3.ms};
}

bool operator>=(const Fraction &f1, const Fraction &f2)
{
    Fraction f3 = f1 / f2;
    return {f3.ps >= f3.ms};
}

bool operator<(const Fraction &f1, const Fraction &f2)
{
    return {!(operator>=(f1, f2))};
}

bool operator<=(const Fraction &f1, const Fraction &f2)
{
    return {!(operator>(f1, f2))};
}

Fraction operator/(const Fraction &f1, const Fraction &f2)
{
    return Fraction{f1.ps * f2.ms, f2.ps * f1.ms};
}
