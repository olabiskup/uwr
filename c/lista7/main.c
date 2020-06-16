//Aleksandra Biskup 317424 lista 7 zadanie 1
#include "lista.h"

int main(){
    char buf[200];
    int c;
    int dl;
    struct element *lista = pusta_lista();
    printf(" 1 - nowa lista\n 2 - dodaj na poczatek\n 3 - dodaj na koniec\n");
    printf(" 4 - podaj wartosc z poczatku\n 5 - usun i zwroc wartosc z poczatku\n 6 - sprawdz czy lista jest pusta\n 7 - podaj dlugosc listy\n 8 - wyjdz\n");
    for(;;){
        scanf("%d", &c);
        printf("\n");
       switch(c){
        case 1:
            lista=pusta_lista();
            break;
        case 2:
            scanf("%s", buf);
            dl=strlen(buf);
            char *k=(char *)malloc(dl+1);
            strcpy(k, buf);
            lista=pdopisz(lista, k);
            break;
        case 3:
            scanf("%s", buf);
            dl=strlen(buf);
            char *p=(char *)malloc(dl+1);
            strcpy(p, buf);
            lista=kdopisz(lista, p);
            break;
        case 4:
            printf("%c", *pwart(lista));
            break;
        case 5:
            printf("%c", *usun_zwroc(lista));
            break;
        case 6:
            if(pusta(lista)) printf("lista pusta");
            else printf("lista niepusta");
            break;
        case 7:
            printf("%d ", dl_listy(lista));
            break;
        case 8:
            return 0;
        default:
            printf("Bledny wybor!");
            break;
        }
    }
    return 0;
}

