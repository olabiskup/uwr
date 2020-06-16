//Aleksandra Biskup 317424 zadanie 1 lista 5

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool next_perm(int n, int p[n])
{
    int tmp;
    int pom[n];

    if(n==1)
        return false;
    if(!(next_perm(n-1, p+1)))
    {
        if(p[0]>p[1])
            return false;
        else
        {
            for(int i=n-1; i>0; i--)
            {
                if(p[i]>p[0])
                {
                    tmp=p[i];
                    p[i]=p[0];
                    p[0]=tmp;
                    break;
                }
            }
            for(int i=0; i<n; i++)
            {
                pom[i]=p[i];
            }
            for(int i=1; i<n; i++)
            {
                p[i]=pom[n-i];
            }
        }
    }

    return true;
}


int main()
{
    int n;
    int p[n];

    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        p[i]=i+1;
    }

    do
    {
        for(int i=0; i<n; i++)
        {
            printf("%d ", p[i]);
        }
        printf("\n");

    }
    while(next_perm(n, p));

    return 0;
}
