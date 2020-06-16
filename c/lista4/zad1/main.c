#include <stdio.h>
#include <stdlib.h>
#include "wymierne.h"

int main()
{
    Wymierna x,y, wynik;
    char c;
    x=wczytaj();
    wypisz(x);
    printf("\n");
    y=wczytaj();
    wypisz(y);
    printf("\n");

    do{
    c=getchar();
    }while(isspace(c));

    if(c=='+'){
    wynik=dod(x,y);
    wypisz(wynik);
    }
    if(c=='-'){
    wynik=odj(x,y);
    wypisz(wynik);
    }
    if(c=='*'){
    wynik=mno(x,y);
    wypisz(wynik);
    }
    if(c=='/'){
    wynik=dziel(x,y);
    wypisz(wynik);
    }
    return 0;
}
