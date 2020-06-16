
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

namespace calculations {

class RationalException : public exception {};
class DivByZero : public RationalException {
  const char *what() const throw() { return "Nie można dzielić przez zero!"; }
};
class OutOfRange : public RationalException {
  const char *what() const throw() { return "Przekroczono zakres!"; }
};
class Rational {
private:
  int num, den;

public:
  int getN() const { return num; }
  int getD() const { return den; }

  Rational(int, int);
  Rational(int);
  Rational() = default;

  Rational(const Rational &) = default;
  Rational &operator=(const Rational &) = default;
  friend ostream &operator<<(ostream &wy, const Rational &x);

  Rational operator+(const Rational &);
  Rational operator-(const Rational &);
  Rational operator*(const Rational &);
  Rational operator/(const Rational &);

  Rational operator!();
  Rational operator-();

  operator double();
  explicit operator int();

  void reduce();
};
} // namespace calculations
