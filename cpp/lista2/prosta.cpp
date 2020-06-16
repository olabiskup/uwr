// Aleksandra Biskup 317424
// Zadanie 2 - Prosta na płaszczyźnie

#include "prosta.hpp"

void normalizuj(double &a, double &b, double &c) {
  double m = 1 / (sqrt((a * a) + (b * b)));
  if (c < 0)
    m *= -1;
  a *= m;
  b *= m;
  c *= m;
}

Wektor::Wektor(const Wektor &v) : dx(v.dx), dy(v.dy) {}
Wektor::Wektor(const double x, const double y) : dx(x), dy(y) {}

Wektor skladaj(Wektor &v, Wektor &u) {
  Wektor res(v.dx + u.dx, v.dy + u.dy);
  return res;
}

Punkt::Punkt(double a, double b) : x(a), y(b) {}
Punkt::Punkt(Punkt &p) : x(p.x), y(p.y) {}
Punkt::Punkt(Punkt p, Wektor v) : x(p.x + v.dx), y(p.y + v.dy) {}

bool Prosta::wektor_rownolegly(Wektor &v) {
  if (a * v.dy == (-1) * b * v.dx)
    return true;
  return false;
}

bool Prosta::wektor_prostopadly(Wektor &v) {
  if (a * v.dx == b * v.dy)
    return true;
  return false;
}
bool Prosta::punkt_na_prostej(Punkt &p) { return (a * p.x + b * p.y + c == 0); }

Prosta::Prosta(double a_, double b_, double c_) {
  if (a_ == 0 && b_ == 0)
    throw invalid_argument("A i B nie mogą być równe 0!");

  a = a_;
  b = b_;
  c = c_;
  normalizuj(a, b, c);
}

Prosta::Prosta(const Punkt &p1, const Punkt &p2) {
  if (p1.x == p2.x && p1.y == p2.y)
    throw invalid_argument("Punkty są takie same.");
  a = p2.y - p1.y;
  b = p1.x - p2.x;
  c = p2.x * p1.y - p1.x * p2.y;
  normalizuj(a, b, c);
}

Prosta::Prosta(const Wektor &v) {
  a = v.dx;
  b = v.dy;
  c = sqrt(v.dx * v.dx + v.dy * v.dy);
  normalizuj(a, b, c);
}

bool proste_rownolegle(Prosta &l1, Prosta &l2) {
  if (l1.geta() * l2.getb() - l2.geta() * l1.getb() == 0)
    return true;
  else
    return false;
}

bool proste_prostopadle(Prosta &p1, Prosta &p2) {
  return p1.geta() * p2.geta() == (-1) * p1.getb() * p2.getb();
}

Punkt punkt_przeciecia(Prosta &p1, Prosta &p2) {
  if (proste_rownolegle(p1, p2))
    throw invalid_argument("Proste są równoległe!");
  double d = p1.geta() * p2.getb() - p2.getb() * p1.geta();
  double x = (p1.getb() * p2.getc() - p2.getb() * p1.getc()) / d;
  double y = (p1.geta() * p2.getc() - p2.geta() * p1.getc()) / d;
  return {x, y};
}