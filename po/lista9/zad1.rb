#Aleksandra Biskup 317424
class Funkcja
  def initialize(&fun)
    @fun = fun
  end

  def value(x)
    @fun.call(x)
  end

  def zerowe (a, b, e)
    while(b-a>e)
      mid = (a+b)/2
        if(@fun.call(mid) == 0) then return mid
        elsif(@fun.call(a)*@fun.call(mid)<0)
          b = mid
        else a = mid
        end
    end
    return (a+b)/2
  end

  def pole(a,b)
    res = 0;
    t = 1000
    x = (b-a)*1.0/t
    pos = a
    for i in 0... t
      res += x * @fun.call(pos)
      pos += x
    end
    return res
  end

  def poch(x)
    return (@fun.call(x+0.00001)-@fun.call(x))/0.00001
  end

end

test1 = Funkcja.new{|x| x}

$\ = "\n"
print test1.poch(2)
print test1.pole(0, 2)
print test1.value(3)
print test1.zerowe(-5,5,0.01)
