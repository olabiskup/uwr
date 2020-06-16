//Aleksandra Biskup 317424 lista 2 zadanie 2

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char tab[200], c;
    int j, m, n;
    int l=0, t=0;


    if (argc<=1){ printf("Brak argumentow\n"); return 1;}
    sscanf(argv[1], "%d", &m);
    sscanf(argv[2], "%d", &n);


    while((c=getchar())!=EOF){

        tab[0]=c;
        j=1;

        while(isspace((tab[j]=getchar()))==0){
            if(j>(n-m+1)){
                printf("za dlugie slowo!");
                return 0;
            }
            else j++;
        }
        l+=j;

        if(t==0){
            for (int i=1; i<m; i++){ printf(" ");}
            t=1;}


        if(j<n-m-l+1){
            for(int j1=0;j1<j;j1++) putchar(tab[j1]);
            printf(" ");
        }
        else{
            printf("\n");
            for (int i=1; i<m; i++){
            printf(" ");
            }
            l=j;
            for(int j1=0;j1<j;j1++) putchar(tab[j1]);
            printf(" ");
        }
    }

    return 0;
}
