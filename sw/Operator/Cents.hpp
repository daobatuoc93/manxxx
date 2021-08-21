#ifndef CENTS_H
#define CENTS_H
#include"class_op.hpp"

class Cents
{
private:
  int m_cents{};

public:
  Cents(int cents)
      : m_cents{cents}
  {
  }
  Cents operator+(int vl);
  Cents operator+(const Cents &c1);
  friend ostream &operator<<(ostream &c1, int vl);
  friend Cents operator+(const Cents &c1, int vl);
  friend Cents operator+(const Cents &c1, const Cents &c2);
  friend Cents operator+(const Cents &c1, int vl);

  Cents operator -();
  bool operator!();
  int getCents() const { return m_cents; }
};
// Need to explicitly provide prototype for operator+ so uses of operator+ in other files know this overload exists
//Cents operator+(const Cents& c1, const Cents& c2);
#endif
