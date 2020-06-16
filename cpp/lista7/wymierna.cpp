#include "wymierna.hpp"

int gcd(int a, int b) {
  if (a == 0)
    return b;
  if (b == 0)
    return a;
  while (a != b) {
    if (a > b)
      a -= b;
    else
      b -= a;
  }
  return a;
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }
namespace calculations {
Rational::Rational(int _num, int _den) {
  if (_den == 0) {
    throw DivByZero();
  }
  num = _num;
  den = _den;
  reduce();
}

Rational::Rational(int x) : Rational(x, 1) {}

void Rational::reduce() {
  int Tnum = this->num;
  int Tden = this->den;
  int Tgcd = gcd(Tnum, Tden);
  Tnum = Tnum / Tgcd;
  Tden = Tden / Tgcd;

  if (Tden < 0) {
    Tnum *= -1;
    Tden *= -1;
  }

  this->num = Tnum;
  this->den = Tden;
}

Rational Rational::operator+(const Rational &q) {
  long long int Tden = lcm(this->den, q.getD());

  long long int Tnum =
      this->num * (Tden / this->den) + q.getN() * (Tden / q.getD());

  if (Tnum > INT_MAX || Tnum < INT_MIN || Tden > INT_MAX || Tden < INT_MIN)
    throw OutOfRange();
  Rational res(Tnum, Tden);

  return res;
}

Rational Rational::operator-(const Rational &q) {
  long long int Tden = lcm(this->den, q.getD());
  long long int Tnum =
      this->num * (Tden / this->den) - q.getN() * (Tden / q.getD());
  if (Tnum > INT_MAX || Tnum < INT_MIN || Tden > INT_MAX || Tden < INT_MIN)
    throw OutOfRange();
  Rational res(Tnum, Tden);
  return res;
}

Rational Rational::operator*(const Rational &q) {
  long long int Tnum = this->num * q.getN();
  long long int Tden = this->den * q.getD();

  if (Tnum > INT_MAX || Tnum < INT_MIN || Tden > INT_MAX || Tden < INT_MIN)
    throw OutOfRange();
  Rational res(Tnum, Tden);
  return res;
}

Rational Rational::operator/(const Rational &q) {
  long long int Tnum = this->num * q.getD();
  long long int Tden = this->den * q.getN();

  if (Tnum > INT_MAX || Tnum < INT_MIN || Tden > INT_MAX || Tden < INT_MIN)
    throw OutOfRange();
  Rational res(Tnum, Tden);
  return res;
}

Rational Rational::operator-() {
  this->num = -this->num;
  return *this;
}

Rational Rational::operator!() {
  if (num == 0)
    throw DivByZero();
  if (this->num < 0) {
    int tmp = -this->num;
    this->num = -this->den;
    this->den = tmp;
  } else {
    int tmp = this->num;
    this->num = this->den;
    this->den = tmp;
  }
  return *this;
}

Rational::operator double() { return (double)this->num / this->den; }

Rational::operator int() { return this->num / this->den; }

std::ostream &operator<<(std::ostream &output,
                         const calculations::Rational &x) {
  std::vector<int> remainders;
  std::vector<int> results;

  unsigned int i, j;
  int remainder;

  remainder = x.getN() % x.getD();
  if (remainder == 0) {
    output << x.getN() / x.getD();
    return output;
  }

  if (remainder < 0)
    remainder *= (-1);

  remainders.push_back(remainder);

  output << x.getN() / x.getD();

  while (true) {
    results.push_back(remainder * 10 / x.getD());
    remainder = remainder * 10 % x.getD();

    if (remainder == 0) {
      output << ".";
      for (i = 0; i < results.size(); i++)
        output << results[i];
      return output;
    }

    for (j = 0; j < remainders.size(); j++) {
      if (remainder == remainders[j]) {
        output << ".";
        for (i = 0; i < j; i++)
          output << results[i];

        output << "(";
        for (i = j; i < results.size(); i++)
          output << results[i];
        output << ")";

        return output;
      }
    }
    remainders.push_back(remainder);
  }
}
} // namespace calculations