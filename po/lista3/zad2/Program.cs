using System;

using zadanie2;

class Program
{
  static void Main(string[] args)
  {
    Slownik<int, string> slownik = new Slownik<int, string>();
    slownik.Dodaj(1, "a");
    slownik.Dodaj(2, "b");
    slownik.Dodaj(3, "c");
    slownik.Dodaj(4, "d");
    slownik.Dodaj(5, "e");
    Console.WriteLine(slownik.Szukaj(4));
    Console.WriteLine(slownik.Szukaj(3));
    slownik.Usun(5);
    Console.WriteLine(slownik.Szukaj(5));
    Console.WriteLine(slownik.Szukaj(4));
  }
}

