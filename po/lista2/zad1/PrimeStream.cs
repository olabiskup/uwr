using System;

namespace zadanie1
{
  class PrimeStream : IntStream
  {
    new int num = 2;
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
    override public int next()
    {
      if (this.num == 2)
      {
        this.num = 3;
      }
      else do
        {
          if (eos()) throw new Exception("Koniec strumienia.");
          this.num += 2;
        } while (!IsPrime(num));
      return num;
    }
  }
}