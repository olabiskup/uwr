//Aleksandra Biskup 317424 zad 2 lista 2


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool wczytaj(int x, int y, bool tab[x+y][y+x])
{
    char c;
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            c=getchar();
            if(c=='\n') c=getchar();
            if (c=='X'||c=='x')
            {
                tab[i][j]=1;
            }
            else
            {
                tab[i][j]=0;
            }
        }
    }
}

bool wypisz(int x, int y, bool tab[x+y][y+x])
{
    for(int i=0; i<x; ++i)
    {
        for(int j=0; j<y; ++j)
        {
            if(tab[i][j])
                printf("X");
            else
                printf(" ");
        }
        printf("\n");
    }
}

bool obrot(int x, int y, bool tab[x+y][y+x], int pivot)
{
    bool tmptab[x+y][y+x];
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            tmptab[i][j]=tab[i][j];
        }
    }
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            tab[i][j]=0;
        }
    }

    if(pivot==3)  //270
    {

        for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {
                if(tmptab[i][j]) tab[y-1-j][i]=1;
            }
        }
    }
    if(pivot==2)  //180
    {
        for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {
                tab[i][j]=tmptab[x-i-1][y-1-j];
            }
        }
    }
    if(pivot==1) //90
    {
        for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {
                if(tmptab[i][j]) tab[j][x-i-1]=1;
            }
        }
    }
}

int main()
{

    int p, x, y, tmp;
    bool tab[1000][1000];
    //x i y to wymiary tablicy, p to parametr odpowiadajacy za obrot tablicy - nale¿y podaæ 1 dla 90 stopni, 2 dla 180 i 3 dla 270
    scanf("%d", &x);
    scanf("%d", &y);
    wczytaj(x,y,tab);
    wypisz(x,y,tab);
    scanf("%d", &p);
    obrot(x,y,tab,p);
    if(p==1||p==3){
        tmp=x;
        x=y;
        y=tmp;
    }
    wypisz(x,y,tab);

    return 0;
}


