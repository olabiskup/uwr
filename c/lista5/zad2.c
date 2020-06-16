//Aleksandra Biskup 317424 zadanie 2 lista 5

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
            for(int i=1; i<n; i++)
            {
                if((p[i]+i)<=n)
                {
                    if((p[i]+i)==p[0])
                        return false;
                }
            }
            for(int i=2; i<n; i++)
            {
                if((p[i]-i)>=n)
                {
                    if((p[i]-i)==p[0])
                        return false;
                }
            }
        }
    }

    return true;
}


int main(int argc, int *argv[])
{
    int n, k;
    int p[n];

    n=argv[1];
    k=argv[2];
    for(int i=0; i<n; i++)
    {
        p[i]=i+1;
    }

    for(int i=0; i<k; i++)
    {
        if(next_perm(n,p))
        {
            for(int j=0; j<n; j++)
            {
                printf("%d", p[i]);
            }
        }
        printf("\n");

    }
    return 0;
}
