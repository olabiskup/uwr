//Aleksandra Biskup 317424 zadanie 2 lista 6
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void gen(int l, double sorttab[l])
{
    srand(time(0));

    for(int i=0; i<l; i++)
    {
        sorttab[i]=rand()%100;
    }
}

void selectionSort(int l, double tab[l])
{
    int i, j, min_idx;
    double tmp;

    for (i = 0; i < l-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < l; j++)
            if (tab[j] < tab[min_idx])
                min_idx = j;
        if(min_idx!=i)
        {
            tmp=tab[i];
            tab[i]=tab[min_idx];
            tab[min_idx]=tmp;
        }
    }
}


bool correct(int l, double tab[l], double sorttab[l])
{
    double testtab[l];

    for(int i=1; i<l; i++)
    {
        if(sorttab[i]<sorttab[i-1])
            return false;
    }

    for(int i=0; i<l; i++)
    {
        testtab[i]=sorttab[i];
    }

    for(int i=0; i<l; i++)
    {
        for(int j=0; j<l; j++)
        {
            if(tab[i]==testtab[j])
            {
                testtab[j]=-1;
                break;
            }
        }
    }

    for(int i=0; i<l; i++)
    {
        if(testtab[i]!=-1)
            return false;
    }

    return true;
}

int compare(const void *a, const void *b)
{
    double* arg1 = (double*)a;
    double* arg2 = (double*)b;
    if (*arg1 < *arg2)
        return -1;
    if (*arg1 > *arg2)
        return 1;
    return 0;
}


void timer(int n, int l, double tab[l], void (*fun)(int, double*))
{
    clock_t start, end;

    double timetab[n];
    double sorttab[l];

    double sum=0, mn, mx, av;

    for(int i=0; i<n; i++)
    {
        gen(l, tab);
        for(int i=0; i<l; i++)
        {
            sorttab[i]=tab[i];
        }
        start=clock();
        (*fun)(l, sorttab);
        end=clock();
        if(!(correct(l,tab,sorttab)))
        {
            printf("bledne sortowanie!");
            exit(0);
        }

        timetab[i]=((double) (end - start)) / CLOCKS_PER_SEC;
        sum+=timetab[i];
    }
    mn=timetab[0];
    mx=timetab[0];
    for(int i=0; i<n; i++)
    {
        if (timetab[i]>mx)
            mx=timetab[i];
        if (timetab[i]<mn)
            mn=timetab[i];
    }
    av=sum/n;

    printf("Sortowanie przez wybor:\n\nCzas minimalny: %lf\nCzas maksymalny: %lf\nCzas sredni: %lf\n", mn, mx, av);

    sum=0;

    for(int i=0; i<n; i++)
    {
        gen(l, tab);
        start=clock();
        qsort(tab, l, sizeof(int), compare);
        end=clock();
        timetab[i]=((double) (end - start)) / CLOCKS_PER_SEC;
        sum+=timetab[i];
    }

    mn=timetab[0];
    mx=timetab[0];

    for(int i=0; i<n; i++)
    {

        if (timetab[i]>mx)
            mx=timetab[i];
        if (timetab[i]<mn)
            mn=timetab[i];
    }
    av=sum/n;

    printf("\nSortowanie szybkie:\n\nCzas minimalny:%lf\nCzas maksymalny: %lf\nCzas sredni: %lf\n\n", mn, mx, av);

}

int main()
{
    double tab[50000];

    printf("Dla 5000 elementow ciagu: \n\n");
    timer(100, 5000, tab, &selectionSort);
    printf("Dla 10000 elementow ciagu: \n\n");
    timer(100, 10000, tab, &selectionSort);
    printf("Dla 50000 elementow ciagu: \n\n");
    timer(100, 50000, tab, &selectionSort);

    return 0;
}
