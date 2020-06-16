using System;
using System.Collections;

namespace zadanie2
{
  public class PrimeCollection : IEnumerable
  {
    private PrimeStream stream = new PrimeStream();
    IEnumerator IEnumerable.GetEnumerator()
    {
      return (IEnumerator)new PrimeEnum(stream);
    }
  }
  public class PrimeEnum : IEnumerator
  {
    int a;
    public PrimeStream stream = new PrimeStream();
    public PrimeEnum(PrimeStream stream)
    {
      this.stream = stream;
    }
    public void Reset()
    {
      stream.reset();
    }
    public bool MoveNext()
    {
      if (stream.eos()) return false;
      a = stream.next();
      return true;
    }
    object IEnumerator.Current
    {
      get
      {
        return a;
      }
    }
  }
}