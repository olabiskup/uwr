//Aleksandra Biskup 317424 lista 1 zadanie 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    const long double y= 0.577215664901532860L;
    long double n=27, a=-log(n), b=1.0, u=-log(n), v=1.0;
    for(double k=1; k<100; k++)
    {
        b=(b*n*n)/(k*k);
        a=1.0/k*((a*n*n)/k+b);
        u=u+a;
        v=v+b;
    }
    printf("%.18Lf %Lg\n", u/v, y-u/v);
    return 0;
}
