# Aleksandra Biskup 317424
# Lista 8 
# Zadanie 3

class Jawna
    def initialize(tekst)
        @tekst = tekst
    end

    def zaszyfruj(klucz)
        for i in 0...@tekst.length
            @tekst[i] = klucz[@tekst[i]]
        end
        Zaszyfrowane.new(@tekst)
    end

    def to_s
        @tekst
    end
end

class Zaszyfrowane
    def initialize(tekst)
        @tekst = tekst
    end

    def odszyfruj(klucz)
        for i in 0...@tekst.length
            @tekst[i] = klucz.invert[@tekst[i]]
        end
        Jawna.new(@tekst)
    end
    
    def to_s
        @tekst
    end
end

klucz = {
    'a' => 'b',
    'b' => 'r',
    'r' => 'y',
    'y' => 'u',
    'u' => 'a'
}

msg = Jawna.new("ruby")
puts "Tekst: " + msg.to_s
msg = msg.zaszyfruj(klucz)
puts "Zaszyfruj: " + msg.to_s
puts "Odszyfruj: " + msg.odszyfruj(klucz).to_s