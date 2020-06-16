using System;
using System.Collections.Generic;

namespace zadanie4
{
  public class Pierwsze : ListaLeniwa
  {
    private int num = 2;
    bool IsPrime(int a)
    {
      if (a == 2) return true;
      if (a % 2 == 0) return false;
      for (int i = 3; i * i <= a; i += 2)
      {
        if (a % i == 0) return false;
      }
      return true;
    }

    protected override int Fill()
    {
      if (this.num == 2)
      {
        this.num = 3;
      }
      else do
        {
          this.num += 2;
        } while (!IsPrime(num));
      return num;
    }
  }
}
