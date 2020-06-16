using System;

namespace zadanie1
{
  class RandomStream : IntStream
  {
    override public bool eos()
    {
      return false;
    }
    Random x = new Random();
    override public int next()
    {
      this.num = x.Next();
      return num;
    }
  }
}