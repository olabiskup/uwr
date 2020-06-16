//Aleksandra Biskup 317424 lista 7 zadanie 1
#include "lista.h"


struct element *pusta_lista(void){
    return NULL;
}

bool pusta(struct element *koniec){
    if (koniec==NULL) return true;
    else return false;
}

char *pwart(struct element *koniec){
    return ((koniec->nastepny)->napis);
}

char *usun_zwroc(struct element *koniec){
    struct element *poczatek=koniec->nastepny;
    if(pusta(koniec)) return 0;
    koniec->nastepny=poczatek->nastepny;
    free(koniec->nastepny);
    return (poczatek->napis);
}

struct element *pdopisz(struct element *koniec, char *info){
    struct element *p;
    if((p=(struct element*)malloc(sizeof(struct element)))==NULL){
        printf("nie przydzielono pamieci!");
        exit(1);
    }

    if(pusta(koniec)){
        p->napis=info;
        koniec =p;
        koniec -> nastepny = koniec;
    }
    else{
        p->napis=info;
        p->nastepny=koniec->nastepny;
        koniec->nastepny=p;
    }

    return (koniec);
}

struct element *kdopisz(struct element *koniec, char *info){
    struct element *p;
    if((p=(struct element*)malloc(sizeof(struct element)))==NULL){
        printf("nie przydzielono pamieci!");
        exit(1);
    }
    if(pusta(koniec)){
        p->napis=info;
        koniec=p;
        koniec->nastepny=koniec;
    }
    else{
        p->napis=info;
        p->nastepny=koniec->nastepny;
        koniec->nastepny=p;
        koniec=p;
    }
    return (koniec);
}
int dl_listy(struct element *koniec){
    struct element *tmp=koniec->nastepny;
    int dl=0;
    if(pusta(koniec)) return dl;
    while(tmp!=koniec){
        tmp=tmp->nastepny;
        dl++;
    }
    return dl;
}

