using System;

namespace zadanie1
{
  public class Lista<T>
  {
    class Element
    {
      public T val;
      public Element next;
      public Element prev;

      public Element(T val)
      {
        this.prev = null;
        this.next = null;
        this.val = val;
      }
    }
    Element head;
    public Lista()
    {
      head = null;
    }
    public bool czyNiepusta()
    {
      if (head == null) return false;
      else return true;
    }

    public void wyswietl()
    {
      Element tmp = head;
      while (tmp != null)
      {
        Console.WriteLine(tmp.val);
        tmp = tmp.next;
      }

    }

    public void dodajGlowa(T value)
    {
      Element newElement = new Element(value);
      if (head == null)
      {
        head = newElement;
        return;
      }
      if (head.next == null)
      {
        newElement.prev = head;
        newElement.next = head;
        head.prev = newElement;
        head = newElement;
        return;
      }
      newElement.next = head;
      newElement.prev = head.prev;
      head.prev = newElement;
      head = newElement;
      return;
    }

    public T usunGlowa()
    {
      T res = head.val;
      if (head.next == null)
      {
        head = null;
        return res;
      }
      head.next.prev = head.prev;
      head = head.next;
      return res;

    }
    public void dodajOgon(T value)
    {
      Element newElement = new Element(value);
      if (head == null)
      {
        head = newElement;
        return;
      }
      if (head.next == null)
      {
        head.prev = newElement;
        head.next = newElement;
        newElement.prev = head;
        return;
      }
      head.prev.next = newElement;
      newElement.prev = head.prev;
      head.prev = newElement;
      return;
    }

    public T usunOgon()
    {
      T res;
      if (head.next == null)
      {
        res = head.val;
        head = null;
        return res;
      }
      res = head.prev.val;
      head.prev.prev.next = null;
      head.prev = head.prev.prev;
      return res;

    }
  }
}