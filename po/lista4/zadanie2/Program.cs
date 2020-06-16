using System;

namespace zadanie2
{
  class Program
  {
    static void Main(string[] args)
    {
      PrimeCollection pc = new PrimeCollection();
      foreach (int p in pc){
        if (p>50) break;
        Console.WriteLine(p);
      }
    }
  }
}
