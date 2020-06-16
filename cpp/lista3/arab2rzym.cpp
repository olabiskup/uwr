// Aleksandra Biskup 317424
// Zadanie 3 - Liczby w zapisie rzymskim

#include <exception>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string arab2rzym(int a) {
  const vector<pair<int, string>> rzym = {
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
      {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
      {5, "V"},    {4, "IV"},   {1, "I"}};

  int aux = 0;
  string wynik = "";

  for (unsigned int i = 0; i < rzym.size(); i++) {
    if (aux + rzym[i].first <= a) {
      aux += rzym[i].first;
      wynik += rzym[i].second;
      i--;
    }
  }

  return wynik;
}

int main(int argc, char *argv[]) {
  if (argc < 2)
    cout << "Podaj liczbę do konwersji.";
  int a;
  for (int i = 1; i < argc; i++) {
    try {
      a = stoi(argv[i]);
    } catch (...) {
      clog << "Niewłaściwy argument!\n";
    }
    if (a < 1 || a > 3999) {
      clog << "Liczba poza zakresem!\n";
      continue;
    }
    cout << arab2rzym(a) << endl;
  }
  return 0;
}