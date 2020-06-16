// Aleksandra Biskup 317424
// Zadanie 4 - stos zaimplementowany na tablicy

#include "zad4.hpp"

int main() {
  int c, cap;
  cout << "Podaj pojemność stosu" << endl;
  cin >> cap;
  Stack *stack = new Stack(cap);
  Stack *liststack = new Stack({"gshg", "sfsf", "scs"});
  printStack(liststack);
  string s;
  cout << " 1. Dodaj element na wierzch stosu\n 2. Zdejmij element ze stosu\n"
          " 3. Zapytaj o ilość elementów stosu\n"
          " 4. Wypisz zawartość stosu\n 5. Zakończ program\n";
  for (;;) {
    cin >> c;
    switch (c) {
    case 1:
      cout << "\nPodaj element do włożenia na stos\n";
      cin >> s;
      stack->push(s);
      cout << endl;
      break;
    case 2:
      cout << "Zdjęto element " << stack->pop() << endl;
      break;
    case 3:
      cout << "Rozmiar stosu: " << stack->askSize() << endl;
      break;
    case 4:
      printStack(stack);
      break;
    case 5:
      delete stack;
      return 0;
    default:
      cout << "Wybierz opcję z menu";
    }
  }
}