//Aleksandra Biskup 317424 lista 7 zadanie 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct element{
    char *napis;
    struct element *nastepny;
};

struct element *pusta_lista(void);
bool pusta(struct element *koniec);
char *pwart(struct element *koniec);
char *usun_zwroc(struct element *koniec);
struct element *pdopisz(struct element *koniec, char *info);
struct element *kdopisz(struct element *koniec, char *info);
int dl_listy(struct element *koniec);
