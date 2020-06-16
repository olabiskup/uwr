//Aleksandra Biskup 317424 zadanie 1 lista 6
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define POCZ 1
#define KON 2
#define FIN 3
#define START 0

typedef double *kolejka[4];

bool pelna(kolejka k);
bool pusta(kolejka k);
void init_kol(kolejka k, int n, double t[n]);
void oproznij(kolejka k);
bool dopiszk(kolejka k, double x);
bool dopiszp(kolejka k, double x);
double pobierzp(kolejka k);
double pobierzk(kolejka k);
