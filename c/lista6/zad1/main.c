//Aleksandra Biskup 317424 zadanie 1 lista 6
#include "kolejka.h"

int main()
{
    kolejka k;
    int n, c;
    double t[1000];
    double x, p;
    scanf("%d", &n);
    init_kol(k, n, t);

    for(;;){

    scanf("%d", &c);

        switch(c){
            case 1://dopisz na poczatek
                scanf("%lf", &x);
                if(!(dopiszp(k, x))) printf("kolejka pelna\n");
                wyswietl(k);
                break;
            case 2:
                scanf("%lf", &x);
                if(!(dopiszk(k, x))) printf("kolejka pelna\n");
                wyswietl(k);
                break;
            case 3:
                p=pobierzp(k);
                printf("%lf\n", p);
                wyswietl(k);
                break;
            case 4:
                p=pobierzk(k);
                printf("%lf\n", p);
                wyswietl(k);
                break;
            case 5://wyswietl
                wyswietl(k);
                break;
            case 6://wyjscie
                return 0;
        }
    }
    return 0;
}
