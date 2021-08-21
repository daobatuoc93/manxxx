#include "class_op.hpp"
#include"Fraction.hpp"
#include"Cents.hpp"
class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{x}, m_y{y}, m_z{z}
    {
    }

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }

    void print() const
    {
        std::cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ')';
    }
    friend ostream &operator<<(ostream &out, const Point &p);
    friend istream &operator>>(istream &in, Point &p);
};

ostream &operator<<(ostream &cout, const Point &p)
{
    cout << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ')';
}

istream &operator>>(istream &in, Point &p)
{
    in >> p.m_x;
    in >> p.m_y;
    in >> p.m_z;
}




int main()
{
    Fraction f1{3, 2};
    Fraction f2{5, 8};

    std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
    std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
    std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
    std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
    std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
    std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
    return 0;
}
