// Aleksandra Biskup 317424
// Zadanie 2 - Prosta na płaszczyźnie

#include "prosta.hpp"

int main() {
  Wektor v1(1, 3);
  Wektor v2(5, 6);
  cout << "Tworzenie wektorów: " << endl
       << "1: " << v1.dx << ", " << v1.dy << endl
       << "2: " << v2.dx << ", " << v2.dy << endl
       << "Kopiowanie wektorów: " << endl;
  Wektor v3(v2);
  cout << "3: " << v3.dx << ", " << v3.dy << endl << "Wektor domyślny: ";
  Wektor v4;
  cout << endl << "default: " << v4.dx << ", " << v4.dy << endl;

  Punkt p1(1, 1);
  Punkt p2(3, 2);

  cout << "Tworzenie punktów: " << endl
       << "1: " << p1.x << ", " << p1.y << endl
       << "2: " << p2.x << ", " << p2.y << endl
       << "Kopiowanie punktów: " << endl;

  Punkt p_copy(p2);

  cout << "3: " << p_copy.x << ", " << p_copy.y << endl << "Punkt domyślny: ";
  Punkt p_default;
  cout << endl << "default: " << p_default.x << ", " << p_default.y << endl;

  Prosta l1(2.0, 1.0, 5.0);
  cout << "Prosta:\n1: " << l1.geta() << "x + " << l1.getb() << "y + "
       << l1.getc();
  Prosta l2(p1, p2);
  cout << "\nProsta przechodząca przez punkty: " << l2.geta() << "x + "
       << l2.getb() << "y + " << l2.getc() << endl;

  cout << "Prostopadłość prostych: ";
  if (proste_prostopadle(l1, l2))
    cout << "tak\n";
  else
    cout << "nie\n";

  cout << "Równoległość prostych: ";
  if (proste_rownolegle(l1, l2))
    cout << "tak\n";
  else
    cout << "nie\n";
  cout << "Punkt na prostej: ";
  if (l1.punkt_na_prostej(p1))
    cout << "tak\n";
  else
    cout << "nie\n";
  cout << "Równoległość wektora do prostej 1: ";
  if (l1.wektor_rownolegly(v1))
    cout << "tak\n";
  else
    cout << "nie\n";
  cout << "Równoległość wektora do prostej 1: ";
  if (l1.wektor_prostopadly(v1))
    cout << "tak\n";
  else
    cout << "nie\n";

  return 0;
}