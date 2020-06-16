#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wymierne.h"
#include "wielomian.h"

void czytajw(int st, Wielomian x){
    Wymierna a;
    for(int i=0; i<=st; i++){
        a=wczytaj();
        x[i]=a;
    }
}

void piszw(int st, Wielomian x){
    Wymierna a;

    for(int i=st; i>0; i++){
        a=x[i];
        wypisz(a);
        printf("x^%d ", i);
    }
    a=x[0];
    wypisz(a);
}

Wymierna licz(int st, Wielomian x, Wymierna wx){
    Wymierna wartosc=x[0];
    for(int i=1; i<=st; i++){
        wartosc+=x[i]*pow(wx,i);
    }
    return wartosc;
}

void wdod(int st1, Wielomian x1, int st2, Wielomian x2, Wielomian wynik){
    int st;
    if(st1<=st2) st=st1;
    else st=st2;

    for(int i=0; i<=st; i++){
        wynik[i]=dod(x1[i], x2[i]);
    }
    if(st1>st2){
        for(int i=st+1; i<=st1; i++){
            wynik[i]=x1[i];
        }
    }

    if(st2>st1){
        for(int i=st+1; i<=st2; i++){
            wynik[i]=x2[i];
        }
    }
}

void wodj(int st1, Wielomian x1, int st2, Wielomian x2, Wielomian wynik){
    int st;
    if(st1<=st2) st=st1;
    else st=st2;

    for(int i=0; i<=st; i++){
        wynik[i]=odj(x1[i], x2[i]);
    }
    if(st1>st2){
        for(int i=st+1; i<=st1; i++){
            wynik[i]=x1[i];
        }
    }

    if(st2>st1){
        for(int i=st+1; i<=st2; i++){
            wynik[i]=x2[i];
        }
    }
}



