using System;

namespace zadanie1
{
  class RandomWordStream
  {
    RandomStream rs = new RandomStream();
    PrimeStream ps = new PrimeStream();
    public string next()
    {
      string word = "";
      int c;
      int size = ps.next();
      for (int i = 0; i < size; i++)
      {
        c = (rs.next() % 25 + 65);
        word += Convert.ToChar(c);
      }
      return word;
    }
  }
}