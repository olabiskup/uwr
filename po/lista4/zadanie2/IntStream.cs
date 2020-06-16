using System;

namespace zadanie2
{
  public class IntStream
  {
    protected int num = 0;
    virtual public bool eos()
    {
      if (num == int.MaxValue) return true;
      else return false;
    }
    virtual public int next()
    {
      if (!eos())
      {
        this.num++;
        return num - 1;
      }
      else
      {
        throw new Exception("Koniec strumienia");
      }
    }
    virtual public void reset()
    {
      this.num = 0;
    }
  }
}

