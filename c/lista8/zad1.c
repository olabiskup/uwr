//Aleksandra Biskup 317424 lista 8 zadanie 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct dzialanie{
    bool czy_liczba;
    double liczba;
    char oper;
    struct dzialanie *lewy, *prawy;
}Dzialanie;

Dzialanie *tworz_lisc(double x){
    Dzialanie *lisc;
    if((lisc=(Dzialanie*)malloc(sizeof(Dzialanie)))==NULL) {
        printf("Nie przydzielono pamieci!");
        exit(1);
    }
    lisc->czy_liczba=true;
    lisc->liczba=x;
    return lisc;
}

Dzialanie *tworz_oper(char op, Dzialanie *lewy, Dzialanie *prawy){
    Dzialanie *operacja;
    if((operacja=(Dzialanie*)malloc(sizeof(Dzialanie)))==NULL){
        printf("Nie przydzielono pamieci!");
        exit(1);
    }
    operacja->czy_liczba=false;
    operacja->oper=op;
    operacja->lewy=lewy;
    operacja->prawy=prawy;
    return operacja;
}

Dzialanie *czytaj_onp(void){
    Dzialanie *stos[1000];
    int wierzcholek=0;
    double x;
    char op;
    do{
        if((scanf(" %c", &op))==1){
            if(isdigit(op)){
                ungetc(op, stdin);
                scanf("%lf", &x);
                stos[wierzcholek]=tworz_lisc(x);
                wierzcholek++;
            }
            else if(op!='='){
                wierzcholek--;
                stos[wierzcholek-1]=tworz_oper(op, stos[wierzcholek-1], stos[wierzcholek]);
            }
        }
    }while(op!='=');

    return stos[0];
}

void wypisz(Dzialanie *korzen){
    int prior_main, prior_lewy, prior_prawy;//priorytety operatorow 1 - mno¿enie lub dzielienie; 0 - dodawanie lub odejmowanie;

    if(korzen->czy_liczba){
        printf("%lf", korzen->liczba);
    }
    else{
        if(korzen->oper=='/'||korzen->oper=='*') prior_main=1;
        if(korzen->oper=='+'||korzen->oper=='-') prior_main=0;

        if(korzen->lewy->oper=='*'||korzen->lewy->oper=='/') prior_lewy=1;
        if(korzen->lewy->oper=='-'||korzen->lewy->oper=='+') prior_lewy=0;

        if (korzen->prawy->oper=='*'||korzen->prawy->oper=='/') prior_prawy=1;
        if (korzen->prawy->oper=='-'||korzen->prawy->oper=='+') prior_prawy=0;

        if(!(prior_main) && !(prior_prawy)){
            if(korzen->prawy->oper=='+'&&korzen->oper=='-'){
                wypisz(korzen->lewy);
                printf("%c", korzen->oper);
                printf("(");
                wypisz(korzen->prawy);
                printf(")");
            }
            else{
                wypisz(korzen->lewy);
                printf("%c", korzen->oper);
                wypisz(korzen->prawy);
            }
        }
        else if(prior_main && !(prior_lewy) && prior_prawy){
            printf("(");
            wypisz(korzen->lewy);
            printf(")");
            printf("%c", korzen->oper);
            wypisz (korzen->prawy);
        }
        else if(prior_main && prior_lewy && !(prior_prawy)){
            wypisz(korzen->lewy);
            printf("%c", korzen->oper);
            printf("(");
            wypisz (korzen->prawy);
            printf(")");
        }
        else if(prior_main && !(prior_lewy) && !(prior_prawy)){
            printf("(");
            wypisz(korzen->lewy);
            printf(")");
            printf("%c", korzen->oper);
            printf("(");
            wypisz (korzen->prawy);
            printf(")");
        }
        else if(prior_main && prior_prawy){
            if(korzen->prawy->oper=='*'&&korzen->oper=='/'){
                wypisz(korzen->lewy);
                printf("%c", korzen->oper);
                printf("(");
                wypisz(korzen->prawy);
                printf(")");
            }
            else{
                wypisz(korzen->lewy);
                printf("%c", korzen->oper);
                wypisz(korzen->prawy);
            }
        }
        else{
            wypisz(korzen->lewy);
            printf("%c", korzen->oper);
            wypisz(korzen->prawy);
        }
    }
}

int main(){
    Dzialanie *wynik=czytaj_onp();
    wypisz(wynik);

    return 0;
}
