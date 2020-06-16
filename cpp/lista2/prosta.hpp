// Aleksandra Biskup 317424
// Zadanie 2 - Prosta na płaszczyźnie

#include <cmath>
#include <iostream>

using namespace std;

class Wektor {
public:
  const double dx = 0.0, dy = 0.0;
  Wektor() = default;
  Wektor(const double x, const double y);
  Wektor(const Wektor &v);

  Wektor &operator=(const Wektor &) = delete;
  Wektor &operator=(Wektor &) = delete;
};

class Punkt {
public:
  const double x = 0.0, y = 0.0;
  Punkt() = default;
  Punkt(double a, double b);
  Punkt(Punkt p, Wektor v);
  Punkt(Punkt &p);

  Punkt &operator=(const Punkt &) = delete;
  Punkt &operator=(Punkt &) = delete;
};

class Prosta {
private:
  double a, b, c;

public:
  double geta() { return a; }
  double getb() { return b; }
  double getc() { return c; }

  Prosta() = default;
  Prosta(const Punkt &p1, const Punkt &p2);
  Prosta(const Wektor &v);
  Prosta(double a_, double b_, double c_);
  bool wektor_prostopadly(Wektor &v);
  bool wektor_rownolegly(Wektor &v);
  bool punkt_na_prostej(Punkt &p);
};

Wektor skladaj(Wektor &v, Wektor &u);
Punkt punkt_przeciecia(Prosta &p1, Prosta &p2);
bool proste_prostopadle(Prosta &p1, Prosta &p2);
bool proste_rownolegle(Prosta &p1, Prosta &p2);
void normalizuj(double &a, double &b, double &c);