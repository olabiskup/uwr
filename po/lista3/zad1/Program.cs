using System;

using zadanie1;

class Program
{
  static void Main()
  {
    Lista<int> lista = new Lista<int>();
    lista.dodajGlowa(3);
    lista.dodajGlowa(2);
    lista.dodajGlowa(1);
    lista.dodajOgon(1);
    lista.dodajOgon(2);
    lista.dodajOgon(3);
    lista.wyswietl();
    System.Console.WriteLine("Usuwam pierwszy element");
    lista.usunGlowa();
    lista.wyswietl();
    System.Console.WriteLine("Usuwam ostatni element");
    lista.usunOgon();
    lista.wyswietl();
  }
}


