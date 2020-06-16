//Aleksandra Biskup 317424 zadanie 1 lista 6
#include "kolejka.h"

bool pelna(kolejka k){
    if(k[POCZ]-1==k[KON]) return true;
    else if((k[POCZ]=k[START])&&k[KON]==k[FIN]-1) return true;
    else return false;
}

bool pusta(kolejka k){
    if(k[POCZ]==k[KON]) return true;
    else return false;
}

void init_kol(kolejka k, int n, double t[n]){
    k[0]=k[1]=k[2]=t;
    k[3]=t+n;
}

void oproznij(kolejka k){
    k[POCZ]=k[KON]=k[START];
}

bool dopiszk(kolejka k, double x){
    if (pelna(k)) return false;
    if(!(pelna(k))){
        *k[KON]=x;
        k[KON]++;
        if (k[KON]==k[FIN]) k[KON]=k[START];
        return true;
    }
}

bool dopiszp(kolejka k, double x){

    if (pelna(k)) return false;
    if(!(pelna(k))){
        k[POCZ]--;
        *k[POCZ]=x;
        if (k[POCZ]==k[START]) k[POCZ]=k[FIN];
        return true;
    }

}

double pobierzp(kolejka k){
    double x;
    if(!(pusta(k))){
        x=*k[POCZ];
        k[POCZ]++;
        if(k[POCZ]==k[FIN]) k[POCZ]=k[START];
        return x;
    }
    else return NAN;
}

double pobierzk(kolejka k){
    double x;
    if(!(pusta(k))){
        k[KON]--;
        if(k[KON]==k[START]) k[KON]=k[FIN];
        x=*k[KON];
        return x;
    }
    else return NAN;
}

void wyswietl(kolejka k){
    for(double *i=k[POCZ]; i<k[KON]; i++){
        if(i==k[FIN]) i=k[POCZ];
        printf("%lf ", *i);
    }
    printf("\n");
}
