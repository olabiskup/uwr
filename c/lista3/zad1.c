//Aleksandra Biskup 317424 zadanie 1 lista 3
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool wczytaj(int n, char liczba[n])
{
    char c;
    int i=0;

    c=getchar();

    while(isspace(c)){
    c=getchar();
    }

    if(c=='-'||c=='+'){

        if(c=='-') liczba[i]='-';
        if (c=='+') liczba [i]='+';
        i++;
        c=getchar();
    }


    while(isdigit(c)){
        liczba[i]=c;
        c=getchar();
        i++;
    }

    liczba[i]='\0';
}

void konwertuj(const char liczba[], int nliczba[]){

    int j=2;
    if(liczba[0]=='-') nliczba[0]=1;
    else nliczba[0]=0;

    nliczba[1]=strlen(liczba);

    for(int i=strlen(liczba)-1; i>=0; i--){
    nliczba[j]=liczba[i]-'0';
    j++;
    }
}

void dodaj(l1[],l2[]){
    i=2;
    while(){
    if(l1[i]+l2[i]>9) {
        wynik[i]=l1[i]+l2[i];
        i++;
    }
    }

}


int main()
{
    char chtab[1000];
    int inttab[1000];

    wczytaj(1000, chtab);
    printf("%s", chtab);
    printf(" ");
    konwertuj(chtab, inttab);
    for(int i=0; i<(strlen(chtab)+2); i++){
    printf("%d", inttab[i]);
    }

    return 0;
}
