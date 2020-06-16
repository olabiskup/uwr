using System;

namespace zadanie4
{
  class Program
  {
    static void Main(string[] args)
    {
      var a = new Pierwsze();
      a.element(32);
      for (int i = 0; i < 32; i++)
      {
        Console.WriteLine(a.element(i));
      }
    }
  }
}
