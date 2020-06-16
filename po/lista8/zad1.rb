# Aleksandra Biskup 317424
# Lista 8 
# Zadanie 1

class Fixnum
    def czynniki
        res = []
        1.upto(self) do |x|
            if self % x == 0 
                res.push(x)
            end
        end
        return res
    end

    def ack(y)
        if self == 0 
            return y + 1 
        elsif y == 0
            return(self - 1).ack(1)
        else return (self - 1).ack(self.ack(y-1))
        end
    end

    def doskonala
        rez = 0
        for i in self.czynniki do
             rez +=i 
        end
         rez - self == self
    end

    def slownie
        slownik = {1 => "jeden ", 2 => "dwa ", 3 => "trzy ", 4 => "cztery ", 5 =>"pięć",
             6 =>"sześć", 7 => "siedem", 8 => "osiem", 9 => "dziewięć", 0 => "zero"}
        rez = String.new

        for i in 0...self.to_s.length do
           rez += slownik[self.to_s[i].to_i] 
        end

        return rez
    end
end

$\ = "\n"
print 10.czynniki 
print 81.czynniki
print 2.ack(1)

print 6.doskonala
print 15.doskonala

print 216.slownie