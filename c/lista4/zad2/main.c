//Aleksandra Biskup 317424 zadanie 2 lista 4
#include <stdio.h>
#include <stdlib.h>
#include "wymierne.h"
#include "wielomian.h"

int main()
{
    int st1, st2, st;
    char c;
    Wymierna wartosc, wx;
    Wielomian x1, x2, wynik;
    scanf("%d", st1);
    czytajw(st1, x1);
    piszw(st1,x1);
    printf("\n\n");
    scanf("%d", st2);
    czytajw(st2, x2);
    piszw(st2,x2);
    printf("\n\n");
    wx=wczytaj();
    wartosc=licz(st1,x1,wx);
    wypisz(wartosc);

    do{
    c=getchar();
    }while(isspace(c));

    if(c=='+'){
    wdod(st1, x1, st2, x2, wynik);
    if(st1<=st2) st=st1;
    else st=st2;
    piszw(st, wynik);
    }
    if(c=='-'){
    wodj(st1, x1, st2, x2, wynik);
    if(st1<=st2) st=st1;
    else st=st2;
    piszw(st, wynik);
    }
    return 0;
}
