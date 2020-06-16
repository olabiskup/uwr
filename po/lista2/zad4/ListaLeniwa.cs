using System;
using System.Collections.Generic;

namespace zadanie4
{
  public class ListaLeniwa
  {
    Random rnd = new Random();

    protected List<int> list = new List<int>();

    virtual protected int Fill()
    {
      return rnd.Next();
    }
    public int GetSize()
    {
      return list.Count;
    }

    public int element(int x)
    {
      if (x < 0) throw new InvalidOperationException("Indeks nie może być ujemny");
      while (x >= GetSize())
      {
        list.Add(Fill());
      }
      return list[x];
    }
  }
}