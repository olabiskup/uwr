using System;

namespace zadanie2
{
  public class Slownik<K, V>
  {
    int rozmiar;
    int ilosc;
    int k;
    K[] klucze;
    V[] wartosci;

    public Slownik()
    {
      rozmiar = 12;
      klucze = new K[rozmiar];
      wartosci = new V[rozmiar];
      k = 0;
      ilosc = 0;
    }

    public void Dodaj(K key, V value)
    {
      if (k >= 11)
      {
        Array.Resize(ref klucze, klucze.Length + rozmiar);
        Array.Resize(ref wartosci, wartosci.Length + rozmiar);
        k = -1;
      }

      klucze[ilosc] = key;
      wartosci[ilosc] = value;
      ilosc++;
      k++;
    }
    public void Usun(K klucz)
    {
      int indeks = Array.IndexOf(klucze, klucz);
      if (indeks == -1)
        return;

      V[] wartosci_nowe = new V[ilosc - 1];
      K[] klucze_nowe = new K[ilosc - 1];

      Array.Copy(klucze, 0, klucze_nowe, 0, indeks);
      Array.Copy(klucze, indeks + 1, klucze_nowe, indeks, ilosc - indeks - 1);
      Array.Copy(wartosci, 0, wartosci_nowe, 0, indeks);
      Array.Copy(wartosci, indeks + 1, wartosci_nowe, indeks, ilosc - indeks - 1);
      klucze = klucze_nowe;
      wartosci = wartosci_nowe;
      ilosc--;
    }
    public V Szukaj(K klucz)
    {
      for (int i = 0; i < ilosc; i++)
        if (klucze[i].Equals(klucz))
          return wartosci[i];
      return default(V);
    }
  }
}
