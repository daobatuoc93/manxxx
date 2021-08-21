#include "Cents.hpp"

Cents Cents::operator+(int value)
{
  return Cents(m_cents + value);
}

Cents operator+(const Cents &c1, const Cents &c2)
{
  return Cents{c1.m_cents + c2.m_cents};
}

Cents operator+(const Cents &c1, int vl)
{
  return Cents{c1.m_cents + vl};
}

Cents Cents::operator-()
{
    return Cents{-m_cents}; // since return type is a Cents, this does an implicit conversion from int to Cents using the Cents(int) constructor
}

bool Cents::operator!() {
  return {m_cents == 0};
}