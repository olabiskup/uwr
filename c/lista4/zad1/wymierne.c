#include "wymierne.h"
#include <stdio.h>

int nwd(int a, int b){
    if(a<0) a=-a;
    if(b<0) b=-b;

    while(a!=b){
        if(a<b) b-=a;
        else a-=b;
    }
    return a;
}
int nww(int a, int b){
    int wynik;
    wynik=a*b/nwd(a,b);
    return wynik;
}

Wymierna konstruujW(int n, int m){
    if(m<0){
        n=-n;
        m=-m;
    }
    int d=nwd(n,m);
    n=n/d;
    m=m/d;
    Wymierna x=n;
    x<<=32;
    x|=m;
    return x;
}

Wymierna wczytaj(){
    Wymierna x;
    int n, m;
    scanf ("%d/%d", &n,&m);
    x=konstruujW(n,m);
    return x;
}

int mianownik(Wymierna x){
    long long int m;
    m=x;
    m<<=32;
    m>>=32;
    return m;
}

int licznik(Wymierna x){
    long long int n;
    n=x;
    n>>=32;
    return n;
}

Wymierna wypisz(Wymierna x){
    int n,m;
    n=licznik(x);
    m=mianownik(x);
    printf("%d/%d",n,m);
}

Wymierna dod(Wymierna n, Wymierna m){
    int a,b,c,d,x,y;
    Wymierna wynik;
    a=licznik(n);
    b=mianownik(n);
    c=licznik(m);
    d=mianownik(m);
    y=nww(b,d);
    a=a*(y/b);
    c=c*(y/d);
    x=a+c;
    wynik=konstruujW(x,y);
    return wynik;
}

Wymierna odj(Wymierna n, Wymierna m){
    int a,b,c,d,x,y;
    Wymierna wynik;
    a=licznik(n);
    b=mianownik(n);
    c=licznik(m);
    d=mianownik(m);
    y=nww(b,d);
    a=a*(y/b);
    c=c*(y/d);
    x=a-c;

    wynik=konstruujW(x,y);
    return wynik;
}

Wymierna mno(Wymierna n, Wymierna m){
    int a,b,c,d, x,y;
    Wymierna wynik;
    a=licznik(n);
    b=mianownik(n);
    c=licznik(m);
    d=mianownik(m);

    x=a*c;
    y=b*d;
    wynik=konstruujW(x,y);
    return wynik;
}

Wymierna dziel(Wymierna n, Wymierna m){
    int a,b,c,d, x,y;
    Wymierna wynik;
    a=licznik(n);
    b=mianownik(n);
    c=licznik(m);
    d=mianownik(m);

    x=a*d;
    y=b*c;

    wynik=konstruujW(x,y);
    return wynik;

}






