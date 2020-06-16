using System;

namespace zadanie1
{
  public class Program
  {
    public static void Main(string[] args)
    {
      var stream = new IntStream();
      var streamPrime = new PrimeStream();
      var streamRandom = new RandomStream();
      var rws = new RandomWordStream();
      System.Console.WriteLine("IntStream");
      for (int i = 0; i < 10; i++)
      {
        try { System.Console.WriteLine(stream.next()); }
        catch (Exception)
        {
          Console.WriteLine("Koniec strumienia");
        }
      }
      System.Console.WriteLine("PrimeStream");
      for (int i = 0; i < 10; i++)
      {
        try { System.Console.WriteLine(streamPrime.next()); }
        catch (Exception)
        {
          Console.WriteLine("Koniec strumienia");
        }
      }
      System.Console.WriteLine("RandomStream");
      for (int i = 0; i < 10; i++)
      {
        try { System.Console.WriteLine(streamRandom.next()); }
        catch (Exception)
        {
          Console.WriteLine("Koniec strumienia");
        }
      }
      System.Console.WriteLine("RandomWordStream");
      for (int i = 0; i < 10; i++)
      {
        try { System.Console.WriteLine(rws.next()); }
        catch (Exception)
        {
          Console.WriteLine("Koniec strumienia");
        }
      }
    }
  }

}