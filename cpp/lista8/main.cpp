// Aleksandra Biskup 317424
// Zadanie 8 - szablon listy jednokierunkowej

#include "list.hpp"

int main() {
  List<int> *test_list = new List<int>();
  int c, val;
  for (;;) {
    cout << "Lista: " << *test_list << endl
         << "1. Dodaj element na koniec\n2.Usuń element o zadanej "
            "wartości\n3.Sprawdź długość\n4. Podaj element na danej "
            "pozycji\n5. Wyjdź z programu\n";

    cin >> c;
    switch (c) {
    case 1:
      cout << "Podaj wartość do wstawienia";

      cin >> val;
      test_list->append(val);
      break;
    case 2:
      cout << "Podaj wartość do usunięcia";
      cin >> val;
      test_list->remove(val);
      break;
    case 3:
      cout << "Długość listy to: " << test_list->count() << endl;
      break;
    case 4:
      cout << "Podaj pozycję: ";
      cin >> val;
      cout << test_list->getdata(val);
      break;
    case 5:
      test_list->~List<int>();
      delete (test_list);
      return 0;
    }
  }
}